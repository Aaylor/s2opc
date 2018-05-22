/*
 *  Copyright (C) 2018 Systerel and others.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "loader.h"

#include <assert.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <string.h>

#include <expat.h>
#include <opcua_identifiers.h>
#include <sopc_dict.h>
#include <sopc_encoder.h>
#include <sopc_hash.h>

#ifdef UANODESET_LOADER_LOG
#define LOG(str) fprintf(stderr, "UANODESET_LOADER: %s:%d: %s\n", __FILE__, __LINE__, (str))
#define LOGF(format, ...) fprintf(stderr, "UANODESET_LOADER: %s:%d: " format "\n", __FILE__, __LINE__, __VA_ARGS__)
#else
#define LOG(str)
#define LOGF(format, ...)
#endif

#define LOG_MEMORY_ALLOCATION_FAILURE LOG("Memory allocation failure")

typedef enum {
    PARSE_START,            // Beginning of file
    PARSE_NODESET,          // In a UANodeSet
    PARSE_ALIASES,          // In an Aliases tag
    PARSE_ALIAS,            // ... in its Alias
    PARSE_NODE,             // In a UANode subtype tag
    PARSE_NODE_DISPLAYNAME, // ... in its DisplayName
    PARSE_NODE_DESCRIPTION, // ... in its Description
    PARSE_NODE_REFERENCES,  // ... in its References
    PARSE_NODE_REFERENCE,   // ... in its References/Reference
    PARSE_NODE_VALUE,       // In the Value tag of a UAVariable/UAVariableType tag
} parse_state_t;

#define SKIP_TAG_LEN 256

struct parse_context_t
{
    XML_Parser parser;
    SOPC_AddressSpace_Description* desc;
    parse_state_t state;
    char skip_tag[SKIP_TAG_LEN]; // If set, start_tag events are ignored until this tag is closed

    // 0 terminated buffer for the char data handler (a single piece of char
    // data in the XML can be broken across many callbacks).
    char* char_data_buffer;

    // strlen of the text in char_data_buffer
    size_t char_data_len;

    // allocated size of char_data_buffer, at least char_data_len + 1 (for the
    // NULL terminator).
    size_t char_data_cap;

    SOPC_Dict* aliases;
    char* current_alias_alias;
    SOPC_BuiltinId current_value_type;
    SOPC_AddressSpace_Description_Item item;
};

#define NS_SEPARATOR "|"
#define UA_NODESET_NS "http://opcfoundation.org/UA/2011/03/UANodeSet.xsd"
#define UA_TYPES_NS "http://opcfoundation.org/UA/2008/02/Types.xsd"
#define NS(ns, tag) ns NS_SEPARATOR tag

static bool is_whitespace_char(char c)
{
    switch (c)
    {
    case ' ':
    case '\t':
    case '\n':
        return true;
    default:
        return false;
    }
}

static const char* strip_whitespace(char* s, size_t len)
{
    char* end = s + len - 1;
    for (; ((*s) != '\0') && is_whitespace_char(*s); ++s)
    {
    }
    for (; (end >= s) && is_whitespace_char(*end); --end)
    {
    }
    *(end + 1) = '\0';
    return s;
}

static bool ctx_char_data_append(struct parse_context_t* ctx, const char* data, size_t len)
{
    size_t required_cap = ctx->char_data_len + len + 1;

    if (required_cap > ctx->char_data_cap)
    {
        size_t cap = 2 * ctx->char_data_cap;

        while (cap < required_cap)
        {
            cap = 2 * cap;
        }

        char* data = realloc(ctx->char_data_buffer, cap * sizeof(char));

        if (data == NULL)
        {
            LOG_MEMORY_ALLOCATION_FAILURE;
            return false;
        }

        ctx->char_data_buffer = data;
        ctx->char_data_cap = cap;
    }

    memcpy(ctx->char_data_buffer + ctx->char_data_len, data, len);
    ctx->char_data_len += len;
    ctx->char_data_buffer[ctx->char_data_len] = '\0';

    return true;
}

static void ctx_char_data_reset(struct parse_context_t* ctx)
{
    ctx->char_data_buffer[0] = '\0';
    ctx->char_data_len = 0;
}

static const char* ctx_char_data_stripped(struct parse_context_t* ctx)
{
    return strip_whitespace(ctx->char_data_buffer, ctx->char_data_len);
}

static SOPC_StatusCode parse(XML_Parser parser, FILE* fd)
{
    char buf[65365];

    while (!feof(fd))
    {
        size_t r = fread(buf, sizeof(char), sizeof(buf) / sizeof(char), fd);

        if ((r == 0) && (ferror(fd) != 0))
        {
            LOGF("Error while reading input file: %s", strerror(errno));
            return SOPC_STATUS_NOK;
        }

        if (XML_Parse(parser, buf, (int) r, 0) != XML_STATUS_OK)
        {
            // The error here comes from one of the callbacks, that log an error
            // themselves.
            return SOPC_STATUS_NOK;
        }
    }

    // Tell the parser that we are at the end of the file
    if (XML_Parse(parser, "", 0, 1) != XML_STATUS_OK)
    {
        return SOPC_STATUS_NOK;
    }

    return SOPC_STATUS_OK;
}

// strdup is POSIX only...
static char* dup_c_string(const char* s)
{
    size_t len = strlen(s);
    char* res = calloc(1 + len, sizeof(char));

    if (res == NULL)
    {
        return NULL;
    }

    memcpy(res, s, len * sizeof(char));
    return res;
}

static bool parse_signed_value(const char* data, size_t len, uint8_t width, void* dest)
{
    char buf[21];

    if (len >= (sizeof(buf) / sizeof(char) - 1))
    {
        return false;
    }

    memcpy(buf, data, len);
    buf[len] = '\0';

    char* endptr;
    int64_t val = strtol(buf, &endptr, 10);

    if (endptr != (buf + len))
    {
        return false;
    }

    if (width == 8 && val >= INT8_MIN && val <= INT8_MAX)
    {
        *((int8_t*) dest) = (int8_t) val;
        return true;
    }
    else if (width == 16 && val >= INT16_MIN && val <= INT16_MAX)
    {
        *((int16_t*) dest) = (int16_t) val;
        return true;
    }
    else if (width == 32 && val >= INT32_MIN && val <= INT32_MAX)
    {
        *((int32_t*) dest) = (int32_t) val;
        return true;
    }
    else if (width == 64)
    {
        *((int64_t*) dest) = (int64_t) val;
        return true;
    }
    else
    {
        // Invalid width and/or out of bounds value
        return false;
    }
}

static bool parse_unsigned_value(const char* data, size_t len, uint8_t width, void* dest)
{
    char buf[21];

    if (len >= (sizeof(buf) / sizeof(char) - 1))
    {
        return false;
    }

    memcpy(buf, data, len);
    buf[len] = '\0';

    char* endptr;
    uint64_t val = strtoul(buf, &endptr, 10);

    if (endptr != (buf + len))
    {
        return false;
    }

    if (width == 8 && val <= UINT8_MAX)
    {
        *((uint8_t*) dest) = (uint8_t) val;
        return true;
    }
    else if (width == 16 && val <= UINT16_MAX)
    {
        *((uint16_t*) dest) = (uint16_t) val;
        return true;
    }
    else if (width == 32 && val <= UINT32_MAX)
    {
        *((uint32_t*) dest) = (uint32_t) val;
        return true;
    }
    else if (width == 64)
    {
        *((uint64_t*) dest) = (uint64_t) val;
        return true;
    }
    else
    {
        // Invalid width and/or out of bounds value
        return false;
    }
}

static bool parse_float_value(const char* data, size_t len, uint8_t width, void* dest)
{
    char buf[21];

    if (len >= (sizeof(buf) / sizeof(char) - 1))
    {
        return false;
    }

    memcpy(buf, data, len);
    buf[len] = '\0';

    char* endptr;
    double val = strtod(buf, &endptr);

    if (endptr != (buf + len))
    {
        return false;
    }

    if (width == 32 && val >= FLT_MIN && val <= FLT_MAX)
    {
        *((float*) dest) = (float) val;
        return true;
    }
    else if (width == 64 && val >= DBL_MIN && val <= DBL_MAX)
    {
        *((double*) dest) = (double) val;
        return true;
    }
    else
    {
        // Invalid width and/or out of bounds value
        return false;
    }
}

static bool start_alias(struct parse_context_t* ctx, const XML_Char** attrs)
{
    assert(ctx->current_alias_alias == NULL);

    for (size_t i = 0; attrs[i]; i++)
    {
        const char* attr = attrs[i];

        if (strcmp(attr, "Alias") == 0)
        {
            const char* val = attrs[++i];
            ctx->current_alias_alias = dup_c_string(val);

            if (ctx->current_alias_alias == NULL)
            {
                LOG_MEMORY_ALLOCATION_FAILURE;
                return false;
            }

            break; // We ignore other attributes so far
        }
    }

    ctx->state = PARSE_ALIAS;

    return true;
}

static bool start_node(struct parse_context_t* ctx, uint32_t element_type, const XML_Char** attrs)
{
    assert(ctx->item.node_class == 0);

    SOPC_AddressSpace_Description_Item_Initialize(&ctx->item, element_type);

    for (size_t i = 0; attrs[i]; ++i)
    {
        const char* attr = attrs[i];

        if (strcmp("NodeId", attr) == 0)
        {
            const char* attr_val = attrs[++i];
            SOPC_NodeId* id = SOPC_NodeId_FromCString(attr_val, (int32_t) strlen(attr_val));

            if (id == NULL)
            {
                LOGF("Invalid variable NodeId: %s", attr_val);
                return false;
            }

            SOPC_NodeId* element_id = SOPC_AddressSpace_Description_Item_Get_NodeId(&ctx->item);

            SOPC_ReturnStatus status = SOPC_NodeId_Copy(element_id, id);
            SOPC_NodeId_Clear(id);
            free(id);

            if (status != SOPC_STATUS_OK)
            {
                LOG_MEMORY_ALLOCATION_FAILURE;
                return false;
            }
        }
        else if (strcmp("BrowseName", attr) == 0)
        {
            const char* attr_val = attrs[++i];

            SOPC_QualifiedName* element_browse_name = SOPC_AddressSpace_Description_Item_Get_BrowseName(&ctx->item);
            SOPC_QualifiedName_Initialize(element_browse_name);
            SOPC_ReturnStatus status = SOPC_QualifiedName_ParseCString(element_browse_name, attr_val);

            if (status != SOPC_STATUS_OK)
            {
                LOGF("Invalid browse name: %s", attr_val);
                return false;
            }
        }
    }

    ctx->state = PARSE_NODE;

    return true;
}

static bool start_node_references(struct parse_context_t* ctx, const XML_Char** attrs)
{
    int32_t* n_refs = SOPC_AddressSpace_Description_Item_Get_NoOfReferences(&ctx->item);
    OpcUa_ReferenceNode** refs = SOPC_AddressSpace_Description_Item_Get_References(&ctx->item);

    assert(*n_refs >= 0);
    int32_t new_n_refs = (*n_refs + 1);
    OpcUa_ReferenceNode* new_refs = realloc(*refs, ((size_t) new_n_refs) * sizeof(OpcUa_ReferenceNode));

    if (new_refs == NULL)
    {
        LOG_MEMORY_ALLOCATION_FAILURE;
        return false;
    }

    OpcUa_ReferenceNode* ref = &new_refs[new_n_refs - 1];
    OpcUa_ReferenceNode_Initialize(ref);
    *refs = new_refs;

    for (size_t i = 0; attrs[i]; ++i)
    {
        const char* attr = attrs[i];

        if (strcmp("ReferenceType", attr) == 0)
        {
            const char* val = attrs[++i];

            bool is_aliased;
            const char* aliased = SOPC_Dict_Get(ctx->aliases, val, &is_aliased);

            if (is_aliased)
            {
                val = aliased;
            }

            SOPC_NodeId* nodeid = SOPC_NodeId_FromCString(val, (int32_t) strlen(val));

            if (nodeid == NULL)
            {
                LOGF("Error while parsing ReferenceType '%s' into a NodeId\n.", val);
                return false;
            }

            SOPC_StatusCode status = SOPC_NodeId_Copy(&ref->ReferenceTypeId, nodeid);
            SOPC_NodeId_Clear(nodeid);
            free(nodeid);

            if (status != SOPC_STATUS_OK)
            {
                LOG_MEMORY_ALLOCATION_FAILURE;
                return false;
            }
        }
        else if (strcmp("IsForward", attr) == 0)
        {
            const char* val = attrs[++i];
            ref->IsInverse = (strcmp(val, "true") != 0);
        }
    }

    *n_refs = new_n_refs;
    ctx->state = PARSE_NODE_REFERENCE;

    return true;
}

static bool start_node_value(struct parse_context_t* ctx, const XML_Char** attrs)
{
    for (size_t i = 0; attrs[i]; ++i)
    {
        const char* attr = attrs[i];

        if (strcmp("AccessLevel", attr) == 0)
        {
            const char* val = attrs[++i];

            if (!parse_unsigned_value(val, strlen(val), 8, &ctx->item.data.variable.AccessLevel))
            {
                LOGF("Invalid AccessLevel on node value: '%s", val);
                return false;
            }
        }
    }

    return true;
}

static void skip_tag(struct parse_context_t* ctx, const char* name)
{
    assert(ctx->skip_tag[0] == 0);
    assert(strlen(name) < SKIP_TAG_LEN);
    strncpy(ctx->skip_tag, name, SKIP_TAG_LEN - 1);
}

static bool current_element_has_value(struct parse_context_t* ctx)
{
    switch (ctx->item.node_class)
    {
    case OpcUa_NodeClass_Variable:
    case OpcUa_NodeClass_VariableType:
        return true;
    default:
        return false;
    }
}

static SOPC_BuiltinId type_id_from_tag(const char* tag)
{
    // tag should have the correct namespace
    if (strncmp(tag, UA_TYPES_NS NS_SEPARATOR, strlen(UA_TYPES_NS NS_SEPARATOR)) != 0)
    {
        return SOPC_Null_Id;
    }

    const char* name = tag + strlen(UA_TYPES_NS NS_SEPARATOR);

    static const struct
    {
        const char* name;
        SOPC_BuiltinId id;
    } TYPE_IDS[] = {
        {"Boolean", SOPC_Boolean_Id},
        {"SByte", SOPC_SByte_Id},
        {"Byte", SOPC_Byte_Id},
        {"Int16", SOPC_Int16_Id},
        {"Int32", SOPC_Int32_Id},
        {"Int64", SOPC_Int64_Id},
        {"UInt16", SOPC_UInt16_Id},
        {"UInt32", SOPC_UInt32_Id},
        {"UInt64", SOPC_UInt64_Id},
        {"Float", SOPC_Float_Id},
        {"Double", SOPC_Double_Id},
        {"String", SOPC_String_Id},
        {"ByteString", SOPC_ByteString_Id},
        {"Guid", SOPC_Guid_Id},
        {"NodeId", SOPC_NodeId_Id},
        {"QualifiedName", SOPC_QualifiedName_Id},
        {"LocalizedText", SOPC_LocalizedText_Id},
        {"XmlElement", SOPC_XmlElement_Id},
        {NULL, SOPC_Null_Id},
    };

    for (size_t i = 0; TYPE_IDS[i].name != NULL; ++i)
    {
        if (strcmp(name, TYPE_IDS[i].name) == 0)
        {
            return TYPE_IDS[i].id;
        }
    }

    return SOPC_Null_Id;
}

static uint32_t element_id_from_tag(const char* tag)
{
    static const struct
    {
        const char* name;
        uint32_t id;
    } ELEMENT_TYPES[] = {
        {"UADataType", OpcUa_NodeClass_DataType},
        {"UAMethod", OpcUa_NodeClass_Method},
        {"UAObject", OpcUa_NodeClass_Object},
        {"UAObjectType", OpcUa_NodeClass_ObjectType},
        {"UAReferenceType", OpcUa_NodeClass_ReferenceType},
        {"UAVariable", OpcUa_NodeClass_Variable},
        {"UAVariableType", OpcUa_NodeClass_VariableType},
        {"UAView", OpcUa_NodeClass_View},
        {NULL, 0},
    };

    if (strncmp(tag, UA_NODESET_NS NS_SEPARATOR, strlen(UA_NODESET_NS NS_SEPARATOR)) != 0)
    {
        return 0;
    }

    const char* name = tag + strlen(UA_NODESET_NS NS_SEPARATOR);

    for (size_t i = 0; ELEMENT_TYPES[i].name != NULL; ++i)
    {
        if (strcmp(name, ELEMENT_TYPES[i].name) == 0)
        {
            return ELEMENT_TYPES[i].id;
        }
    }

    return 0;
}

static void start_element_handler(void* user_data, const XML_Char* name, const XML_Char** attrs)
{
    struct parse_context_t* ctx = user_data;

    if (ctx->skip_tag[0] != 0)
    {
        return; // We're skipping until the end of a tag
    }

    switch (ctx->state)
    {
    case PARSE_START:
        if (strcmp(name, NS(UA_NODESET_NS, "UANodeSet")) != 0)
        {
            LOGF("Unexpected tag %s", name);
            XML_StopParser(ctx->parser, 0);
            return;
        }

        ctx->state = PARSE_NODESET;
        return;
    case PARSE_NODESET:
    {
        uint32_t element_type = element_id_from_tag(name);

        if (element_type > 0)
        {
            if (!start_node(ctx, element_type, attrs))
            {
                XML_StopParser(ctx->parser, 0);
                return;
            }
        }
        else if (strcmp(NS(UA_NODESET_NS, "Aliases"), name) == 0)
        {
            ctx->state = PARSE_ALIASES;
        }
        else
        {
            skip_tag(ctx, name);
        }
        break;
    }
    case PARSE_NODE:
        if (strcmp(NS(UA_NODESET_NS, "DisplayName"), name) == 0)
        {
            ctx->state = PARSE_NODE_DISPLAYNAME;
        }
        else if (strcmp(NS(UA_NODESET_NS, "Description"), name) == 0)
        {
            ctx->state = PARSE_NODE_DESCRIPTION;
        }
        else if (strcmp(NS(UA_NODESET_NS, "References"), name) == 0)
        {
            ctx->state = PARSE_NODE_REFERENCES;
        }
        else if (current_element_has_value(ctx) && strcmp(NS(UA_NODESET_NS, "Value"), name) == 0)
        {
            if (!start_node_value(ctx, attrs))
            {
                XML_StopParser(ctx->parser, 0);
                return;
            }

            ctx->state = PARSE_NODE_VALUE;
        }
        else
        {
            skip_tag(ctx, name);
        }
        break;
    case PARSE_NODE_REFERENCES:
        if (strcmp(NS(UA_NODESET_NS, "Reference"), name) == 0)
        {
            if (!start_node_references(ctx, attrs))
            {
                XML_StopParser(ctx->parser, 0);
                return;
            }
        }
        else
        {
            skip_tag(ctx, name);
        }
        break;
    case PARSE_ALIASES:
        if (strcmp(NS(UA_NODESET_NS, "Alias"), name) == 0)
        {
            if (!start_alias(ctx, attrs))
            {
                XML_StopParser(ctx->parser, 0);
                return;
            }
        }
        else
        {
            skip_tag(ctx, name);
        }
        break;
    case PARSE_NODE_VALUE:
    {
        assert(current_element_has_value(ctx));

        SOPC_BuiltinId type_id = type_id_from_tag(name);

        if (type_id != SOPC_Null_Id)
        {
            assert(ctx->current_value_type == SOPC_Null_Id);
            ctx->current_value_type = type_id;
        }
        else
        {
            LOGF("Unsupported value type: %s", name);
            skip_tag(ctx, name);
        }
        break;
    }
    default:
        return;
    }
}

static bool finalize_alias(struct parse_context_t* ctx)
{
    if (ctx->current_alias_alias == NULL)
    {
        LOG("Missing Alias attribute on Alias.");
        return false;
    }

    char* target = dup_c_string(ctx_char_data_stripped(ctx));
    ctx_char_data_reset(ctx);

    if (target == NULL || !SOPC_Dict_Insert(ctx->aliases, ctx->current_alias_alias, target))
    {
        LOG_MEMORY_ALLOCATION_FAILURE;
        free(target);
        return false;
    }

    ctx->current_alias_alias = NULL;

    return true;
}

static bool finalize_reference(struct parse_context_t* ctx)
{
    int32_t* n_refs = SOPC_AddressSpace_Description_Item_Get_NoOfReferences(&ctx->item);
    OpcUa_ReferenceNode** refs = SOPC_AddressSpace_Description_Item_Get_References(&ctx->item);

    assert(*n_refs > 0);
    OpcUa_ReferenceNode* ref = &(*refs)[(*n_refs) - 1];
    const char* text = ctx_char_data_stripped(ctx);
    SOPC_NodeId* target_id = SOPC_NodeId_FromCString(text, (int32_t) strlen(text));

    if (target_id == NULL)
    {
        LOGF("Cannot parse reference target '%s' into a NodeId.", text);
        ctx_char_data_reset(ctx);
        return false;
    }

    ctx_char_data_reset(ctx);

    SOPC_ReturnStatus status = SOPC_NodeId_Copy(&ref->TargetId.NodeId, target_id);
    SOPC_NodeId_Clear(target_id);
    free(target_id);

    return status == SOPC_STATUS_OK;
}

static SOPC_LocalizedText* element_localized_text_for_state(struct parse_context_t* ctx)
{
    switch (ctx->state)
    {
    case PARSE_NODE_DISPLAYNAME:
        return SOPC_AddressSpace_Description_Item_Get_DisplayName(&ctx->item);
    case PARSE_NODE_DESCRIPTION:
        return SOPC_AddressSpace_Description_Item_Get_Description(&ctx->item);
    default:
        assert(false && "Unexpected state");
    }
}

static uint8_t type_width(SOPC_BuiltinId ty)
{
    switch (ty)
    {
    case SOPC_SByte_Id:
    case SOPC_Byte_Id:
        return 8;
    case SOPC_Int16_Id:
    case SOPC_UInt16_Id:
        return 16;
    case SOPC_Int32_Id:
    case SOPC_UInt32_Id:
        return 32;
    case SOPC_Int64_Id:
    case SOPC_UInt64_Id:
        return 64;
    default:
        assert(false && "Non numeric type");
    }
}

#define FOREACH_SIGNED_VALUE_TYPE(x) \
    x(SOPC_SByte_Id, Sbyte) x(SOPC_Int16_Id, Int16) x(SOPC_Int32_Id, Int32) x(SOPC_Int64_Id, Int64)

#define FOREACH_UNSIGNED_VALUE_TYPE(x) \
    x(SOPC_Byte_Id, Byte) x(SOPC_UInt16_Id, Uint16) x(SOPC_UInt32_Id, Uint32) x(SOPC_UInt64_Id, Uint64)

#define SET_INT_ELEMENT_VALUE_CASE(id, field, signed_or_unsigned)                                    \
    case id:                                                                                         \
        if (parse_##signed_or_unsigned##_value(val, strlen(val), type_width(id), &var->Value.field)) \
        {                                                                                            \
            var->BuiltInTypeId = id;                                                                 \
            return true;                                                                             \
        }                                                                                            \
        else                                                                                         \
        {                                                                                            \
            LOGF("Invalid integer value: '%s'", val);                                                \
            return false;                                                                            \
        }

#define SET_SIGNED_INT_ELEMENT_VALUE_CASE(id, field) SET_INT_ELEMENT_VALUE_CASE(id, field, signed)
#define SET_UNSIGNED_INT_ELEMENT_VALUE_CASE(id, field) SET_INT_ELEMENT_VALUE_CASE(id, field, unsigned)

#define SET_STR_ELEMENT_VALUE_CASE(field)                                      \
    if (SOPC_String_CopyFromCString(&var->Value.field, val) == SOPC_STATUS_OK) \
    {                                                                          \
        var->BuiltInTypeId = type_id;                                          \
        return true;                                                           \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        LOG_MEMORY_ALLOCATION_FAILURE;                                         \
        return false;                                                          \
    }

static bool set_variant_value_guid(SOPC_Variant* var, const char* guid_str)
{
    SOPC_Guid* guid = calloc(1, sizeof(SOPC_Guid));

    if (guid == NULL)
    {
        return false;
    }

    SOPC_Guid_Initialize(guid);

    if (SOPC_Guid_FromCString(guid, guid_str, strlen(guid_str)) != SOPC_STATUS_OK)
    {
        LOGF("Invalid GUID: '%s'", guid_str);
        SOPC_Guid_Clear(guid);
        free(guid);
        return false;
    }

    var->BuiltInTypeId = SOPC_Guid_Id;
    var->Value.Guid = guid;
    return true;
}

static bool set_variant_value_qname(SOPC_Variant* var, const char* qname_str)
{
    SOPC_QualifiedName* qname = calloc(1, sizeof(SOPC_QualifiedName));

    if (qname == NULL)
    {
        LOG_MEMORY_ALLOCATION_FAILURE;
        free(qname);
        return false;
    }

    SOPC_QualifiedName_Initialize(qname);
    SOPC_ReturnStatus status = SOPC_QualifiedName_ParseCString(qname, qname_str);

    if (status == SOPC_STATUS_OK)
    {
        var->BuiltInTypeId = SOPC_QualifiedName_Id;
        var->Value.Qname = qname;
        return true;
    }
    else
    {
        LOGF("Invalid qualified name: '%s'", qname_str);
        SOPC_QualifiedName_Clear(qname);
        free(qname);
        return false;
    }
}

static bool set_variant_value_localized_text(SOPC_Variant* var, const char* text)
{
    SOPC_LocalizedText* lt = calloc(1, sizeof(SOPC_LocalizedText));

    if (lt == NULL)
    {
        LOG_MEMORY_ALLOCATION_FAILURE;
        free(lt);
        return false;
    }

    SOPC_LocalizedText_Initialize(lt);

    if (SOPC_String_CopyFromCString(&lt->Text, text) != SOPC_STATUS_OK)
    {
        LOG_MEMORY_ALLOCATION_FAILURE;
        SOPC_LocalizedText_Clear(lt);
        free(lt);
        return false;
    }
    else
    {
        var->BuiltInTypeId = SOPC_LocalizedText_Id;
        var->Value.LocalizedText = lt;
        return true;
    }
}

static bool set_variant_value_nodeid(SOPC_Variant* var, const char* id)
{
    size_t len = strlen(id);
    assert(len <= INT32_MAX);

    var->Value.NodeId = SOPC_NodeId_FromCString(id, (int32_t) len);

    if (var->Value.NodeId == NULL)
    {
        LOGF("Invalid NodeId: '%s'", id);
        return false;
    }

    var->BuiltInTypeId = SOPC_NodeId_Id;
    return true;
}

static bool set_variant_value(SOPC_Variant* var, SOPC_BuiltinId type_id, const char* val)
{
    switch (type_id)
    {
    case SOPC_Boolean_Id:
        var->BuiltInTypeId = SOPC_Boolean_Id;
        var->Value.Boolean = (strcmp(val, "true") == 0);
        return true;
        FOREACH_SIGNED_VALUE_TYPE(SET_SIGNED_INT_ELEMENT_VALUE_CASE)
        FOREACH_UNSIGNED_VALUE_TYPE(SET_UNSIGNED_INT_ELEMENT_VALUE_CASE)
    case SOPC_Float_Id:
        if (parse_float_value(val, strlen(val), 32, &var->Value.Floatv))
        {
            var->BuiltInTypeId = SOPC_Float_Id;
            return true;
        }
        else
        {
            LOGF("Invalid float value: '%s'", val);
            return false;
        }
    case SOPC_Double_Id:
        if (parse_float_value(val, strlen(val), 64, &var->Value.Doublev))
        {
            var->BuiltInTypeId = SOPC_Double_Id;
            return true;
        }
        else
        {
            LOGF("Invalid double value: '%s'", val);
            return false;
        }
    case SOPC_String_Id:
        SET_STR_ELEMENT_VALUE_CASE(String)
    case SOPC_ByteString_Id:
        SET_STR_ELEMENT_VALUE_CASE(Bstring)
    case SOPC_XmlElement_Id:
        SET_STR_ELEMENT_VALUE_CASE(XmlElt)
    case SOPC_Guid_Id:
        return set_variant_value_guid(var, val);
    case SOPC_NodeId_Id:
        return set_variant_value_nodeid(var, val);
    case SOPC_QualifiedName_Id:
        return set_variant_value_qname(var, val);
    case SOPC_LocalizedText_Id:
        return set_variant_value_localized_text(var, val);
    default:
        assert(false && "Cannot parse current value type.");
    }
}

static bool set_element_value(struct parse_context_t* ctx)
{
    SOPC_Variant* var = SOPC_AddressSpace_Description_Item_Get_Value(&ctx->item);
    bool ok = set_variant_value(var, ctx->current_value_type, ctx_char_data_stripped(ctx));
    ctx_char_data_reset(ctx);

    return ok;
}

static void end_element_handler(void* user_data, const XML_Char* name)
{
    struct parse_context_t* ctx = user_data;

    if ((ctx->skip_tag[0] != 0) && (strcmp(ctx->skip_tag, name) == 0))
    {
        ctx->skip_tag[0] = 0;
        return;
    }

    switch (ctx->state)
    {
    case PARSE_ALIASES:
        ctx->state = PARSE_NODESET;
        break;
    case PARSE_ALIAS:
    {
        bool ok = finalize_alias(ctx);

        free(ctx->current_alias_alias);
        ctx->current_alias_alias = NULL;

        if (!ok)
        {
            XML_StopParser(ctx->parser, false);
            return;
        }

        ctx->state = PARSE_ALIASES;
        break;
    }
    case PARSE_NODE_DISPLAYNAME:
    case PARSE_NODE_DESCRIPTION:
    {
        SOPC_LocalizedText* lt = element_localized_text_for_state(ctx);
        SOPC_String_Clear(&lt->Text);
        SOPC_ReturnStatus status = SOPC_String_CopyFromCString(&lt->Text, ctx_char_data_stripped(ctx));
        ctx_char_data_reset(ctx);

        if (status != SOPC_STATUS_OK)
        {
            LOG_MEMORY_ALLOCATION_FAILURE;
            XML_StopParser(ctx->parser, false);
            return;
        }

        ctx->state = PARSE_NODE;
        break;
    }
    case PARSE_NODE_REFERENCES:
        ctx->state = PARSE_NODE;
        break;
    case PARSE_NODE_VALUE:
        if ((ctx->current_value_type != SOPC_Null_Id) && !set_element_value(ctx))
        {
            XML_StopParser(ctx->parser, false);
            return;
        }

        ctx->current_value_type = SOPC_Null_Id;
        ctx->state = PARSE_NODE;
        break;
    case PARSE_NODE:
    {
        SOPC_ReturnStatus status = SOPC_STATUS_NOK;
        SOPC_AddressSpace_Description_Item* item = calloc(1, sizeof(SOPC_AddressSpace_Description_Item));

        if (item != NULL)
        {
            memcpy(item, &ctx->item, sizeof(SOPC_AddressSpace_Description_Item));
            ctx->item.node_class = 0;
            status = SOPC_AddressSpace_Description_Append(ctx->desc, item);
        }
        else
        {
            LOG_MEMORY_ALLOCATION_FAILURE;
        }

        if (status != SOPC_STATUS_OK)
        {
            LOG_MEMORY_ALLOCATION_FAILURE;
            SOPC_AddressSpace_Description_Item_Clear(&ctx->item);
            free(item);
            XML_StopParser(ctx->parser, false);
            return;
        }

        ctx->item.node_class = 0;
        ctx->state = PARSE_NODESET;
        break;
    }
    case PARSE_NODE_REFERENCE:
        if (!finalize_reference(ctx))
        {
            XML_StopParser(ctx->parser, false);
            return;
        }

        ctx->state = PARSE_NODE_REFERENCES;
        break;
    case PARSE_NODESET:
        break;
    case PARSE_START:
        assert(false && "Got end_element callback when in PARSE_START state.");
        break;
    }
}

static void char_data_handler(void* user_data, const XML_Char* s, int len)
{
    assert(len >= 0);

    struct parse_context_t* ctx = user_data;

    switch (ctx->state)
    {
    case PARSE_NODE_DISPLAYNAME:
    case PARSE_NODE_DESCRIPTION:
    case PARSE_ALIAS:
    case PARSE_NODE_REFERENCE:
    case PARSE_NODE_VALUE:
        if (!ctx_char_data_append(ctx, s, (size_t) len))
        {
            XML_StopParser(ctx->parser, false);
            return;
        }

        break;
    default:
        return;
    }
}

static uint64_t str_hash(const void* data)
{
    return SOPC_DJBHash((const uint8_t*) data, strlen((const char*) data));
}

static bool str_equal(const void* a, const void* b)
{
    return strcmp((const char*) a, (const char*) b) == 0;
}

SOPC_StatusCode SOPC_UANodeSet_Parse(FILE* fd, SOPC_AddressSpace_Description* desc)
{
    static const size_t char_data_cap_initial = 4096;
    SOPC_Dict* aliases = SOPC_Dict_Create(NULL, str_hash, str_equal, free, free);
    XML_Parser parser = XML_ParserCreateNS(NULL, NS_SEPARATOR[0]);
    char* char_data_buffer = calloc(char_data_cap_initial, sizeof(char));

    if ((aliases == NULL) || (parser == NULL) || (char_data_buffer == NULL))
    {
        LOG_MEMORY_ALLOCATION_FAILURE;
        SOPC_Dict_Delete(aliases);
        XML_ParserFree(parser);
        free(char_data_buffer);
        return SOPC_STATUS_NOK;
    }

    struct parse_context_t ctx;
    memset(&ctx, 0, sizeof(struct parse_context_t));
    XML_SetUserData(parser, &ctx);

    ctx.aliases = aliases;
    ctx.state = PARSE_START;
    ctx.parser = parser;
    ctx.desc = desc;
    ctx.char_data_buffer = char_data_buffer;
    ctx.char_data_cap = char_data_cap_initial;

    XML_SetElementHandler(parser, start_element_handler, end_element_handler);
    XML_SetCharacterDataHandler(parser, char_data_handler);

    SOPC_StatusCode res = parse(parser, fd);
    XML_ParserFree(parser);
    SOPC_Dict_Delete(aliases);
    free(ctx.current_alias_alias);
    free(ctx.char_data_buffer);

    return res;
}