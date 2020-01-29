/*
 * Licensed to Systerel under one or more contributor license
 * agreements. See the NOTICE file distributed with this work
 * for additional information regarding copyright ownership.
 * Systerel licenses this file to you under the Apache
 * License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "opcua_identifiers.h"
#include "sopc_types.h"
#include "sopc_encoder.h"


#ifndef OPCUA_EXCLUDE_ReferenceNode
/*============================================================================
 * OpcUa_ReferenceNode_Initialize
 *===========================================================================*/
void OpcUa_ReferenceNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReferenceNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceNode_Clear
 *===========================================================================*/
void OpcUa_ReferenceNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReferenceNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReferenceNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReferenceNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReferenceNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReferenceNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReferenceNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceNode, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceNode, IsInverse) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceNode, TargetId) // offset
    },
};

/*============================================================================
 * Descriptor of the ReferenceNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReferenceNode_EncodeableType =
{
    "ReferenceNode",
    OpcUaId_ReferenceNode,
    OpcUaId_ReferenceNode_Encoding_DefaultBinary,
    OpcUaId_ReferenceNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReferenceNode),
    OpcUa_ReferenceNode_Initialize,
    OpcUa_ReferenceNode_Clear,
    NULL,
    OpcUa_ReferenceNode_Encode,
    OpcUa_ReferenceNode_Decode,
    sizeof ReferenceNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReferenceNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Node
/*============================================================================
 * OpcUa_Node_Initialize
 *===========================================================================*/
void OpcUa_Node_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_Node_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Node_Clear
 *===========================================================================*/
void OpcUa_Node_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_Node_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Node_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Node_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_Node_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_Node_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Node_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_Node_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the Node encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor Node_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_Node, References) // offset
    },
};

/*============================================================================
 * Descriptor of the Node encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_Node_EncodeableType =
{
    "Node",
    OpcUaId_Node,
    OpcUaId_Node_Encoding_DefaultBinary,
    OpcUaId_Node_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_Node),
    OpcUa_Node_Initialize,
    OpcUa_Node_Clear,
    NULL,
    OpcUa_Node_Encode,
    OpcUa_Node_Decode,
    sizeof Node_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    Node_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_InstanceNode
/*============================================================================
 * OpcUa_InstanceNode_Initialize
 *===========================================================================*/
void OpcUa_InstanceNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_InstanceNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_InstanceNode_Clear
 *===========================================================================*/
void OpcUa_InstanceNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_InstanceNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_InstanceNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_InstanceNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_InstanceNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_InstanceNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_InstanceNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_InstanceNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the InstanceNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor InstanceNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_InstanceNode, References) // offset
    },
};

/*============================================================================
 * Descriptor of the InstanceNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_InstanceNode_EncodeableType =
{
    "InstanceNode",
    OpcUaId_InstanceNode,
    OpcUaId_InstanceNode_Encoding_DefaultBinary,
    OpcUaId_InstanceNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_InstanceNode),
    OpcUa_InstanceNode_Initialize,
    OpcUa_InstanceNode_Clear,
    NULL,
    OpcUa_InstanceNode_Encode,
    OpcUa_InstanceNode_Decode,
    sizeof InstanceNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    InstanceNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_TypeNode
/*============================================================================
 * OpcUa_TypeNode_Initialize
 *===========================================================================*/
void OpcUa_TypeNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TypeNode_Clear
 *===========================================================================*/
void OpcUa_TypeNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TypeNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TypeNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TypeNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TypeNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TypeNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TypeNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_TypeNode, References) // offset
    },
};

/*============================================================================
 * Descriptor of the TypeNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TypeNode_EncodeableType =
{
    "TypeNode",
    OpcUaId_TypeNode,
    OpcUaId_TypeNode_Encoding_DefaultBinary,
    OpcUaId_TypeNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TypeNode),
    OpcUa_TypeNode_Initialize,
    OpcUa_TypeNode_Clear,
    NULL,
    OpcUa_TypeNode_Encode,
    OpcUa_TypeNode_Decode,
    sizeof TypeNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TypeNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ObjectNode
/*============================================================================
 * OpcUa_ObjectNode_Initialize
 *===========================================================================*/
void OpcUa_ObjectNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ObjectNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectNode_Clear
 *===========================================================================*/
void OpcUa_ObjectNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ObjectNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ObjectNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ObjectNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ObjectNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ObjectNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ObjectNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectNode, EventNotifier) // offset
    },
};

/*============================================================================
 * Descriptor of the ObjectNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ObjectNode_EncodeableType =
{
    "ObjectNode",
    OpcUaId_ObjectNode,
    OpcUaId_ObjectNode_Encoding_DefaultBinary,
    OpcUaId_ObjectNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ObjectNode),
    OpcUa_ObjectNode_Initialize,
    OpcUa_ObjectNode_Clear,
    NULL,
    OpcUa_ObjectNode_Encode,
    OpcUa_ObjectNode_Decode,
    sizeof ObjectNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ObjectNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ObjectTypeNode
/*============================================================================
 * OpcUa_ObjectTypeNode_Initialize
 *===========================================================================*/
void OpcUa_ObjectTypeNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ObjectTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectTypeNode_Clear
 *===========================================================================*/
void OpcUa_ObjectTypeNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ObjectTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectTypeNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectTypeNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ObjectTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ObjectTypeNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectTypeNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ObjectTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ObjectTypeNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ObjectTypeNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeNode, IsAbstract) // offset
    },
};

/*============================================================================
 * Descriptor of the ObjectTypeNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ObjectTypeNode_EncodeableType =
{
    "ObjectTypeNode",
    OpcUaId_ObjectTypeNode,
    OpcUaId_ObjectTypeNode_Encoding_DefaultBinary,
    OpcUaId_ObjectTypeNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ObjectTypeNode),
    OpcUa_ObjectTypeNode_Initialize,
    OpcUa_ObjectTypeNode_Clear,
    NULL,
    OpcUa_ObjectTypeNode_Encode,
    OpcUa_ObjectTypeNode_Decode,
    sizeof ObjectTypeNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ObjectTypeNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_VariableNode
/*============================================================================
 * OpcUa_VariableNode_Initialize
 *===========================================================================*/
void OpcUa_VariableNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_VariableNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableNode_Clear
 *===========================================================================*/
void OpcUa_VariableNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_VariableNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_VariableNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_VariableNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_VariableNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the VariableNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor VariableNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, DataType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, ValueRank) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, NoOfArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, ArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, AccessLevel) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, UserAccessLevel) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, MinimumSamplingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableNode, Historizing) // offset
    },
};

/*============================================================================
 * Descriptor of the VariableNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_VariableNode_EncodeableType =
{
    "VariableNode",
    OpcUaId_VariableNode,
    OpcUaId_VariableNode_Encoding_DefaultBinary,
    OpcUaId_VariableNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_VariableNode),
    OpcUa_VariableNode_Initialize,
    OpcUa_VariableNode_Clear,
    NULL,
    OpcUa_VariableNode_Encode,
    OpcUa_VariableNode_Decode,
    sizeof VariableNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    VariableNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_VariableTypeNode
/*============================================================================
 * OpcUa_VariableTypeNode_Initialize
 *===========================================================================*/
void OpcUa_VariableTypeNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_VariableTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableTypeNode_Clear
 *===========================================================================*/
void OpcUa_VariableTypeNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_VariableTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableTypeNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableTypeNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_VariableTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_VariableTypeNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableTypeNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_VariableTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the VariableTypeNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor VariableTypeNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, DataType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, ValueRank) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, NoOfArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, ArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeNode, IsAbstract) // offset
    },
};

/*============================================================================
 * Descriptor of the VariableTypeNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_VariableTypeNode_EncodeableType =
{
    "VariableTypeNode",
    OpcUaId_VariableTypeNode,
    OpcUaId_VariableTypeNode_Encoding_DefaultBinary,
    OpcUaId_VariableTypeNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_VariableTypeNode),
    OpcUa_VariableTypeNode_Initialize,
    OpcUa_VariableTypeNode_Clear,
    NULL,
    OpcUa_VariableTypeNode_Encode,
    OpcUa_VariableTypeNode_Decode,
    sizeof VariableTypeNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    VariableTypeNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReferenceTypeNode
/*============================================================================
 * OpcUa_ReferenceTypeNode_Initialize
 *===========================================================================*/
void OpcUa_ReferenceTypeNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReferenceTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceTypeNode_Clear
 *===========================================================================*/
void OpcUa_ReferenceTypeNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReferenceTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceTypeNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceTypeNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReferenceTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReferenceTypeNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceTypeNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReferenceTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReferenceTypeNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReferenceTypeNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, IsAbstract) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, Symmetric) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeNode, InverseName) // offset
    },
};

/*============================================================================
 * Descriptor of the ReferenceTypeNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReferenceTypeNode_EncodeableType =
{
    "ReferenceTypeNode",
    OpcUaId_ReferenceTypeNode,
    OpcUaId_ReferenceTypeNode_Encoding_DefaultBinary,
    OpcUaId_ReferenceTypeNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReferenceTypeNode),
    OpcUa_ReferenceTypeNode_Initialize,
    OpcUa_ReferenceTypeNode_Clear,
    NULL,
    OpcUa_ReferenceTypeNode_Encode,
    OpcUa_ReferenceTypeNode_Decode,
    sizeof ReferenceTypeNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReferenceTypeNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MethodNode
/*============================================================================
 * OpcUa_MethodNode_Initialize
 *===========================================================================*/
void OpcUa_MethodNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MethodNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MethodNode_Clear
 *===========================================================================*/
void OpcUa_MethodNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MethodNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MethodNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MethodNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MethodNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MethodNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MethodNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MethodNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MethodNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MethodNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, Executable) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodNode, UserExecutable) // offset
    },
};

/*============================================================================
 * Descriptor of the MethodNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MethodNode_EncodeableType =
{
    "MethodNode",
    OpcUaId_MethodNode,
    OpcUaId_MethodNode_Encoding_DefaultBinary,
    OpcUaId_MethodNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MethodNode),
    OpcUa_MethodNode_Initialize,
    OpcUa_MethodNode_Clear,
    NULL,
    OpcUa_MethodNode_Encode,
    OpcUa_MethodNode_Decode,
    sizeof MethodNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MethodNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ViewNode
/*============================================================================
 * OpcUa_ViewNode_Initialize
 *===========================================================================*/
void OpcUa_ViewNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ViewNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ViewNode_Clear
 *===========================================================================*/
void OpcUa_ViewNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ViewNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ViewNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ViewNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ViewNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ViewNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ViewNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ViewNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ViewNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ViewNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, ContainsNoLoops) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewNode, EventNotifier) // offset
    },
};

/*============================================================================
 * Descriptor of the ViewNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ViewNode_EncodeableType =
{
    "ViewNode",
    OpcUaId_ViewNode,
    OpcUaId_ViewNode_Encoding_DefaultBinary,
    OpcUaId_ViewNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ViewNode),
    OpcUa_ViewNode_Initialize,
    OpcUa_ViewNode_Clear,
    NULL,
    OpcUa_ViewNode_Encode,
    OpcUa_ViewNode_Decode,
    sizeof ViewNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ViewNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DataTypeNode
/*============================================================================
 * OpcUa_DataTypeNode_Initialize
 *===========================================================================*/
void OpcUa_DataTypeNode_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DataTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataTypeNode_Clear
 *===========================================================================*/
void OpcUa_DataTypeNode_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DataTypeNode_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataTypeNode_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataTypeNode_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DataTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DataTypeNode_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataTypeNode_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DataTypeNode_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DataTypeNode encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DataTypeNode_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceNode, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, References) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeNode, IsAbstract) // offset
    },
};

/*============================================================================
 * Descriptor of the DataTypeNode encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DataTypeNode_EncodeableType =
{
    "DataTypeNode",
    OpcUaId_DataTypeNode,
    OpcUaId_DataTypeNode_Encoding_DefaultBinary,
    OpcUaId_DataTypeNode_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DataTypeNode),
    OpcUa_DataTypeNode_Initialize,
    OpcUa_DataTypeNode_Clear,
    NULL,
    OpcUa_DataTypeNode_Encode,
    OpcUa_DataTypeNode_Decode,
    sizeof DataTypeNode_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DataTypeNode_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Argument
/*============================================================================
 * OpcUa_Argument_Initialize
 *===========================================================================*/
void OpcUa_Argument_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_Argument_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Argument_Clear
 *===========================================================================*/
void OpcUa_Argument_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_Argument_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Argument_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Argument_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_Argument_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_Argument_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Argument_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_Argument_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the Argument encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor Argument_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Argument, Name) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Argument, DataType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Argument, ValueRank) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Argument, NoOfArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Argument, ArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Argument, Description) // offset
    },
};

/*============================================================================
 * Descriptor of the Argument encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_Argument_EncodeableType =
{
    "Argument",
    OpcUaId_Argument,
    OpcUaId_Argument_Encoding_DefaultBinary,
    OpcUaId_Argument_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_Argument),
    OpcUa_Argument_Initialize,
    OpcUa_Argument_Clear,
    NULL,
    OpcUa_Argument_Encode,
    OpcUa_Argument_Decode,
    sizeof Argument_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    Argument_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EnumValueType
/*============================================================================
 * OpcUa_EnumValueType_Initialize
 *===========================================================================*/
void OpcUa_EnumValueType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EnumValueType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EnumValueType_Clear
 *===========================================================================*/
void OpcUa_EnumValueType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EnumValueType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EnumValueType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EnumValueType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EnumValueType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EnumValueType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EnumValueType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EnumValueType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EnumValueType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EnumValueType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int64_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumValueType, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumValueType, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumValueType, Description) // offset
    },
};

/*============================================================================
 * Descriptor of the EnumValueType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EnumValueType_EncodeableType =
{
    "EnumValueType",
    OpcUaId_EnumValueType,
    OpcUaId_EnumValueType_Encoding_DefaultBinary,
    OpcUaId_EnumValueType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EnumValueType),
    OpcUa_EnumValueType_Initialize,
    OpcUa_EnumValueType_Clear,
    NULL,
    OpcUa_EnumValueType_Encode,
    OpcUa_EnumValueType_Decode,
    sizeof EnumValueType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EnumValueType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EnumField
/*============================================================================
 * OpcUa_EnumField_Initialize
 *===========================================================================*/
void OpcUa_EnumField_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EnumField_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EnumField_Clear
 *===========================================================================*/
void OpcUa_EnumField_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EnumField_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EnumField_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EnumField_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EnumField_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EnumField_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EnumField_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EnumField_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EnumField encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EnumField_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int64_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumField, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumField, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumField, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EnumField, Name) // offset
    },
};

/*============================================================================
 * Descriptor of the EnumField encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EnumField_EncodeableType =
{
    "EnumField",
    OpcUaId_EnumField,
    OpcUaId_EnumField_Encoding_DefaultBinary,
    OpcUaId_EnumField_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EnumField),
    OpcUa_EnumField_Initialize,
    OpcUa_EnumField_Clear,
    NULL,
    OpcUa_EnumField_Encode,
    OpcUa_EnumField_Decode,
    sizeof EnumField_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EnumField_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_OptionSet
/*============================================================================
 * OpcUa_OptionSet_Initialize
 *===========================================================================*/
void OpcUa_OptionSet_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_OptionSet_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_OptionSet_Clear
 *===========================================================================*/
void OpcUa_OptionSet_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_OptionSet_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_OptionSet_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_OptionSet_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_OptionSet_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_OptionSet_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_OptionSet_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_OptionSet_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the OptionSet encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor OptionSet_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OptionSet, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OptionSet, ValidBits) // offset
    },
};

/*============================================================================
 * Descriptor of the OptionSet encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_OptionSet_EncodeableType =
{
    "OptionSet",
    OpcUaId_OptionSet,
    OpcUaId_OptionSet_Encoding_DefaultBinary,
    OpcUaId_OptionSet_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_OptionSet),
    OpcUa_OptionSet_Initialize,
    OpcUa_OptionSet_Clear,
    NULL,
    OpcUa_OptionSet_Encode,
    OpcUa_OptionSet_Decode,
    sizeof OptionSet_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    OptionSet_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_TimeZoneDataType
/*============================================================================
 * OpcUa_TimeZoneDataType_Initialize
 *===========================================================================*/
void OpcUa_TimeZoneDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TimeZoneDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TimeZoneDataType_Clear
 *===========================================================================*/
void OpcUa_TimeZoneDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TimeZoneDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TimeZoneDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TimeZoneDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TimeZoneDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TimeZoneDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TimeZoneDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TimeZoneDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TimeZoneDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TimeZoneDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int16_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TimeZoneDataType, Offset) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TimeZoneDataType, DaylightSavingInOffset) // offset
    },
};

/*============================================================================
 * Descriptor of the TimeZoneDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TimeZoneDataType_EncodeableType =
{
    "TimeZoneDataType",
    OpcUaId_TimeZoneDataType,
    OpcUaId_TimeZoneDataType_Encoding_DefaultBinary,
    OpcUaId_TimeZoneDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TimeZoneDataType),
    OpcUa_TimeZoneDataType_Initialize,
    OpcUa_TimeZoneDataType_Clear,
    NULL,
    OpcUa_TimeZoneDataType_Encode,
    OpcUa_TimeZoneDataType_Decode,
    sizeof TimeZoneDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TimeZoneDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ApplicationDescription
/*============================================================================
 * OpcUa_ApplicationDescription_Initialize
 *===========================================================================*/
void OpcUa_ApplicationDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ApplicationDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ApplicationDescription_Clear
 *===========================================================================*/
void OpcUa_ApplicationDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ApplicationDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ApplicationDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ApplicationDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ApplicationDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ApplicationDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ApplicationDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ApplicationDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ApplicationDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ApplicationDescription_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, ApplicationUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, ProductUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, ApplicationName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, ApplicationType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, GatewayServerUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, DiscoveryProfileUri) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, NoOfDiscoveryUrls) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ApplicationDescription, DiscoveryUrls) // offset
    },
};

/*============================================================================
 * Descriptor of the ApplicationDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ApplicationDescription_EncodeableType =
{
    "ApplicationDescription",
    OpcUaId_ApplicationDescription,
    OpcUaId_ApplicationDescription_Encoding_DefaultBinary,
    OpcUaId_ApplicationDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ApplicationDescription),
    OpcUa_ApplicationDescription_Initialize,
    OpcUa_ApplicationDescription_Clear,
    NULL,
    OpcUa_ApplicationDescription_Encode,
    OpcUa_ApplicationDescription_Decode,
    sizeof ApplicationDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ApplicationDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RequestHeader
/*============================================================================
 * OpcUa_RequestHeader_Initialize
 *===========================================================================*/
void OpcUa_RequestHeader_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RequestHeader_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RequestHeader_Clear
 *===========================================================================*/
void OpcUa_RequestHeader_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RequestHeader_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RequestHeader_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RequestHeader_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RequestHeader_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RequestHeader_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RequestHeader_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RequestHeader_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RequestHeader encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RequestHeader_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, AuthenticationToken) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, Timestamp) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, RequestHandle) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, ReturnDiagnostics) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, AuditEntryId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, TimeoutHint) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RequestHeader, AdditionalHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the RequestHeader encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RequestHeader_EncodeableType =
{
    "RequestHeader",
    OpcUaId_RequestHeader,
    OpcUaId_RequestHeader_Encoding_DefaultBinary,
    OpcUaId_RequestHeader_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RequestHeader),
    OpcUa_RequestHeader_Initialize,
    OpcUa_RequestHeader_Clear,
    NULL,
    OpcUa_RequestHeader_Encode,
    OpcUa_RequestHeader_Decode,
    sizeof RequestHeader_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RequestHeader_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ResponseHeader
/*============================================================================
 * OpcUa_ResponseHeader_Initialize
 *===========================================================================*/
void OpcUa_ResponseHeader_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ResponseHeader_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ResponseHeader_Clear
 *===========================================================================*/
void OpcUa_ResponseHeader_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ResponseHeader_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ResponseHeader_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ResponseHeader_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ResponseHeader_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ResponseHeader_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ResponseHeader_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ResponseHeader_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ResponseHeader encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ResponseHeader_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, Timestamp) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, RequestHandle) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, ServiceResult) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, ServiceDiagnostics) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, NoOfStringTable) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, StringTable) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ResponseHeader, AdditionalHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the ResponseHeader encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ResponseHeader_EncodeableType =
{
    "ResponseHeader",
    OpcUaId_ResponseHeader,
    OpcUaId_ResponseHeader_Encoding_DefaultBinary,
    OpcUaId_ResponseHeader_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ResponseHeader),
    OpcUa_ResponseHeader_Initialize,
    OpcUa_ResponseHeader_Clear,
    NULL,
    OpcUa_ResponseHeader_Encode,
    OpcUa_ResponseHeader_Decode,
    sizeof ResponseHeader_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ResponseHeader_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ServiceFault
/*============================================================================
 * OpcUa_ServiceFault_Initialize
 *===========================================================================*/
void OpcUa_ServiceFault_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ServiceFault_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServiceFault_Clear
 *===========================================================================*/
void OpcUa_ServiceFault_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ServiceFault_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServiceFault_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServiceFault_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ServiceFault_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ServiceFault_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServiceFault_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ServiceFault_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ServiceFault encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ServiceFault_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_ServiceFault, ResponseHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the ServiceFault encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ServiceFault_EncodeableType =
{
    "ServiceFault",
    OpcUaId_ServiceFault,
    OpcUaId_ServiceFault_Encoding_DefaultBinary,
    OpcUaId_ServiceFault_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ServiceFault),
    OpcUa_ServiceFault_Initialize,
    OpcUa_ServiceFault_Clear,
    NULL,
    OpcUa_ServiceFault_Encode,
    OpcUa_ServiceFault_Decode,
    sizeof ServiceFault_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ServiceFault_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_FindServers
#ifndef OPCUA_EXCLUDE_FindServersRequest
/*============================================================================
 * OpcUa_FindServersRequest_Initialize
 *===========================================================================*/
void OpcUa_FindServersRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_FindServersRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersRequest_Clear
 *===========================================================================*/
void OpcUa_FindServersRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_FindServersRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_FindServersRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_FindServersRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_FindServersRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the FindServersRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor FindServersRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersRequest, EndpointUrl) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersRequest, NoOfLocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersRequest, LocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersRequest, NoOfServerUris) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersRequest, ServerUris) // offset
    },
};

/*============================================================================
 * Descriptor of the FindServersRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_FindServersRequest_EncodeableType =
{
    "FindServersRequest",
    OpcUaId_FindServersRequest,
    OpcUaId_FindServersRequest_Encoding_DefaultBinary,
    OpcUaId_FindServersRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_FindServersRequest),
    OpcUa_FindServersRequest_Initialize,
    OpcUa_FindServersRequest_Clear,
    NULL,
    OpcUa_FindServersRequest_Encode,
    OpcUa_FindServersRequest_Decode,
    sizeof FindServersRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    FindServersRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_FindServersResponse
/*============================================================================
 * OpcUa_FindServersResponse_Initialize
 *===========================================================================*/
void OpcUa_FindServersResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_FindServersResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersResponse_Clear
 *===========================================================================*/
void OpcUa_FindServersResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_FindServersResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_FindServersResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_FindServersResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_FindServersResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the FindServersResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor FindServersResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersResponse, NoOfServers) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ApplicationDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersResponse, Servers) // offset
    },
};

/*============================================================================
 * Descriptor of the FindServersResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_FindServersResponse_EncodeableType =
{
    "FindServersResponse",
    OpcUaId_FindServersResponse,
    OpcUaId_FindServersResponse_Encoding_DefaultBinary,
    OpcUaId_FindServersResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_FindServersResponse),
    OpcUa_FindServersResponse_Initialize,
    OpcUa_FindServersResponse_Clear,
    NULL,
    OpcUa_FindServersResponse_Encode,
    OpcUa_FindServersResponse_Decode,
    sizeof FindServersResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    FindServersResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_ServerOnNetwork
/*============================================================================
 * OpcUa_ServerOnNetwork_Initialize
 *===========================================================================*/
void OpcUa_ServerOnNetwork_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ServerOnNetwork_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServerOnNetwork_Clear
 *===========================================================================*/
void OpcUa_ServerOnNetwork_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ServerOnNetwork_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServerOnNetwork_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServerOnNetwork_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ServerOnNetwork_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ServerOnNetwork_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServerOnNetwork_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ServerOnNetwork_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ServerOnNetwork encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ServerOnNetwork_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerOnNetwork, RecordId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerOnNetwork, ServerName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerOnNetwork, DiscoveryUrl) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerOnNetwork, NoOfServerCapabilities) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerOnNetwork, ServerCapabilities) // offset
    },
};

/*============================================================================
 * Descriptor of the ServerOnNetwork encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ServerOnNetwork_EncodeableType =
{
    "ServerOnNetwork",
    OpcUaId_ServerOnNetwork,
    OpcUaId_ServerOnNetwork_Encoding_DefaultBinary,
    OpcUaId_ServerOnNetwork_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ServerOnNetwork),
    OpcUa_ServerOnNetwork_Initialize,
    OpcUa_ServerOnNetwork_Clear,
    NULL,
    OpcUa_ServerOnNetwork_Encode,
    OpcUa_ServerOnNetwork_Decode,
    sizeof ServerOnNetwork_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ServerOnNetwork_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_FindServersOnNetwork
#ifndef OPCUA_EXCLUDE_FindServersOnNetworkRequest
/*============================================================================
 * OpcUa_FindServersOnNetworkRequest_Initialize
 *===========================================================================*/
void OpcUa_FindServersOnNetworkRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_FindServersOnNetworkRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersOnNetworkRequest_Clear
 *===========================================================================*/
void OpcUa_FindServersOnNetworkRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_FindServersOnNetworkRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersOnNetworkRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersOnNetworkRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_FindServersOnNetworkRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_FindServersOnNetworkRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersOnNetworkRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_FindServersOnNetworkRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the FindServersOnNetworkRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor FindServersOnNetworkRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkRequest, StartingRecordId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkRequest, MaxRecordsToReturn) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkRequest, NoOfServerCapabilityFilter) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkRequest, ServerCapabilityFilter) // offset
    },
};

/*============================================================================
 * Descriptor of the FindServersOnNetworkRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_FindServersOnNetworkRequest_EncodeableType =
{
    "FindServersOnNetworkRequest",
    OpcUaId_FindServersOnNetworkRequest,
    OpcUaId_FindServersOnNetworkRequest_Encoding_DefaultBinary,
    OpcUaId_FindServersOnNetworkRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_FindServersOnNetworkRequest),
    OpcUa_FindServersOnNetworkRequest_Initialize,
    OpcUa_FindServersOnNetworkRequest_Clear,
    NULL,
    OpcUa_FindServersOnNetworkRequest_Encode,
    OpcUa_FindServersOnNetworkRequest_Decode,
    sizeof FindServersOnNetworkRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    FindServersOnNetworkRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_FindServersOnNetworkResponse
/*============================================================================
 * OpcUa_FindServersOnNetworkResponse_Initialize
 *===========================================================================*/
void OpcUa_FindServersOnNetworkResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_FindServersOnNetworkResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersOnNetworkResponse_Clear
 *===========================================================================*/
void OpcUa_FindServersOnNetworkResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_FindServersOnNetworkResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_FindServersOnNetworkResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersOnNetworkResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_FindServersOnNetworkResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_FindServersOnNetworkResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_FindServersOnNetworkResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_FindServersOnNetworkResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the FindServersOnNetworkResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor FindServersOnNetworkResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkResponse, LastCounterResetTime) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkResponse, NoOfServers) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServerOnNetwork, // typeIndex
        (uint32_t) offsetof(OpcUa_FindServersOnNetworkResponse, Servers) // offset
    },
};

/*============================================================================
 * Descriptor of the FindServersOnNetworkResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_FindServersOnNetworkResponse_EncodeableType =
{
    "FindServersOnNetworkResponse",
    OpcUaId_FindServersOnNetworkResponse,
    OpcUaId_FindServersOnNetworkResponse_Encoding_DefaultBinary,
    OpcUaId_FindServersOnNetworkResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_FindServersOnNetworkResponse),
    OpcUa_FindServersOnNetworkResponse_Initialize,
    OpcUa_FindServersOnNetworkResponse_Clear,
    NULL,
    OpcUa_FindServersOnNetworkResponse_Encode,
    OpcUa_FindServersOnNetworkResponse_Decode,
    sizeof FindServersOnNetworkResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    FindServersOnNetworkResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_UserTokenPolicy
/*============================================================================
 * OpcUa_UserTokenPolicy_Initialize
 *===========================================================================*/
void OpcUa_UserTokenPolicy_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UserTokenPolicy_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UserTokenPolicy_Clear
 *===========================================================================*/
void OpcUa_UserTokenPolicy_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UserTokenPolicy_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UserTokenPolicy_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UserTokenPolicy_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UserTokenPolicy_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UserTokenPolicy_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UserTokenPolicy_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UserTokenPolicy_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UserTokenPolicy encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UserTokenPolicy_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserTokenPolicy, PolicyId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserTokenPolicy, TokenType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserTokenPolicy, IssuedTokenType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserTokenPolicy, IssuerEndpointUrl) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserTokenPolicy, SecurityPolicyUri) // offset
    },
};

/*============================================================================
 * Descriptor of the UserTokenPolicy encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UserTokenPolicy_EncodeableType =
{
    "UserTokenPolicy",
    OpcUaId_UserTokenPolicy,
    OpcUaId_UserTokenPolicy_Encoding_DefaultBinary,
    OpcUaId_UserTokenPolicy_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UserTokenPolicy),
    OpcUa_UserTokenPolicy_Initialize,
    OpcUa_UserTokenPolicy_Clear,
    NULL,
    OpcUa_UserTokenPolicy_Encode,
    OpcUa_UserTokenPolicy_Decode,
    sizeof UserTokenPolicy_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UserTokenPolicy_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EndpointDescription
/*============================================================================
 * OpcUa_EndpointDescription_Initialize
 *===========================================================================*/
void OpcUa_EndpointDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EndpointDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EndpointDescription_Clear
 *===========================================================================*/
void OpcUa_EndpointDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EndpointDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EndpointDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EndpointDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EndpointDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EndpointDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EndpointDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EndpointDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EndpointDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EndpointDescription_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, EndpointUrl) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ApplicationDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, Server) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, ServerCertificate) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, SecurityMode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, SecurityPolicyUri) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, NoOfUserIdentityTokens) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_UserTokenPolicy, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, UserIdentityTokens) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, TransportProfileUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointDescription, SecurityLevel) // offset
    },
};

/*============================================================================
 * Descriptor of the EndpointDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EndpointDescription_EncodeableType =
{
    "EndpointDescription",
    OpcUaId_EndpointDescription,
    OpcUaId_EndpointDescription_Encoding_DefaultBinary,
    OpcUaId_EndpointDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EndpointDescription),
    OpcUa_EndpointDescription_Initialize,
    OpcUa_EndpointDescription_Clear,
    NULL,
    OpcUa_EndpointDescription_Encode,
    OpcUa_EndpointDescription_Decode,
    sizeof EndpointDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EndpointDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_GetEndpoints
#ifndef OPCUA_EXCLUDE_GetEndpointsRequest
/*============================================================================
 * OpcUa_GetEndpointsRequest_Initialize
 *===========================================================================*/
void OpcUa_GetEndpointsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_GetEndpointsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_GetEndpointsRequest_Clear
 *===========================================================================*/
void OpcUa_GetEndpointsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_GetEndpointsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_GetEndpointsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_GetEndpointsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_GetEndpointsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_GetEndpointsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_GetEndpointsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_GetEndpointsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the GetEndpointsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor GetEndpointsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsRequest, EndpointUrl) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsRequest, NoOfLocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsRequest, LocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsRequest, NoOfProfileUris) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsRequest, ProfileUris) // offset
    },
};

/*============================================================================
 * Descriptor of the GetEndpointsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_GetEndpointsRequest_EncodeableType =
{
    "GetEndpointsRequest",
    OpcUaId_GetEndpointsRequest,
    OpcUaId_GetEndpointsRequest_Encoding_DefaultBinary,
    OpcUaId_GetEndpointsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_GetEndpointsRequest),
    OpcUa_GetEndpointsRequest_Initialize,
    OpcUa_GetEndpointsRequest_Clear,
    NULL,
    OpcUa_GetEndpointsRequest_Encode,
    OpcUa_GetEndpointsRequest_Decode,
    sizeof GetEndpointsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    GetEndpointsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_GetEndpointsResponse
/*============================================================================
 * OpcUa_GetEndpointsResponse_Initialize
 *===========================================================================*/
void OpcUa_GetEndpointsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_GetEndpointsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_GetEndpointsResponse_Clear
 *===========================================================================*/
void OpcUa_GetEndpointsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_GetEndpointsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_GetEndpointsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_GetEndpointsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_GetEndpointsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_GetEndpointsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_GetEndpointsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_GetEndpointsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the GetEndpointsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor GetEndpointsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsResponse, NoOfEndpoints) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EndpointDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_GetEndpointsResponse, Endpoints) // offset
    },
};

/*============================================================================
 * Descriptor of the GetEndpointsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_GetEndpointsResponse_EncodeableType =
{
    "GetEndpointsResponse",
    OpcUaId_GetEndpointsResponse,
    OpcUaId_GetEndpointsResponse_Encoding_DefaultBinary,
    OpcUaId_GetEndpointsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_GetEndpointsResponse),
    OpcUa_GetEndpointsResponse_Initialize,
    OpcUa_GetEndpointsResponse_Clear,
    NULL,
    OpcUa_GetEndpointsResponse_Encode,
    OpcUa_GetEndpointsResponse_Decode,
    sizeof GetEndpointsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    GetEndpointsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_RegisteredServer
/*============================================================================
 * OpcUa_RegisteredServer_Initialize
 *===========================================================================*/
void OpcUa_RegisteredServer_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisteredServer_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisteredServer_Clear
 *===========================================================================*/
void OpcUa_RegisteredServer_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisteredServer_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisteredServer_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisteredServer_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisteredServer_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisteredServer_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisteredServer_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisteredServer_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisteredServer encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisteredServer_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, ServerUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, ProductUri) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, NoOfServerNames) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, ServerNames) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, ServerType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, GatewayServerUri) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, NoOfDiscoveryUrls) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, DiscoveryUrls) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, SemaphoreFilePath) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisteredServer, IsOnline) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisteredServer encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisteredServer_EncodeableType =
{
    "RegisteredServer",
    OpcUaId_RegisteredServer,
    OpcUaId_RegisteredServer_Encoding_DefaultBinary,
    OpcUaId_RegisteredServer_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisteredServer),
    OpcUa_RegisteredServer_Initialize,
    OpcUa_RegisteredServer_Clear,
    NULL,
    OpcUa_RegisteredServer_Encode,
    OpcUa_RegisteredServer_Decode,
    sizeof RegisteredServer_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisteredServer_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RegisterServer
#ifndef OPCUA_EXCLUDE_RegisterServerRequest
/*============================================================================
 * OpcUa_RegisterServerRequest_Initialize
 *===========================================================================*/
void OpcUa_RegisterServerRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisterServerRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServerRequest_Clear
 *===========================================================================*/
void OpcUa_RegisterServerRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisterServerRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServerRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServerRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisterServerRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisterServerRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServerRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisterServerRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisterServerRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisterServerRequest_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_RegisteredServer, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServerRequest, Server) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisterServerRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisterServerRequest_EncodeableType =
{
    "RegisterServerRequest",
    OpcUaId_RegisterServerRequest,
    OpcUaId_RegisterServerRequest_Encoding_DefaultBinary,
    OpcUaId_RegisterServerRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisterServerRequest),
    OpcUa_RegisterServerRequest_Initialize,
    OpcUa_RegisterServerRequest_Clear,
    NULL,
    OpcUa_RegisterServerRequest_Encode,
    OpcUa_RegisterServerRequest_Decode,
    sizeof RegisterServerRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisterServerRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RegisterServerResponse
/*============================================================================
 * OpcUa_RegisterServerResponse_Initialize
 *===========================================================================*/
void OpcUa_RegisterServerResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisterServerResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServerResponse_Clear
 *===========================================================================*/
void OpcUa_RegisterServerResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisterServerResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServerResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServerResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisterServerResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisterServerResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServerResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisterServerResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisterServerResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisterServerResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServerResponse, ResponseHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisterServerResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisterServerResponse_EncodeableType =
{
    "RegisterServerResponse",
    OpcUaId_RegisterServerResponse,
    OpcUaId_RegisterServerResponse_Encoding_DefaultBinary,
    OpcUaId_RegisterServerResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisterServerResponse),
    OpcUa_RegisterServerResponse_Initialize,
    OpcUa_RegisterServerResponse_Clear,
    NULL,
    OpcUa_RegisterServerResponse_Encode,
    OpcUa_RegisterServerResponse_Decode,
    sizeof RegisterServerResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisterServerResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_MdnsDiscoveryConfiguration
/*============================================================================
 * OpcUa_MdnsDiscoveryConfiguration_Initialize
 *===========================================================================*/
void OpcUa_MdnsDiscoveryConfiguration_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MdnsDiscoveryConfiguration_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MdnsDiscoveryConfiguration_Clear
 *===========================================================================*/
void OpcUa_MdnsDiscoveryConfiguration_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MdnsDiscoveryConfiguration_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MdnsDiscoveryConfiguration_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MdnsDiscoveryConfiguration_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MdnsDiscoveryConfiguration_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MdnsDiscoveryConfiguration_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MdnsDiscoveryConfiguration_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MdnsDiscoveryConfiguration_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MdnsDiscoveryConfiguration encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MdnsDiscoveryConfiguration_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MdnsDiscoveryConfiguration, MdnsServerName) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MdnsDiscoveryConfiguration, NoOfServerCapabilities) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MdnsDiscoveryConfiguration, ServerCapabilities) // offset
    },
};

/*============================================================================
 * Descriptor of the MdnsDiscoveryConfiguration encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MdnsDiscoveryConfiguration_EncodeableType =
{
    "MdnsDiscoveryConfiguration",
    OpcUaId_MdnsDiscoveryConfiguration,
    OpcUaId_MdnsDiscoveryConfiguration_Encoding_DefaultBinary,
    OpcUaId_MdnsDiscoveryConfiguration_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MdnsDiscoveryConfiguration),
    OpcUa_MdnsDiscoveryConfiguration_Initialize,
    OpcUa_MdnsDiscoveryConfiguration_Clear,
    NULL,
    OpcUa_MdnsDiscoveryConfiguration_Encode,
    OpcUa_MdnsDiscoveryConfiguration_Decode,
    sizeof MdnsDiscoveryConfiguration_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MdnsDiscoveryConfiguration_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RegisterServer2
#ifndef OPCUA_EXCLUDE_RegisterServer2Request
/*============================================================================
 * OpcUa_RegisterServer2Request_Initialize
 *===========================================================================*/
void OpcUa_RegisterServer2Request_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisterServer2Request_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServer2Request_Clear
 *===========================================================================*/
void OpcUa_RegisterServer2Request_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisterServer2Request_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServer2Request_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServer2Request_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisterServer2Request_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisterServer2Request_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServer2Request_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisterServer2Request_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisterServer2Request encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisterServer2Request_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_RegisteredServer, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Request, Server) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Request, NoOfDiscoveryConfiguration) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Request, DiscoveryConfiguration) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisterServer2Request encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisterServer2Request_EncodeableType =
{
    "RegisterServer2Request",
    OpcUaId_RegisterServer2Request,
    OpcUaId_RegisterServer2Request_Encoding_DefaultBinary,
    OpcUaId_RegisterServer2Request_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisterServer2Request),
    OpcUa_RegisterServer2Request_Initialize,
    OpcUa_RegisterServer2Request_Clear,
    NULL,
    OpcUa_RegisterServer2Request_Encode,
    OpcUa_RegisterServer2Request_Decode,
    sizeof RegisterServer2Request_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisterServer2Request_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RegisterServer2Response
/*============================================================================
 * OpcUa_RegisterServer2Response_Initialize
 *===========================================================================*/
void OpcUa_RegisterServer2Response_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisterServer2Response_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServer2Response_Clear
 *===========================================================================*/
void OpcUa_RegisterServer2Response_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisterServer2Response_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterServer2Response_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServer2Response_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisterServer2Response_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisterServer2Response_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterServer2Response_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisterServer2Response_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisterServer2Response encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisterServer2Response_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Response, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Response, NoOfConfigurationResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Response, ConfigurationResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Response, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterServer2Response, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisterServer2Response encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisterServer2Response_EncodeableType =
{
    "RegisterServer2Response",
    OpcUaId_RegisterServer2Response,
    OpcUaId_RegisterServer2Response_Encoding_DefaultBinary,
    OpcUaId_RegisterServer2Response_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisterServer2Response),
    OpcUa_RegisterServer2Response_Initialize,
    OpcUa_RegisterServer2Response_Clear,
    NULL,
    OpcUa_RegisterServer2Response_Encode,
    OpcUa_RegisterServer2Response_Decode,
    sizeof RegisterServer2Response_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisterServer2Response_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_ChannelSecurityToken
/*============================================================================
 * OpcUa_ChannelSecurityToken_Initialize
 *===========================================================================*/
void OpcUa_ChannelSecurityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ChannelSecurityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ChannelSecurityToken_Clear
 *===========================================================================*/
void OpcUa_ChannelSecurityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ChannelSecurityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ChannelSecurityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ChannelSecurityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ChannelSecurityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ChannelSecurityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ChannelSecurityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ChannelSecurityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ChannelSecurityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ChannelSecurityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ChannelSecurityToken, ChannelId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ChannelSecurityToken, TokenId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ChannelSecurityToken, CreatedAt) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ChannelSecurityToken, RevisedLifetime) // offset
    },
};

/*============================================================================
 * Descriptor of the ChannelSecurityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ChannelSecurityToken_EncodeableType =
{
    "ChannelSecurityToken",
    OpcUaId_ChannelSecurityToken,
    OpcUaId_ChannelSecurityToken_Encoding_DefaultBinary,
    OpcUaId_ChannelSecurityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ChannelSecurityToken),
    OpcUa_ChannelSecurityToken_Initialize,
    OpcUa_ChannelSecurityToken_Clear,
    NULL,
    OpcUa_ChannelSecurityToken_Encode,
    OpcUa_ChannelSecurityToken_Decode,
    sizeof ChannelSecurityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ChannelSecurityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_OpenSecureChannel
#ifndef OPCUA_EXCLUDE_OpenSecureChannelRequest
/*============================================================================
 * OpcUa_OpenSecureChannelRequest_Initialize
 *===========================================================================*/
void OpcUa_OpenSecureChannelRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_OpenSecureChannelRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_OpenSecureChannelRequest_Clear
 *===========================================================================*/
void OpcUa_OpenSecureChannelRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_OpenSecureChannelRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_OpenSecureChannelRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_OpenSecureChannelRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_OpenSecureChannelRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_OpenSecureChannelRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_OpenSecureChannelRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_OpenSecureChannelRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the OpenSecureChannelRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor OpenSecureChannelRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelRequest, ClientProtocolVersion) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelRequest, RequestType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelRequest, SecurityMode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelRequest, ClientNonce) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelRequest, RequestedLifetime) // offset
    },
};

/*============================================================================
 * Descriptor of the OpenSecureChannelRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_OpenSecureChannelRequest_EncodeableType =
{
    "OpenSecureChannelRequest",
    OpcUaId_OpenSecureChannelRequest,
    OpcUaId_OpenSecureChannelRequest_Encoding_DefaultBinary,
    OpcUaId_OpenSecureChannelRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_OpenSecureChannelRequest),
    OpcUa_OpenSecureChannelRequest_Initialize,
    OpcUa_OpenSecureChannelRequest_Clear,
    NULL,
    OpcUa_OpenSecureChannelRequest_Encode,
    OpcUa_OpenSecureChannelRequest_Decode,
    sizeof OpenSecureChannelRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    OpenSecureChannelRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_OpenSecureChannelResponse
/*============================================================================
 * OpcUa_OpenSecureChannelResponse_Initialize
 *===========================================================================*/
void OpcUa_OpenSecureChannelResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_OpenSecureChannelResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_OpenSecureChannelResponse_Clear
 *===========================================================================*/
void OpcUa_OpenSecureChannelResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_OpenSecureChannelResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_OpenSecureChannelResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_OpenSecureChannelResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_OpenSecureChannelResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_OpenSecureChannelResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_OpenSecureChannelResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_OpenSecureChannelResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the OpenSecureChannelResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor OpenSecureChannelResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelResponse, ServerProtocolVersion) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ChannelSecurityToken, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelResponse, SecurityToken) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_OpenSecureChannelResponse, ServerNonce) // offset
    },
};

/*============================================================================
 * Descriptor of the OpenSecureChannelResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_OpenSecureChannelResponse_EncodeableType =
{
    "OpenSecureChannelResponse",
    OpcUaId_OpenSecureChannelResponse,
    OpcUaId_OpenSecureChannelResponse_Encoding_DefaultBinary,
    OpcUaId_OpenSecureChannelResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_OpenSecureChannelResponse),
    OpcUa_OpenSecureChannelResponse_Initialize,
    OpcUa_OpenSecureChannelResponse_Clear,
    NULL,
    OpcUa_OpenSecureChannelResponse_Encode,
    OpcUa_OpenSecureChannelResponse_Decode,
    sizeof OpenSecureChannelResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    OpenSecureChannelResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_CloseSecureChannel
#ifndef OPCUA_EXCLUDE_CloseSecureChannelRequest
/*============================================================================
 * OpcUa_CloseSecureChannelRequest_Initialize
 *===========================================================================*/
void OpcUa_CloseSecureChannelRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CloseSecureChannelRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSecureChannelRequest_Clear
 *===========================================================================*/
void OpcUa_CloseSecureChannelRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CloseSecureChannelRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSecureChannelRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSecureChannelRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CloseSecureChannelRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CloseSecureChannelRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSecureChannelRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CloseSecureChannelRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Descriptor of the CloseSecureChannelRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CloseSecureChannelRequest_EncodeableType =
{
    "CloseSecureChannelRequest",
    OpcUaId_CloseSecureChannelRequest,
    OpcUaId_CloseSecureChannelRequest_Encoding_DefaultBinary,
    OpcUaId_CloseSecureChannelRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CloseSecureChannelRequest),
    OpcUa_CloseSecureChannelRequest_Initialize,
    OpcUa_CloseSecureChannelRequest_Clear,
    NULL,
    OpcUa_CloseSecureChannelRequest_Encode,
    OpcUa_CloseSecureChannelRequest_Decode,
    0,
    NULL
};
#endif

#ifndef OPCUA_EXCLUDE_CloseSecureChannelResponse
/*============================================================================
 * OpcUa_CloseSecureChannelResponse_Initialize
 *===========================================================================*/
void OpcUa_CloseSecureChannelResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CloseSecureChannelResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSecureChannelResponse_Clear
 *===========================================================================*/
void OpcUa_CloseSecureChannelResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CloseSecureChannelResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSecureChannelResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSecureChannelResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CloseSecureChannelResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CloseSecureChannelResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSecureChannelResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CloseSecureChannelResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CloseSecureChannelResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CloseSecureChannelResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CloseSecureChannelResponse, ResponseHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the CloseSecureChannelResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CloseSecureChannelResponse_EncodeableType =
{
    "CloseSecureChannelResponse",
    OpcUaId_CloseSecureChannelResponse,
    OpcUaId_CloseSecureChannelResponse_Encoding_DefaultBinary,
    OpcUaId_CloseSecureChannelResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CloseSecureChannelResponse),
    OpcUa_CloseSecureChannelResponse_Initialize,
    OpcUa_CloseSecureChannelResponse_Clear,
    NULL,
    OpcUa_CloseSecureChannelResponse_Encode,
    OpcUa_CloseSecureChannelResponse_Decode,
    sizeof CloseSecureChannelResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CloseSecureChannelResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_SignedSoftwareCertificate
/*============================================================================
 * OpcUa_SignedSoftwareCertificate_Initialize
 *===========================================================================*/
void OpcUa_SignedSoftwareCertificate_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SignedSoftwareCertificate_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SignedSoftwareCertificate_Clear
 *===========================================================================*/
void OpcUa_SignedSoftwareCertificate_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SignedSoftwareCertificate_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SignedSoftwareCertificate_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SignedSoftwareCertificate_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SignedSoftwareCertificate_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SignedSoftwareCertificate_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SignedSoftwareCertificate_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SignedSoftwareCertificate_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SignedSoftwareCertificate encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SignedSoftwareCertificate_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SignedSoftwareCertificate, CertificateData) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SignedSoftwareCertificate, Signature) // offset
    },
};

/*============================================================================
 * Descriptor of the SignedSoftwareCertificate encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SignedSoftwareCertificate_EncodeableType =
{
    "SignedSoftwareCertificate",
    OpcUaId_SignedSoftwareCertificate,
    OpcUaId_SignedSoftwareCertificate_Encoding_DefaultBinary,
    OpcUaId_SignedSoftwareCertificate_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SignedSoftwareCertificate),
    OpcUa_SignedSoftwareCertificate_Initialize,
    OpcUa_SignedSoftwareCertificate_Clear,
    NULL,
    OpcUa_SignedSoftwareCertificate_Encode,
    OpcUa_SignedSoftwareCertificate_Decode,
    sizeof SignedSoftwareCertificate_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SignedSoftwareCertificate_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SignatureData
/*============================================================================
 * OpcUa_SignatureData_Initialize
 *===========================================================================*/
void OpcUa_SignatureData_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SignatureData_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SignatureData_Clear
 *===========================================================================*/
void OpcUa_SignatureData_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SignatureData_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SignatureData_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SignatureData_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SignatureData_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SignatureData_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SignatureData_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SignatureData_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SignatureData encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SignatureData_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SignatureData, Algorithm) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SignatureData, Signature) // offset
    },
};

/*============================================================================
 * Descriptor of the SignatureData encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SignatureData_EncodeableType =
{
    "SignatureData",
    OpcUaId_SignatureData,
    OpcUaId_SignatureData_Encoding_DefaultBinary,
    OpcUaId_SignatureData_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SignatureData),
    OpcUa_SignatureData_Initialize,
    OpcUa_SignatureData_Clear,
    NULL,
    OpcUa_SignatureData_Encode,
    OpcUa_SignatureData_Decode,
    sizeof SignatureData_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SignatureData_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CreateSession
#ifndef OPCUA_EXCLUDE_CreateSessionRequest
/*============================================================================
 * OpcUa_CreateSessionRequest_Initialize
 *===========================================================================*/
void OpcUa_CreateSessionRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CreateSessionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSessionRequest_Clear
 *===========================================================================*/
void OpcUa_CreateSessionRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CreateSessionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSessionRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSessionRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CreateSessionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CreateSessionRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSessionRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CreateSessionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CreateSessionRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CreateSessionRequest_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ApplicationDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, ClientDescription) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, ServerUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, EndpointUrl) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, SessionName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, ClientNonce) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, ClientCertificate) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, RequestedSessionTimeout) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionRequest, MaxResponseMessageSize) // offset
    },
};

/*============================================================================
 * Descriptor of the CreateSessionRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CreateSessionRequest_EncodeableType =
{
    "CreateSessionRequest",
    OpcUaId_CreateSessionRequest,
    OpcUaId_CreateSessionRequest_Encoding_DefaultBinary,
    OpcUaId_CreateSessionRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CreateSessionRequest),
    OpcUa_CreateSessionRequest_Initialize,
    OpcUa_CreateSessionRequest_Clear,
    NULL,
    OpcUa_CreateSessionRequest_Encode,
    OpcUa_CreateSessionRequest_Decode,
    sizeof CreateSessionRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CreateSessionRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CreateSessionResponse
/*============================================================================
 * OpcUa_CreateSessionResponse_Initialize
 *===========================================================================*/
void OpcUa_CreateSessionResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CreateSessionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSessionResponse_Clear
 *===========================================================================*/
void OpcUa_CreateSessionResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CreateSessionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSessionResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSessionResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CreateSessionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CreateSessionResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSessionResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CreateSessionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CreateSessionResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CreateSessionResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, SessionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, AuthenticationToken) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, RevisedSessionTimeout) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, ServerNonce) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, ServerCertificate) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, NoOfServerEndpoints) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EndpointDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, ServerEndpoints) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, NoOfServerSoftwareCertificates) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SignedSoftwareCertificate, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, ServerSoftwareCertificates) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SignatureData, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, ServerSignature) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSessionResponse, MaxRequestMessageSize) // offset
    },
};

/*============================================================================
 * Descriptor of the CreateSessionResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CreateSessionResponse_EncodeableType =
{
    "CreateSessionResponse",
    OpcUaId_CreateSessionResponse,
    OpcUaId_CreateSessionResponse_Encoding_DefaultBinary,
    OpcUaId_CreateSessionResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CreateSessionResponse),
    OpcUa_CreateSessionResponse_Initialize,
    OpcUa_CreateSessionResponse_Clear,
    NULL,
    OpcUa_CreateSessionResponse_Encode,
    OpcUa_CreateSessionResponse_Decode,
    sizeof CreateSessionResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CreateSessionResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_UserIdentityToken
/*============================================================================
 * OpcUa_UserIdentityToken_Initialize
 *===========================================================================*/
void OpcUa_UserIdentityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UserIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UserIdentityToken_Clear
 *===========================================================================*/
void OpcUa_UserIdentityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UserIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UserIdentityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UserIdentityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UserIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UserIdentityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UserIdentityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UserIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UserIdentityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UserIdentityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserIdentityToken, PolicyId) // offset
    },
};

/*============================================================================
 * Descriptor of the UserIdentityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UserIdentityToken_EncodeableType =
{
    "UserIdentityToken",
    OpcUaId_UserIdentityToken,
    OpcUaId_UserIdentityToken_Encoding_DefaultBinary,
    OpcUaId_UserIdentityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UserIdentityToken),
    OpcUa_UserIdentityToken_Initialize,
    OpcUa_UserIdentityToken_Clear,
    NULL,
    OpcUa_UserIdentityToken_Encode,
    OpcUa_UserIdentityToken_Decode,
    sizeof UserIdentityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UserIdentityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AnonymousIdentityToken
/*============================================================================
 * OpcUa_AnonymousIdentityToken_Initialize
 *===========================================================================*/
void OpcUa_AnonymousIdentityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AnonymousIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AnonymousIdentityToken_Clear
 *===========================================================================*/
void OpcUa_AnonymousIdentityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AnonymousIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AnonymousIdentityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AnonymousIdentityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AnonymousIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AnonymousIdentityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AnonymousIdentityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AnonymousIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AnonymousIdentityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AnonymousIdentityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AnonymousIdentityToken, PolicyId) // offset
    },
};

/*============================================================================
 * Descriptor of the AnonymousIdentityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AnonymousIdentityToken_EncodeableType =
{
    "AnonymousIdentityToken",
    OpcUaId_AnonymousIdentityToken,
    OpcUaId_AnonymousIdentityToken_Encoding_DefaultBinary,
    OpcUaId_AnonymousIdentityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AnonymousIdentityToken),
    OpcUa_AnonymousIdentityToken_Initialize,
    OpcUa_AnonymousIdentityToken_Clear,
    NULL,
    OpcUa_AnonymousIdentityToken_Encode,
    OpcUa_AnonymousIdentityToken_Decode,
    sizeof AnonymousIdentityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AnonymousIdentityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_UserNameIdentityToken
/*============================================================================
 * OpcUa_UserNameIdentityToken_Initialize
 *===========================================================================*/
void OpcUa_UserNameIdentityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UserNameIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UserNameIdentityToken_Clear
 *===========================================================================*/
void OpcUa_UserNameIdentityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UserNameIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UserNameIdentityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UserNameIdentityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UserNameIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UserNameIdentityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UserNameIdentityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UserNameIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UserNameIdentityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UserNameIdentityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserNameIdentityToken, PolicyId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserNameIdentityToken, UserName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserNameIdentityToken, Password) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UserNameIdentityToken, EncryptionAlgorithm) // offset
    },
};

/*============================================================================
 * Descriptor of the UserNameIdentityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UserNameIdentityToken_EncodeableType =
{
    "UserNameIdentityToken",
    OpcUaId_UserNameIdentityToken,
    OpcUaId_UserNameIdentityToken_Encoding_DefaultBinary,
    OpcUaId_UserNameIdentityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UserNameIdentityToken),
    OpcUa_UserNameIdentityToken_Initialize,
    OpcUa_UserNameIdentityToken_Clear,
    NULL,
    OpcUa_UserNameIdentityToken_Encode,
    OpcUa_UserNameIdentityToken_Decode,
    sizeof UserNameIdentityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UserNameIdentityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_X509IdentityToken
/*============================================================================
 * OpcUa_X509IdentityToken_Initialize
 *===========================================================================*/
void OpcUa_X509IdentityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_X509IdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_X509IdentityToken_Clear
 *===========================================================================*/
void OpcUa_X509IdentityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_X509IdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_X509IdentityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_X509IdentityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_X509IdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_X509IdentityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_X509IdentityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_X509IdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the X509IdentityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor X509IdentityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_X509IdentityToken, PolicyId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_X509IdentityToken, CertificateData) // offset
    },
};

/*============================================================================
 * Descriptor of the X509IdentityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_X509IdentityToken_EncodeableType =
{
    "X509IdentityToken",
    OpcUaId_X509IdentityToken,
    OpcUaId_X509IdentityToken_Encoding_DefaultBinary,
    OpcUaId_X509IdentityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_X509IdentityToken),
    OpcUa_X509IdentityToken_Initialize,
    OpcUa_X509IdentityToken_Clear,
    NULL,
    OpcUa_X509IdentityToken_Encode,
    OpcUa_X509IdentityToken_Decode,
    sizeof X509IdentityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    X509IdentityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_KerberosIdentityToken
/*============================================================================
 * OpcUa_KerberosIdentityToken_Initialize
 *===========================================================================*/
void OpcUa_KerberosIdentityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_KerberosIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_KerberosIdentityToken_Clear
 *===========================================================================*/
void OpcUa_KerberosIdentityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_KerberosIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_KerberosIdentityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_KerberosIdentityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_KerberosIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_KerberosIdentityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_KerberosIdentityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_KerberosIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the KerberosIdentityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor KerberosIdentityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_KerberosIdentityToken, PolicyId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_KerberosIdentityToken, TicketData) // offset
    },
};

/*============================================================================
 * Descriptor of the KerberosIdentityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_KerberosIdentityToken_EncodeableType =
{
    "KerberosIdentityToken",
    OpcUaId_KerberosIdentityToken,
    OpcUaId_KerberosIdentityToken_Encoding_DefaultBinary,
    OpcUaId_KerberosIdentityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_KerberosIdentityToken),
    OpcUa_KerberosIdentityToken_Initialize,
    OpcUa_KerberosIdentityToken_Clear,
    NULL,
    OpcUa_KerberosIdentityToken_Encode,
    OpcUa_KerberosIdentityToken_Decode,
    sizeof KerberosIdentityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    KerberosIdentityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_IssuedIdentityToken
/*============================================================================
 * OpcUa_IssuedIdentityToken_Initialize
 *===========================================================================*/
void OpcUa_IssuedIdentityToken_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_IssuedIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_IssuedIdentityToken_Clear
 *===========================================================================*/
void OpcUa_IssuedIdentityToken_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_IssuedIdentityToken_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_IssuedIdentityToken_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_IssuedIdentityToken_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_IssuedIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_IssuedIdentityToken_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_IssuedIdentityToken_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_IssuedIdentityToken_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the IssuedIdentityToken encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor IssuedIdentityToken_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_IssuedIdentityToken, PolicyId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_IssuedIdentityToken, TokenData) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_IssuedIdentityToken, EncryptionAlgorithm) // offset
    },
};

/*============================================================================
 * Descriptor of the IssuedIdentityToken encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_IssuedIdentityToken_EncodeableType =
{
    "IssuedIdentityToken",
    OpcUaId_IssuedIdentityToken,
    OpcUaId_IssuedIdentityToken_Encoding_DefaultBinary,
    OpcUaId_IssuedIdentityToken_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_IssuedIdentityToken),
    OpcUa_IssuedIdentityToken_Initialize,
    OpcUa_IssuedIdentityToken_Clear,
    NULL,
    OpcUa_IssuedIdentityToken_Encode,
    OpcUa_IssuedIdentityToken_Decode,
    sizeof IssuedIdentityToken_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    IssuedIdentityToken_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ActivateSession
#ifndef OPCUA_EXCLUDE_ActivateSessionRequest
/*============================================================================
 * OpcUa_ActivateSessionRequest_Initialize
 *===========================================================================*/
void OpcUa_ActivateSessionRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ActivateSessionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ActivateSessionRequest_Clear
 *===========================================================================*/
void OpcUa_ActivateSessionRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ActivateSessionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ActivateSessionRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ActivateSessionRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ActivateSessionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ActivateSessionRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ActivateSessionRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ActivateSessionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ActivateSessionRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ActivateSessionRequest_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SignatureData, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, ClientSignature) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, NoOfClientSoftwareCertificates) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SignedSoftwareCertificate, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, ClientSoftwareCertificates) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, NoOfLocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, LocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, UserIdentityToken) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SignatureData, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionRequest, UserTokenSignature) // offset
    },
};

/*============================================================================
 * Descriptor of the ActivateSessionRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ActivateSessionRequest_EncodeableType =
{
    "ActivateSessionRequest",
    OpcUaId_ActivateSessionRequest,
    OpcUaId_ActivateSessionRequest_Encoding_DefaultBinary,
    OpcUaId_ActivateSessionRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ActivateSessionRequest),
    OpcUa_ActivateSessionRequest_Initialize,
    OpcUa_ActivateSessionRequest_Clear,
    NULL,
    OpcUa_ActivateSessionRequest_Encode,
    OpcUa_ActivateSessionRequest_Decode,
    sizeof ActivateSessionRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ActivateSessionRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ActivateSessionResponse
/*============================================================================
 * OpcUa_ActivateSessionResponse_Initialize
 *===========================================================================*/
void OpcUa_ActivateSessionResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ActivateSessionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ActivateSessionResponse_Clear
 *===========================================================================*/
void OpcUa_ActivateSessionResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ActivateSessionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ActivateSessionResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ActivateSessionResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ActivateSessionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ActivateSessionResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ActivateSessionResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ActivateSessionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ActivateSessionResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ActivateSessionResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionResponse, ServerNonce) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ActivateSessionResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the ActivateSessionResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ActivateSessionResponse_EncodeableType =
{
    "ActivateSessionResponse",
    OpcUaId_ActivateSessionResponse,
    OpcUaId_ActivateSessionResponse_Encoding_DefaultBinary,
    OpcUaId_ActivateSessionResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ActivateSessionResponse),
    OpcUa_ActivateSessionResponse_Initialize,
    OpcUa_ActivateSessionResponse_Clear,
    NULL,
    OpcUa_ActivateSessionResponse_Encode,
    OpcUa_ActivateSessionResponse_Decode,
    sizeof ActivateSessionResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ActivateSessionResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_CloseSession
#ifndef OPCUA_EXCLUDE_CloseSessionRequest
/*============================================================================
 * OpcUa_CloseSessionRequest_Initialize
 *===========================================================================*/
void OpcUa_CloseSessionRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CloseSessionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSessionRequest_Clear
 *===========================================================================*/
void OpcUa_CloseSessionRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CloseSessionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSessionRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSessionRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CloseSessionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CloseSessionRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSessionRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CloseSessionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CloseSessionRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CloseSessionRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CloseSessionRequest, DeleteSubscriptions) // offset
    },
};

/*============================================================================
 * Descriptor of the CloseSessionRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CloseSessionRequest_EncodeableType =
{
    "CloseSessionRequest",
    OpcUaId_CloseSessionRequest,
    OpcUaId_CloseSessionRequest_Encoding_DefaultBinary,
    OpcUaId_CloseSessionRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CloseSessionRequest),
    OpcUa_CloseSessionRequest_Initialize,
    OpcUa_CloseSessionRequest_Clear,
    NULL,
    OpcUa_CloseSessionRequest_Encode,
    OpcUa_CloseSessionRequest_Decode,
    sizeof CloseSessionRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CloseSessionRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CloseSessionResponse
/*============================================================================
 * OpcUa_CloseSessionResponse_Initialize
 *===========================================================================*/
void OpcUa_CloseSessionResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CloseSessionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSessionResponse_Clear
 *===========================================================================*/
void OpcUa_CloseSessionResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CloseSessionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CloseSessionResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSessionResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CloseSessionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CloseSessionResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CloseSessionResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CloseSessionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CloseSessionResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CloseSessionResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CloseSessionResponse, ResponseHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the CloseSessionResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CloseSessionResponse_EncodeableType =
{
    "CloseSessionResponse",
    OpcUaId_CloseSessionResponse,
    OpcUaId_CloseSessionResponse_Encoding_DefaultBinary,
    OpcUaId_CloseSessionResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CloseSessionResponse),
    OpcUa_CloseSessionResponse_Initialize,
    OpcUa_CloseSessionResponse_Clear,
    NULL,
    OpcUa_CloseSessionResponse_Encode,
    OpcUa_CloseSessionResponse_Decode,
    sizeof CloseSessionResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CloseSessionResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_Cancel
#ifndef OPCUA_EXCLUDE_CancelRequest
/*============================================================================
 * OpcUa_CancelRequest_Initialize
 *===========================================================================*/
void OpcUa_CancelRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CancelRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CancelRequest_Clear
 *===========================================================================*/
void OpcUa_CancelRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CancelRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CancelRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CancelRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CancelRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CancelRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CancelRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CancelRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CancelRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CancelRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CancelRequest, RequestHandle) // offset
    },
};

/*============================================================================
 * Descriptor of the CancelRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CancelRequest_EncodeableType =
{
    "CancelRequest",
    OpcUaId_CancelRequest,
    OpcUaId_CancelRequest_Encoding_DefaultBinary,
    OpcUaId_CancelRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CancelRequest),
    OpcUa_CancelRequest_Initialize,
    OpcUa_CancelRequest_Clear,
    NULL,
    OpcUa_CancelRequest_Encode,
    OpcUa_CancelRequest_Decode,
    sizeof CancelRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CancelRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CancelResponse
/*============================================================================
 * OpcUa_CancelResponse_Initialize
 *===========================================================================*/
void OpcUa_CancelResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CancelResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CancelResponse_Clear
 *===========================================================================*/
void OpcUa_CancelResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CancelResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CancelResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CancelResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CancelResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CancelResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CancelResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CancelResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CancelResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CancelResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CancelResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CancelResponse, CancelCount) // offset
    },
};

/*============================================================================
 * Descriptor of the CancelResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CancelResponse_EncodeableType =
{
    "CancelResponse",
    OpcUaId_CancelResponse,
    OpcUaId_CancelResponse_Encoding_DefaultBinary,
    OpcUaId_CancelResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CancelResponse),
    OpcUa_CancelResponse_Initialize,
    OpcUa_CancelResponse_Clear,
    NULL,
    OpcUa_CancelResponse_Encode,
    OpcUa_CancelResponse_Decode,
    sizeof CancelResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CancelResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_NodeAttributes
/*============================================================================
 * OpcUa_NodeAttributes_Initialize
 *===========================================================================*/
void OpcUa_NodeAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_NodeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NodeAttributes_Clear
 *===========================================================================*/
void OpcUa_NodeAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_NodeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NodeAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NodeAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_NodeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_NodeAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NodeAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_NodeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the NodeAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor NodeAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeAttributes, UserWriteMask) // offset
    },
};

/*============================================================================
 * Descriptor of the NodeAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_NodeAttributes_EncodeableType =
{
    "NodeAttributes",
    OpcUaId_NodeAttributes,
    OpcUaId_NodeAttributes_Encoding_DefaultBinary,
    OpcUaId_NodeAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_NodeAttributes),
    OpcUa_NodeAttributes_Initialize,
    OpcUa_NodeAttributes_Clear,
    NULL,
    OpcUa_NodeAttributes_Encode,
    OpcUa_NodeAttributes_Decode,
    sizeof NodeAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    NodeAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ObjectAttributes
/*============================================================================
 * OpcUa_ObjectAttributes_Initialize
 *===========================================================================*/
void OpcUa_ObjectAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ObjectAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectAttributes_Clear
 *===========================================================================*/
void OpcUa_ObjectAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ObjectAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ObjectAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ObjectAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ObjectAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ObjectAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ObjectAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectAttributes, EventNotifier) // offset
    },
};

/*============================================================================
 * Descriptor of the ObjectAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ObjectAttributes_EncodeableType =
{
    "ObjectAttributes",
    OpcUaId_ObjectAttributes,
    OpcUaId_ObjectAttributes_Encoding_DefaultBinary,
    OpcUaId_ObjectAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ObjectAttributes),
    OpcUa_ObjectAttributes_Initialize,
    OpcUa_ObjectAttributes_Clear,
    NULL,
    OpcUa_ObjectAttributes_Encode,
    OpcUa_ObjectAttributes_Decode,
    sizeof ObjectAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ObjectAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_VariableAttributes
/*============================================================================
 * OpcUa_VariableAttributes_Initialize
 *===========================================================================*/
void OpcUa_VariableAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_VariableAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableAttributes_Clear
 *===========================================================================*/
void OpcUa_VariableAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_VariableAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_VariableAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_VariableAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_VariableAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the VariableAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor VariableAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, DataType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, ValueRank) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, NoOfArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, ArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, AccessLevel) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, UserAccessLevel) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, MinimumSamplingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableAttributes, Historizing) // offset
    },
};

/*============================================================================
 * Descriptor of the VariableAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_VariableAttributes_EncodeableType =
{
    "VariableAttributes",
    OpcUaId_VariableAttributes,
    OpcUaId_VariableAttributes_Encoding_DefaultBinary,
    OpcUaId_VariableAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_VariableAttributes),
    OpcUa_VariableAttributes_Initialize,
    OpcUa_VariableAttributes_Clear,
    NULL,
    OpcUa_VariableAttributes_Encode,
    OpcUa_VariableAttributes_Decode,
    sizeof VariableAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    VariableAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MethodAttributes
/*============================================================================
 * OpcUa_MethodAttributes_Initialize
 *===========================================================================*/
void OpcUa_MethodAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MethodAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MethodAttributes_Clear
 *===========================================================================*/
void OpcUa_MethodAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MethodAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MethodAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MethodAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MethodAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MethodAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MethodAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MethodAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MethodAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MethodAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, Executable) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MethodAttributes, UserExecutable) // offset
    },
};

/*============================================================================
 * Descriptor of the MethodAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MethodAttributes_EncodeableType =
{
    "MethodAttributes",
    OpcUaId_MethodAttributes,
    OpcUaId_MethodAttributes_Encoding_DefaultBinary,
    OpcUaId_MethodAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MethodAttributes),
    OpcUa_MethodAttributes_Initialize,
    OpcUa_MethodAttributes_Clear,
    NULL,
    OpcUa_MethodAttributes_Encode,
    OpcUa_MethodAttributes_Decode,
    sizeof MethodAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MethodAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ObjectTypeAttributes
/*============================================================================
 * OpcUa_ObjectTypeAttributes_Initialize
 *===========================================================================*/
void OpcUa_ObjectTypeAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ObjectTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectTypeAttributes_Clear
 *===========================================================================*/
void OpcUa_ObjectTypeAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ObjectTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ObjectTypeAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectTypeAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ObjectTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ObjectTypeAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ObjectTypeAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ObjectTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ObjectTypeAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ObjectTypeAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ObjectTypeAttributes, IsAbstract) // offset
    },
};

/*============================================================================
 * Descriptor of the ObjectTypeAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ObjectTypeAttributes_EncodeableType =
{
    "ObjectTypeAttributes",
    OpcUaId_ObjectTypeAttributes,
    OpcUaId_ObjectTypeAttributes_Encoding_DefaultBinary,
    OpcUaId_ObjectTypeAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ObjectTypeAttributes),
    OpcUa_ObjectTypeAttributes_Initialize,
    OpcUa_ObjectTypeAttributes_Clear,
    NULL,
    OpcUa_ObjectTypeAttributes_Encode,
    OpcUa_ObjectTypeAttributes_Decode,
    sizeof ObjectTypeAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ObjectTypeAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_VariableTypeAttributes
/*============================================================================
 * OpcUa_VariableTypeAttributes_Initialize
 *===========================================================================*/
void OpcUa_VariableTypeAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_VariableTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableTypeAttributes_Clear
 *===========================================================================*/
void OpcUa_VariableTypeAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_VariableTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_VariableTypeAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableTypeAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_VariableTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_VariableTypeAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_VariableTypeAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_VariableTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the VariableTypeAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor VariableTypeAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, Value) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, DataType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, ValueRank) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, NoOfArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, ArrayDimensions) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_VariableTypeAttributes, IsAbstract) // offset
    },
};

/*============================================================================
 * Descriptor of the VariableTypeAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_VariableTypeAttributes_EncodeableType =
{
    "VariableTypeAttributes",
    OpcUaId_VariableTypeAttributes,
    OpcUaId_VariableTypeAttributes_Encoding_DefaultBinary,
    OpcUaId_VariableTypeAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_VariableTypeAttributes),
    OpcUa_VariableTypeAttributes_Initialize,
    OpcUa_VariableTypeAttributes_Clear,
    NULL,
    OpcUa_VariableTypeAttributes_Encode,
    OpcUa_VariableTypeAttributes_Decode,
    sizeof VariableTypeAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    VariableTypeAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReferenceTypeAttributes
/*============================================================================
 * OpcUa_ReferenceTypeAttributes_Initialize
 *===========================================================================*/
void OpcUa_ReferenceTypeAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReferenceTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceTypeAttributes_Clear
 *===========================================================================*/
void OpcUa_ReferenceTypeAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReferenceTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceTypeAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceTypeAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReferenceTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReferenceTypeAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceTypeAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReferenceTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReferenceTypeAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReferenceTypeAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, IsAbstract) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, Symmetric) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceTypeAttributes, InverseName) // offset
    },
};

/*============================================================================
 * Descriptor of the ReferenceTypeAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReferenceTypeAttributes_EncodeableType =
{
    "ReferenceTypeAttributes",
    OpcUaId_ReferenceTypeAttributes,
    OpcUaId_ReferenceTypeAttributes_Encoding_DefaultBinary,
    OpcUaId_ReferenceTypeAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReferenceTypeAttributes),
    OpcUa_ReferenceTypeAttributes_Initialize,
    OpcUa_ReferenceTypeAttributes_Clear,
    NULL,
    OpcUa_ReferenceTypeAttributes_Encode,
    OpcUa_ReferenceTypeAttributes_Decode,
    sizeof ReferenceTypeAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReferenceTypeAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DataTypeAttributes
/*============================================================================
 * OpcUa_DataTypeAttributes_Initialize
 *===========================================================================*/
void OpcUa_DataTypeAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DataTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataTypeAttributes_Clear
 *===========================================================================*/
void OpcUa_DataTypeAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DataTypeAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataTypeAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataTypeAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DataTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DataTypeAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataTypeAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DataTypeAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DataTypeAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DataTypeAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataTypeAttributes, IsAbstract) // offset
    },
};

/*============================================================================
 * Descriptor of the DataTypeAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DataTypeAttributes_EncodeableType =
{
    "DataTypeAttributes",
    OpcUaId_DataTypeAttributes,
    OpcUaId_DataTypeAttributes_Encoding_DefaultBinary,
    OpcUaId_DataTypeAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DataTypeAttributes),
    OpcUa_DataTypeAttributes_Initialize,
    OpcUa_DataTypeAttributes_Clear,
    NULL,
    OpcUa_DataTypeAttributes_Encode,
    OpcUa_DataTypeAttributes_Decode,
    sizeof DataTypeAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DataTypeAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ViewAttributes
/*============================================================================
 * OpcUa_ViewAttributes_Initialize
 *===========================================================================*/
void OpcUa_ViewAttributes_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ViewAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ViewAttributes_Clear
 *===========================================================================*/
void OpcUa_ViewAttributes_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ViewAttributes_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ViewAttributes_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ViewAttributes_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ViewAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ViewAttributes_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ViewAttributes_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ViewAttributes_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ViewAttributes encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ViewAttributes_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, SpecifiedAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, Description) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, WriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, UserWriteMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, ContainsNoLoops) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewAttributes, EventNotifier) // offset
    },
};

/*============================================================================
 * Descriptor of the ViewAttributes encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ViewAttributes_EncodeableType =
{
    "ViewAttributes",
    OpcUaId_ViewAttributes,
    OpcUaId_ViewAttributes_Encoding_DefaultBinary,
    OpcUaId_ViewAttributes_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ViewAttributes),
    OpcUa_ViewAttributes_Initialize,
    OpcUa_ViewAttributes_Clear,
    NULL,
    OpcUa_ViewAttributes_Encode,
    OpcUa_ViewAttributes_Decode,
    sizeof ViewAttributes_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ViewAttributes_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AddNodesItem
/*============================================================================
 * OpcUa_AddNodesItem_Initialize
 *===========================================================================*/
void OpcUa_AddNodesItem_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddNodesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesItem_Clear
 *===========================================================================*/
void OpcUa_AddNodesItem_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddNodesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesItem_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesItem_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddNodesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddNodesItem_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesItem_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddNodesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddNodesItem encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddNodesItem_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, ParentNodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, RequestedNewNodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, NodeAttributes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesItem, TypeDefinition) // offset
    },
};

/*============================================================================
 * Descriptor of the AddNodesItem encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddNodesItem_EncodeableType =
{
    "AddNodesItem",
    OpcUaId_AddNodesItem,
    OpcUaId_AddNodesItem_Encoding_DefaultBinary,
    OpcUaId_AddNodesItem_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddNodesItem),
    OpcUa_AddNodesItem_Initialize,
    OpcUa_AddNodesItem_Clear,
    NULL,
    OpcUa_AddNodesItem_Encode,
    OpcUa_AddNodesItem_Decode,
    sizeof AddNodesItem_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddNodesItem_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AddNodesResult
/*============================================================================
 * OpcUa_AddNodesResult_Initialize
 *===========================================================================*/
void OpcUa_AddNodesResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddNodesResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesResult_Clear
 *===========================================================================*/
void OpcUa_AddNodesResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddNodesResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddNodesResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddNodesResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddNodesResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddNodesResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddNodesResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResult, AddedNodeId) // offset
    },
};

/*============================================================================
 * Descriptor of the AddNodesResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddNodesResult_EncodeableType =
{
    "AddNodesResult",
    OpcUaId_AddNodesResult,
    OpcUaId_AddNodesResult_Encoding_DefaultBinary,
    OpcUaId_AddNodesResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddNodesResult),
    OpcUa_AddNodesResult_Initialize,
    OpcUa_AddNodesResult_Clear,
    NULL,
    OpcUa_AddNodesResult_Encode,
    OpcUa_AddNodesResult_Decode,
    sizeof AddNodesResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddNodesResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AddNodes
#ifndef OPCUA_EXCLUDE_AddNodesRequest
/*============================================================================
 * OpcUa_AddNodesRequest_Initialize
 *===========================================================================*/
void OpcUa_AddNodesRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesRequest_Clear
 *===========================================================================*/
void OpcUa_AddNodesRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddNodesRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddNodesRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddNodesRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesRequest, NoOfNodesToAdd) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_AddNodesItem, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesRequest, NodesToAdd) // offset
    },
};

/*============================================================================
 * Descriptor of the AddNodesRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddNodesRequest_EncodeableType =
{
    "AddNodesRequest",
    OpcUaId_AddNodesRequest,
    OpcUaId_AddNodesRequest_Encoding_DefaultBinary,
    OpcUaId_AddNodesRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddNodesRequest),
    OpcUa_AddNodesRequest_Initialize,
    OpcUa_AddNodesRequest_Clear,
    NULL,
    OpcUa_AddNodesRequest_Encode,
    OpcUa_AddNodesRequest_Decode,
    sizeof AddNodesRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddNodesRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AddNodesResponse
/*============================================================================
 * OpcUa_AddNodesResponse_Initialize
 *===========================================================================*/
void OpcUa_AddNodesResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesResponse_Clear
 *===========================================================================*/
void OpcUa_AddNodesResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddNodesResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddNodesResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddNodesResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddNodesResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddNodesResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_AddNodesResult, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddNodesResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the AddNodesResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddNodesResponse_EncodeableType =
{
    "AddNodesResponse",
    OpcUaId_AddNodesResponse,
    OpcUaId_AddNodesResponse_Encoding_DefaultBinary,
    OpcUaId_AddNodesResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddNodesResponse),
    OpcUa_AddNodesResponse_Initialize,
    OpcUa_AddNodesResponse_Clear,
    NULL,
    OpcUa_AddNodesResponse_Encode,
    OpcUa_AddNodesResponse_Decode,
    sizeof AddNodesResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddNodesResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_AddReferencesItem
/*============================================================================
 * OpcUa_AddReferencesItem_Initialize
 *===========================================================================*/
void OpcUa_AddReferencesItem_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddReferencesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddReferencesItem_Clear
 *===========================================================================*/
void OpcUa_AddReferencesItem_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddReferencesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddReferencesItem_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddReferencesItem_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddReferencesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddReferencesItem_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddReferencesItem_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddReferencesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddReferencesItem encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddReferencesItem_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesItem, SourceNodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesItem, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesItem, IsForward) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesItem, TargetServerUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesItem, TargetNodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesItem, TargetNodeClass) // offset
    },
};

/*============================================================================
 * Descriptor of the AddReferencesItem encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddReferencesItem_EncodeableType =
{
    "AddReferencesItem",
    OpcUaId_AddReferencesItem,
    OpcUaId_AddReferencesItem_Encoding_DefaultBinary,
    OpcUaId_AddReferencesItem_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddReferencesItem),
    OpcUa_AddReferencesItem_Initialize,
    OpcUa_AddReferencesItem_Clear,
    NULL,
    OpcUa_AddReferencesItem_Encode,
    OpcUa_AddReferencesItem_Decode,
    sizeof AddReferencesItem_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddReferencesItem_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AddReferences
#ifndef OPCUA_EXCLUDE_AddReferencesRequest
/*============================================================================
 * OpcUa_AddReferencesRequest_Initialize
 *===========================================================================*/
void OpcUa_AddReferencesRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddReferencesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddReferencesRequest_Clear
 *===========================================================================*/
void OpcUa_AddReferencesRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddReferencesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddReferencesRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddReferencesRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddReferencesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddReferencesRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddReferencesRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddReferencesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddReferencesRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddReferencesRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesRequest, NoOfReferencesToAdd) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_AddReferencesItem, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesRequest, ReferencesToAdd) // offset
    },
};

/*============================================================================
 * Descriptor of the AddReferencesRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddReferencesRequest_EncodeableType =
{
    "AddReferencesRequest",
    OpcUaId_AddReferencesRequest,
    OpcUaId_AddReferencesRequest_Encoding_DefaultBinary,
    OpcUaId_AddReferencesRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddReferencesRequest),
    OpcUa_AddReferencesRequest_Initialize,
    OpcUa_AddReferencesRequest_Clear,
    NULL,
    OpcUa_AddReferencesRequest_Encode,
    OpcUa_AddReferencesRequest_Decode,
    sizeof AddReferencesRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddReferencesRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AddReferencesResponse
/*============================================================================
 * OpcUa_AddReferencesResponse_Initialize
 *===========================================================================*/
void OpcUa_AddReferencesResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AddReferencesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddReferencesResponse_Clear
 *===========================================================================*/
void OpcUa_AddReferencesResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AddReferencesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AddReferencesResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddReferencesResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AddReferencesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AddReferencesResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AddReferencesResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AddReferencesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AddReferencesResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AddReferencesResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AddReferencesResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the AddReferencesResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AddReferencesResponse_EncodeableType =
{
    "AddReferencesResponse",
    OpcUaId_AddReferencesResponse,
    OpcUaId_AddReferencesResponse_Encoding_DefaultBinary,
    OpcUaId_AddReferencesResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AddReferencesResponse),
    OpcUa_AddReferencesResponse_Initialize,
    OpcUa_AddReferencesResponse_Clear,
    NULL,
    OpcUa_AddReferencesResponse_Encode,
    OpcUa_AddReferencesResponse_Decode,
    sizeof AddReferencesResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AddReferencesResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_DeleteNodesItem
/*============================================================================
 * OpcUa_DeleteNodesItem_Initialize
 *===========================================================================*/
void OpcUa_DeleteNodesItem_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteNodesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteNodesItem_Clear
 *===========================================================================*/
void OpcUa_DeleteNodesItem_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteNodesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteNodesItem_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteNodesItem_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteNodesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteNodesItem_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteNodesItem_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteNodesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteNodesItem encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteNodesItem_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesItem, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesItem, DeleteTargetReferences) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteNodesItem encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteNodesItem_EncodeableType =
{
    "DeleteNodesItem",
    OpcUaId_DeleteNodesItem,
    OpcUaId_DeleteNodesItem_Encoding_DefaultBinary,
    OpcUaId_DeleteNodesItem_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteNodesItem),
    OpcUa_DeleteNodesItem_Initialize,
    OpcUa_DeleteNodesItem_Clear,
    NULL,
    OpcUa_DeleteNodesItem_Encode,
    OpcUa_DeleteNodesItem_Decode,
    sizeof DeleteNodesItem_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteNodesItem_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteNodes
#ifndef OPCUA_EXCLUDE_DeleteNodesRequest
/*============================================================================
 * OpcUa_DeleteNodesRequest_Initialize
 *===========================================================================*/
void OpcUa_DeleteNodesRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteNodesRequest_Clear
 *===========================================================================*/
void OpcUa_DeleteNodesRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteNodesRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteNodesRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteNodesRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteNodesRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteNodesRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteNodesRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesRequest, NoOfNodesToDelete) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_DeleteNodesItem, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesRequest, NodesToDelete) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteNodesRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteNodesRequest_EncodeableType =
{
    "DeleteNodesRequest",
    OpcUaId_DeleteNodesRequest,
    OpcUaId_DeleteNodesRequest_Encoding_DefaultBinary,
    OpcUaId_DeleteNodesRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteNodesRequest),
    OpcUa_DeleteNodesRequest_Initialize,
    OpcUa_DeleteNodesRequest_Clear,
    NULL,
    OpcUa_DeleteNodesRequest_Encode,
    OpcUa_DeleteNodesRequest_Decode,
    sizeof DeleteNodesRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteNodesRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteNodesResponse
/*============================================================================
 * OpcUa_DeleteNodesResponse_Initialize
 *===========================================================================*/
void OpcUa_DeleteNodesResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteNodesResponse_Clear
 *===========================================================================*/
void OpcUa_DeleteNodesResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteNodesResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteNodesResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteNodesResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteNodesResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteNodesResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteNodesResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteNodesResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteNodesResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteNodesResponse_EncodeableType =
{
    "DeleteNodesResponse",
    OpcUaId_DeleteNodesResponse,
    OpcUaId_DeleteNodesResponse_Encoding_DefaultBinary,
    OpcUaId_DeleteNodesResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteNodesResponse),
    OpcUa_DeleteNodesResponse_Initialize,
    OpcUa_DeleteNodesResponse_Clear,
    NULL,
    OpcUa_DeleteNodesResponse_Encode,
    OpcUa_DeleteNodesResponse_Decode,
    sizeof DeleteNodesResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteNodesResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_DeleteReferencesItem
/*============================================================================
 * OpcUa_DeleteReferencesItem_Initialize
 *===========================================================================*/
void OpcUa_DeleteReferencesItem_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteReferencesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteReferencesItem_Clear
 *===========================================================================*/
void OpcUa_DeleteReferencesItem_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteReferencesItem_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteReferencesItem_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteReferencesItem_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteReferencesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteReferencesItem_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteReferencesItem_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteReferencesItem_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteReferencesItem encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteReferencesItem_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesItem, SourceNodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesItem, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesItem, IsForward) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesItem, TargetNodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesItem, DeleteBidirectional) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteReferencesItem encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteReferencesItem_EncodeableType =
{
    "DeleteReferencesItem",
    OpcUaId_DeleteReferencesItem,
    OpcUaId_DeleteReferencesItem_Encoding_DefaultBinary,
    OpcUaId_DeleteReferencesItem_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteReferencesItem),
    OpcUa_DeleteReferencesItem_Initialize,
    OpcUa_DeleteReferencesItem_Clear,
    NULL,
    OpcUa_DeleteReferencesItem_Encode,
    OpcUa_DeleteReferencesItem_Decode,
    sizeof DeleteReferencesItem_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteReferencesItem_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteReferences
#ifndef OPCUA_EXCLUDE_DeleteReferencesRequest
/*============================================================================
 * OpcUa_DeleteReferencesRequest_Initialize
 *===========================================================================*/
void OpcUa_DeleteReferencesRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteReferencesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteReferencesRequest_Clear
 *===========================================================================*/
void OpcUa_DeleteReferencesRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteReferencesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteReferencesRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteReferencesRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteReferencesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteReferencesRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteReferencesRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteReferencesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteReferencesRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteReferencesRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesRequest, NoOfReferencesToDelete) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_DeleteReferencesItem, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesRequest, ReferencesToDelete) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteReferencesRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteReferencesRequest_EncodeableType =
{
    "DeleteReferencesRequest",
    OpcUaId_DeleteReferencesRequest,
    OpcUaId_DeleteReferencesRequest_Encoding_DefaultBinary,
    OpcUaId_DeleteReferencesRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteReferencesRequest),
    OpcUa_DeleteReferencesRequest_Initialize,
    OpcUa_DeleteReferencesRequest_Clear,
    NULL,
    OpcUa_DeleteReferencesRequest_Encode,
    OpcUa_DeleteReferencesRequest_Decode,
    sizeof DeleteReferencesRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteReferencesRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteReferencesResponse
/*============================================================================
 * OpcUa_DeleteReferencesResponse_Initialize
 *===========================================================================*/
void OpcUa_DeleteReferencesResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteReferencesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteReferencesResponse_Clear
 *===========================================================================*/
void OpcUa_DeleteReferencesResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteReferencesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteReferencesResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteReferencesResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteReferencesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteReferencesResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteReferencesResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteReferencesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteReferencesResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteReferencesResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteReferencesResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteReferencesResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteReferencesResponse_EncodeableType =
{
    "DeleteReferencesResponse",
    OpcUaId_DeleteReferencesResponse,
    OpcUaId_DeleteReferencesResponse_Encoding_DefaultBinary,
    OpcUaId_DeleteReferencesResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteReferencesResponse),
    OpcUa_DeleteReferencesResponse_Initialize,
    OpcUa_DeleteReferencesResponse_Clear,
    NULL,
    OpcUa_DeleteReferencesResponse_Encode,
    OpcUa_DeleteReferencesResponse_Decode,
    sizeof DeleteReferencesResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteReferencesResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_ViewDescription
/*============================================================================
 * OpcUa_ViewDescription_Initialize
 *===========================================================================*/
void OpcUa_ViewDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ViewDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ViewDescription_Clear
 *===========================================================================*/
void OpcUa_ViewDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ViewDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ViewDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ViewDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ViewDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ViewDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ViewDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ViewDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ViewDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ViewDescription_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewDescription, ViewId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewDescription, Timestamp) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ViewDescription, ViewVersion) // offset
    },
};

/*============================================================================
 * Descriptor of the ViewDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ViewDescription_EncodeableType =
{
    "ViewDescription",
    OpcUaId_ViewDescription,
    OpcUaId_ViewDescription_Encoding_DefaultBinary,
    OpcUaId_ViewDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ViewDescription),
    OpcUa_ViewDescription_Initialize,
    OpcUa_ViewDescription_Clear,
    NULL,
    OpcUa_ViewDescription_Encode,
    OpcUa_ViewDescription_Decode,
    sizeof ViewDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ViewDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowseDescription
/*============================================================================
 * OpcUa_BrowseDescription_Initialize
 *===========================================================================*/
void OpcUa_BrowseDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowseDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseDescription_Clear
 *===========================================================================*/
void OpcUa_BrowseDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowseDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowseDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowseDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowseDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowseDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowseDescription_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseDescription, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseDescription, BrowseDirection) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseDescription, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseDescription, IncludeSubtypes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseDescription, NodeClassMask) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseDescription, ResultMask) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowseDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowseDescription_EncodeableType =
{
    "BrowseDescription",
    OpcUaId_BrowseDescription,
    OpcUaId_BrowseDescription_Encoding_DefaultBinary,
    OpcUaId_BrowseDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowseDescription),
    OpcUa_BrowseDescription_Initialize,
    OpcUa_BrowseDescription_Clear,
    NULL,
    OpcUa_BrowseDescription_Encode,
    OpcUa_BrowseDescription_Decode,
    sizeof BrowseDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowseDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReferenceDescription
/*============================================================================
 * OpcUa_ReferenceDescription_Initialize
 *===========================================================================*/
void OpcUa_ReferenceDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReferenceDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceDescription_Clear
 *===========================================================================*/
void OpcUa_ReferenceDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReferenceDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReferenceDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReferenceDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReferenceDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReferenceDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReferenceDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReferenceDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReferenceDescription_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, IsForward) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, BrowseName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, NodeClass) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReferenceDescription, TypeDefinition) // offset
    },
};

/*============================================================================
 * Descriptor of the ReferenceDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReferenceDescription_EncodeableType =
{
    "ReferenceDescription",
    OpcUaId_ReferenceDescription,
    OpcUaId_ReferenceDescription_Encoding_DefaultBinary,
    OpcUaId_ReferenceDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReferenceDescription),
    OpcUa_ReferenceDescription_Initialize,
    OpcUa_ReferenceDescription_Clear,
    NULL,
    OpcUa_ReferenceDescription_Encode,
    OpcUa_ReferenceDescription_Decode,
    sizeof ReferenceDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReferenceDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowseResult
/*============================================================================
 * OpcUa_BrowseResult_Initialize
 *===========================================================================*/
void OpcUa_BrowseResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowseResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseResult_Clear
 *===========================================================================*/
void OpcUa_BrowseResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowseResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowseResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowseResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowseResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowseResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowseResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResult, ContinuationPoint) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResult, NoOfReferences) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReferenceDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResult, References) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowseResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowseResult_EncodeableType =
{
    "BrowseResult",
    OpcUaId_BrowseResult,
    OpcUaId_BrowseResult_Encoding_DefaultBinary,
    OpcUaId_BrowseResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowseResult),
    OpcUa_BrowseResult_Initialize,
    OpcUa_BrowseResult_Clear,
    NULL,
    OpcUa_BrowseResult_Encode,
    OpcUa_BrowseResult_Decode,
    sizeof BrowseResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowseResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Browse
#ifndef OPCUA_EXCLUDE_BrowseRequest
/*============================================================================
 * OpcUa_BrowseRequest_Initialize
 *===========================================================================*/
void OpcUa_BrowseRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowseRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseRequest_Clear
 *===========================================================================*/
void OpcUa_BrowseRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowseRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowseRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowseRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowseRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowseRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowseRequest_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ViewDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseRequest, View) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseRequest, RequestedMaxReferencesPerNode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseRequest, NoOfNodesToBrowse) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BrowseDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseRequest, NodesToBrowse) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowseRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowseRequest_EncodeableType =
{
    "BrowseRequest",
    OpcUaId_BrowseRequest,
    OpcUaId_BrowseRequest_Encoding_DefaultBinary,
    OpcUaId_BrowseRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowseRequest),
    OpcUa_BrowseRequest_Initialize,
    OpcUa_BrowseRequest_Clear,
    NULL,
    OpcUa_BrowseRequest_Encode,
    OpcUa_BrowseRequest_Decode,
    sizeof BrowseRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowseRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowseResponse
/*============================================================================
 * OpcUa_BrowseResponse_Initialize
 *===========================================================================*/
void OpcUa_BrowseResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowseResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseResponse_Clear
 *===========================================================================*/
void OpcUa_BrowseResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowseResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowseResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowseResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowseResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowseResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowseResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BrowseResult, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowseResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowseResponse_EncodeableType =
{
    "BrowseResponse",
    OpcUaId_BrowseResponse,
    OpcUaId_BrowseResponse_Encoding_DefaultBinary,
    OpcUaId_BrowseResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowseResponse),
    OpcUa_BrowseResponse_Initialize,
    OpcUa_BrowseResponse_Clear,
    NULL,
    OpcUa_BrowseResponse_Encode,
    OpcUa_BrowseResponse_Decode,
    sizeof BrowseResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowseResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_BrowseNext
#ifndef OPCUA_EXCLUDE_BrowseNextRequest
/*============================================================================
 * OpcUa_BrowseNextRequest_Initialize
 *===========================================================================*/
void OpcUa_BrowseNextRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowseNextRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseNextRequest_Clear
 *===========================================================================*/
void OpcUa_BrowseNextRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowseNextRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseNextRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseNextRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowseNextRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowseNextRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseNextRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowseNextRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowseNextRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowseNextRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextRequest, ReleaseContinuationPoints) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextRequest, NoOfContinuationPoints) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextRequest, ContinuationPoints) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowseNextRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowseNextRequest_EncodeableType =
{
    "BrowseNextRequest",
    OpcUaId_BrowseNextRequest,
    OpcUaId_BrowseNextRequest_Encoding_DefaultBinary,
    OpcUaId_BrowseNextRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowseNextRequest),
    OpcUa_BrowseNextRequest_Initialize,
    OpcUa_BrowseNextRequest_Clear,
    NULL,
    OpcUa_BrowseNextRequest_Encode,
    OpcUa_BrowseNextRequest_Decode,
    sizeof BrowseNextRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowseNextRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowseNextResponse
/*============================================================================
 * OpcUa_BrowseNextResponse_Initialize
 *===========================================================================*/
void OpcUa_BrowseNextResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowseNextResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseNextResponse_Clear
 *===========================================================================*/
void OpcUa_BrowseNextResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowseNextResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowseNextResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseNextResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowseNextResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowseNextResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowseNextResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowseNextResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowseNextResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowseNextResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BrowseResult, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowseNextResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowseNextResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowseNextResponse_EncodeableType =
{
    "BrowseNextResponse",
    OpcUaId_BrowseNextResponse,
    OpcUaId_BrowseNextResponse_Encoding_DefaultBinary,
    OpcUaId_BrowseNextResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowseNextResponse),
    OpcUa_BrowseNextResponse_Initialize,
    OpcUa_BrowseNextResponse_Clear,
    NULL,
    OpcUa_BrowseNextResponse_Encode,
    OpcUa_BrowseNextResponse_Decode,
    sizeof BrowseNextResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowseNextResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_RelativePathElement
/*============================================================================
 * OpcUa_RelativePathElement_Initialize
 *===========================================================================*/
void OpcUa_RelativePathElement_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RelativePathElement_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RelativePathElement_Clear
 *===========================================================================*/
void OpcUa_RelativePathElement_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RelativePathElement_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RelativePathElement_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RelativePathElement_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RelativePathElement_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RelativePathElement_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RelativePathElement_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RelativePathElement_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RelativePathElement encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RelativePathElement_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RelativePathElement, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RelativePathElement, IsInverse) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RelativePathElement, IncludeSubtypes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RelativePathElement, TargetName) // offset
    },
};

/*============================================================================
 * Descriptor of the RelativePathElement encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RelativePathElement_EncodeableType =
{
    "RelativePathElement",
    OpcUaId_RelativePathElement,
    OpcUaId_RelativePathElement_Encoding_DefaultBinary,
    OpcUaId_RelativePathElement_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RelativePathElement),
    OpcUa_RelativePathElement_Initialize,
    OpcUa_RelativePathElement_Clear,
    NULL,
    OpcUa_RelativePathElement_Encode,
    OpcUa_RelativePathElement_Decode,
    sizeof RelativePathElement_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RelativePathElement_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RelativePath
/*============================================================================
 * OpcUa_RelativePath_Initialize
 *===========================================================================*/
void OpcUa_RelativePath_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RelativePath_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RelativePath_Clear
 *===========================================================================*/
void OpcUa_RelativePath_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RelativePath_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RelativePath_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RelativePath_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RelativePath_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RelativePath_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RelativePath_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RelativePath_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RelativePath encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RelativePath_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RelativePath, NoOfElements) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_RelativePathElement, // typeIndex
        (uint32_t) offsetof(OpcUa_RelativePath, Elements) // offset
    },
};

/*============================================================================
 * Descriptor of the RelativePath encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RelativePath_EncodeableType =
{
    "RelativePath",
    OpcUaId_RelativePath,
    OpcUaId_RelativePath_Encoding_DefaultBinary,
    OpcUaId_RelativePath_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RelativePath),
    OpcUa_RelativePath_Initialize,
    OpcUa_RelativePath_Clear,
    NULL,
    OpcUa_RelativePath_Encode,
    OpcUa_RelativePath_Decode,
    sizeof RelativePath_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RelativePath_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowsePath
/*============================================================================
 * OpcUa_BrowsePath_Initialize
 *===========================================================================*/
void OpcUa_BrowsePath_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowsePath_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowsePath_Clear
 *===========================================================================*/
void OpcUa_BrowsePath_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowsePath_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowsePath_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowsePath_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowsePath_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowsePath_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowsePath_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowsePath_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowsePath encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowsePath_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePath, StartingNode) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_RelativePath, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePath, RelativePath) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowsePath encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowsePath_EncodeableType =
{
    "BrowsePath",
    OpcUaId_BrowsePath,
    OpcUaId_BrowsePath_Encoding_DefaultBinary,
    OpcUaId_BrowsePath_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowsePath),
    OpcUa_BrowsePath_Initialize,
    OpcUa_BrowsePath_Clear,
    NULL,
    OpcUa_BrowsePath_Encode,
    OpcUa_BrowsePath_Decode,
    sizeof BrowsePath_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowsePath_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowsePathTarget
/*============================================================================
 * OpcUa_BrowsePathTarget_Initialize
 *===========================================================================*/
void OpcUa_BrowsePathTarget_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowsePathTarget_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowsePathTarget_Clear
 *===========================================================================*/
void OpcUa_BrowsePathTarget_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowsePathTarget_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowsePathTarget_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowsePathTarget_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowsePathTarget_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowsePathTarget_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowsePathTarget_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowsePathTarget_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowsePathTarget encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowsePathTarget_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePathTarget, TargetId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePathTarget, RemainingPathIndex) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowsePathTarget encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowsePathTarget_EncodeableType =
{
    "BrowsePathTarget",
    OpcUaId_BrowsePathTarget,
    OpcUaId_BrowsePathTarget_Encoding_DefaultBinary,
    OpcUaId_BrowsePathTarget_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowsePathTarget),
    OpcUa_BrowsePathTarget_Initialize,
    OpcUa_BrowsePathTarget_Clear,
    NULL,
    OpcUa_BrowsePathTarget_Encode,
    OpcUa_BrowsePathTarget_Decode,
    sizeof BrowsePathTarget_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowsePathTarget_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_BrowsePathResult
/*============================================================================
 * OpcUa_BrowsePathResult_Initialize
 *===========================================================================*/
void OpcUa_BrowsePathResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BrowsePathResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowsePathResult_Clear
 *===========================================================================*/
void OpcUa_BrowsePathResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BrowsePathResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BrowsePathResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowsePathResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BrowsePathResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BrowsePathResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BrowsePathResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BrowsePathResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BrowsePathResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BrowsePathResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePathResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePathResult, NoOfTargets) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BrowsePathTarget, // typeIndex
        (uint32_t) offsetof(OpcUa_BrowsePathResult, Targets) // offset
    },
};

/*============================================================================
 * Descriptor of the BrowsePathResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BrowsePathResult_EncodeableType =
{
    "BrowsePathResult",
    OpcUaId_BrowsePathResult,
    OpcUaId_BrowsePathResult_Encoding_DefaultBinary,
    OpcUaId_BrowsePathResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BrowsePathResult),
    OpcUa_BrowsePathResult_Initialize,
    OpcUa_BrowsePathResult_Clear,
    NULL,
    OpcUa_BrowsePathResult_Encode,
    OpcUa_BrowsePathResult_Decode,
    sizeof BrowsePathResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BrowsePathResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIds
#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIdsRequest
/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsRequest_Initialize
 *===========================================================================*/
void OpcUa_TranslateBrowsePathsToNodeIdsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsRequest_Clear
 *===========================================================================*/
void OpcUa_TranslateBrowsePathsToNodeIdsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TranslateBrowsePathsToNodeIdsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TranslateBrowsePathsToNodeIdsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TranslateBrowsePathsToNodeIdsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TranslateBrowsePathsToNodeIdsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsRequest, NoOfBrowsePaths) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BrowsePath, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsRequest, BrowsePaths) // offset
    },
};

/*============================================================================
 * Descriptor of the TranslateBrowsePathsToNodeIdsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType =
{
    "TranslateBrowsePathsToNodeIdsRequest",
    OpcUaId_TranslateBrowsePathsToNodeIdsRequest,
    OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultBinary,
    OpcUaId_TranslateBrowsePathsToNodeIdsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TranslateBrowsePathsToNodeIdsRequest),
    OpcUa_TranslateBrowsePathsToNodeIdsRequest_Initialize,
    OpcUa_TranslateBrowsePathsToNodeIdsRequest_Clear,
    NULL,
    OpcUa_TranslateBrowsePathsToNodeIdsRequest_Encode,
    OpcUa_TranslateBrowsePathsToNodeIdsRequest_Decode,
    sizeof TranslateBrowsePathsToNodeIdsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TranslateBrowsePathsToNodeIdsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIdsResponse
/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsResponse_Initialize
 *===========================================================================*/
void OpcUa_TranslateBrowsePathsToNodeIdsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsResponse_Clear
 *===========================================================================*/
void OpcUa_TranslateBrowsePathsToNodeIdsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TranslateBrowsePathsToNodeIdsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TranslateBrowsePathsToNodeIdsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TranslateBrowsePathsToNodeIdsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TranslateBrowsePathsToNodeIdsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TranslateBrowsePathsToNodeIdsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BrowsePathResult, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TranslateBrowsePathsToNodeIdsResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the TranslateBrowsePathsToNodeIdsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType =
{
    "TranslateBrowsePathsToNodeIdsResponse",
    OpcUaId_TranslateBrowsePathsToNodeIdsResponse,
    OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultBinary,
    OpcUaId_TranslateBrowsePathsToNodeIdsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TranslateBrowsePathsToNodeIdsResponse),
    OpcUa_TranslateBrowsePathsToNodeIdsResponse_Initialize,
    OpcUa_TranslateBrowsePathsToNodeIdsResponse_Clear,
    NULL,
    OpcUa_TranslateBrowsePathsToNodeIdsResponse_Encode,
    OpcUa_TranslateBrowsePathsToNodeIdsResponse_Decode,
    sizeof TranslateBrowsePathsToNodeIdsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TranslateBrowsePathsToNodeIdsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_RegisterNodes
#ifndef OPCUA_EXCLUDE_RegisterNodesRequest
/*============================================================================
 * OpcUa_RegisterNodesRequest_Initialize
 *===========================================================================*/
void OpcUa_RegisterNodesRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisterNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterNodesRequest_Clear
 *===========================================================================*/
void OpcUa_RegisterNodesRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisterNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterNodesRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterNodesRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisterNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisterNodesRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterNodesRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisterNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisterNodesRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisterNodesRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterNodesRequest, NoOfNodesToRegister) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterNodesRequest, NodesToRegister) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisterNodesRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisterNodesRequest_EncodeableType =
{
    "RegisterNodesRequest",
    OpcUaId_RegisterNodesRequest,
    OpcUaId_RegisterNodesRequest_Encoding_DefaultBinary,
    OpcUaId_RegisterNodesRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisterNodesRequest),
    OpcUa_RegisterNodesRequest_Initialize,
    OpcUa_RegisterNodesRequest_Clear,
    NULL,
    OpcUa_RegisterNodesRequest_Encode,
    OpcUa_RegisterNodesRequest_Decode,
    sizeof RegisterNodesRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisterNodesRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RegisterNodesResponse
/*============================================================================
 * OpcUa_RegisterNodesResponse_Initialize
 *===========================================================================*/
void OpcUa_RegisterNodesResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RegisterNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterNodesResponse_Clear
 *===========================================================================*/
void OpcUa_RegisterNodesResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RegisterNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RegisterNodesResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterNodesResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RegisterNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RegisterNodesResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RegisterNodesResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RegisterNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RegisterNodesResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RegisterNodesResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterNodesResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterNodesResponse, NoOfRegisteredNodeIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RegisterNodesResponse, RegisteredNodeIds) // offset
    },
};

/*============================================================================
 * Descriptor of the RegisterNodesResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RegisterNodesResponse_EncodeableType =
{
    "RegisterNodesResponse",
    OpcUaId_RegisterNodesResponse,
    OpcUaId_RegisterNodesResponse_Encoding_DefaultBinary,
    OpcUaId_RegisterNodesResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RegisterNodesResponse),
    OpcUa_RegisterNodesResponse_Initialize,
    OpcUa_RegisterNodesResponse_Clear,
    NULL,
    OpcUa_RegisterNodesResponse_Encode,
    OpcUa_RegisterNodesResponse_Decode,
    sizeof RegisterNodesResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RegisterNodesResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_UnregisterNodes
#ifndef OPCUA_EXCLUDE_UnregisterNodesRequest
/*============================================================================
 * OpcUa_UnregisterNodesRequest_Initialize
 *===========================================================================*/
void OpcUa_UnregisterNodesRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UnregisterNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UnregisterNodesRequest_Clear
 *===========================================================================*/
void OpcUa_UnregisterNodesRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UnregisterNodesRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UnregisterNodesRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UnregisterNodesRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UnregisterNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UnregisterNodesRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UnregisterNodesRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UnregisterNodesRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UnregisterNodesRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UnregisterNodesRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UnregisterNodesRequest, NoOfNodesToUnregister) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UnregisterNodesRequest, NodesToUnregister) // offset
    },
};

/*============================================================================
 * Descriptor of the UnregisterNodesRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UnregisterNodesRequest_EncodeableType =
{
    "UnregisterNodesRequest",
    OpcUaId_UnregisterNodesRequest,
    OpcUaId_UnregisterNodesRequest_Encoding_DefaultBinary,
    OpcUaId_UnregisterNodesRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UnregisterNodesRequest),
    OpcUa_UnregisterNodesRequest_Initialize,
    OpcUa_UnregisterNodesRequest_Clear,
    NULL,
    OpcUa_UnregisterNodesRequest_Encode,
    OpcUa_UnregisterNodesRequest_Decode,
    sizeof UnregisterNodesRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UnregisterNodesRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_UnregisterNodesResponse
/*============================================================================
 * OpcUa_UnregisterNodesResponse_Initialize
 *===========================================================================*/
void OpcUa_UnregisterNodesResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UnregisterNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UnregisterNodesResponse_Clear
 *===========================================================================*/
void OpcUa_UnregisterNodesResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UnregisterNodesResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UnregisterNodesResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UnregisterNodesResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UnregisterNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UnregisterNodesResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UnregisterNodesResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UnregisterNodesResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UnregisterNodesResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UnregisterNodesResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_UnregisterNodesResponse, ResponseHeader) // offset
    },
};

/*============================================================================
 * Descriptor of the UnregisterNodesResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UnregisterNodesResponse_EncodeableType =
{
    "UnregisterNodesResponse",
    OpcUaId_UnregisterNodesResponse,
    OpcUaId_UnregisterNodesResponse_Encoding_DefaultBinary,
    OpcUaId_UnregisterNodesResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UnregisterNodesResponse),
    OpcUa_UnregisterNodesResponse_Initialize,
    OpcUa_UnregisterNodesResponse_Clear,
    NULL,
    OpcUa_UnregisterNodesResponse_Encode,
    OpcUa_UnregisterNodesResponse_Decode,
    sizeof UnregisterNodesResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UnregisterNodesResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_EndpointConfiguration
/*============================================================================
 * OpcUa_EndpointConfiguration_Initialize
 *===========================================================================*/
void OpcUa_EndpointConfiguration_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EndpointConfiguration_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EndpointConfiguration_Clear
 *===========================================================================*/
void OpcUa_EndpointConfiguration_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EndpointConfiguration_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EndpointConfiguration_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EndpointConfiguration_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EndpointConfiguration_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EndpointConfiguration_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EndpointConfiguration_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EndpointConfiguration_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EndpointConfiguration encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EndpointConfiguration_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, OperationTimeout) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, UseBinaryEncoding) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, MaxStringLength) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, MaxByteStringLength) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, MaxArrayLength) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, MaxMessageSize) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, MaxBufferSize) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, ChannelLifetime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointConfiguration, SecurityTokenLifetime) // offset
    },
};

/*============================================================================
 * Descriptor of the EndpointConfiguration encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EndpointConfiguration_EncodeableType =
{
    "EndpointConfiguration",
    OpcUaId_EndpointConfiguration,
    OpcUaId_EndpointConfiguration_Encoding_DefaultBinary,
    OpcUaId_EndpointConfiguration_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EndpointConfiguration),
    OpcUa_EndpointConfiguration_Initialize,
    OpcUa_EndpointConfiguration_Clear,
    NULL,
    OpcUa_EndpointConfiguration_Encode,
    OpcUa_EndpointConfiguration_Decode,
    sizeof EndpointConfiguration_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EndpointConfiguration_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SupportedProfile
/*============================================================================
 * OpcUa_SupportedProfile_Initialize
 *===========================================================================*/
void OpcUa_SupportedProfile_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SupportedProfile_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SupportedProfile_Clear
 *===========================================================================*/
void OpcUa_SupportedProfile_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SupportedProfile_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SupportedProfile_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SupportedProfile_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SupportedProfile_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SupportedProfile_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SupportedProfile_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SupportedProfile_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SupportedProfile encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SupportedProfile_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, OrganizationUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, ProfileId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, ComplianceTool) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, ComplianceDate) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, ComplianceLevel) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, NoOfUnsupportedUnitIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SupportedProfile, UnsupportedUnitIds) // offset
    },
};

/*============================================================================
 * Descriptor of the SupportedProfile encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SupportedProfile_EncodeableType =
{
    "SupportedProfile",
    OpcUaId_SupportedProfile,
    OpcUaId_SupportedProfile_Encoding_DefaultBinary,
    OpcUaId_SupportedProfile_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SupportedProfile),
    OpcUa_SupportedProfile_Initialize,
    OpcUa_SupportedProfile_Clear,
    NULL,
    OpcUa_SupportedProfile_Encode,
    OpcUa_SupportedProfile_Decode,
    sizeof SupportedProfile_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SupportedProfile_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SoftwareCertificate
/*============================================================================
 * OpcUa_SoftwareCertificate_Initialize
 *===========================================================================*/
void OpcUa_SoftwareCertificate_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SoftwareCertificate_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SoftwareCertificate_Clear
 *===========================================================================*/
void OpcUa_SoftwareCertificate_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SoftwareCertificate_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SoftwareCertificate_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SoftwareCertificate_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SoftwareCertificate_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SoftwareCertificate_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SoftwareCertificate_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SoftwareCertificate_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SoftwareCertificate encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SoftwareCertificate_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, ProductName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, ProductUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, VendorName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, VendorProductCertificate) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, SoftwareVersion) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, BuildNumber) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, BuildDate) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, IssuedBy) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, IssueDate) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, NoOfSupportedProfiles) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SupportedProfile, // typeIndex
        (uint32_t) offsetof(OpcUa_SoftwareCertificate, SupportedProfiles) // offset
    },
};

/*============================================================================
 * Descriptor of the SoftwareCertificate encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SoftwareCertificate_EncodeableType =
{
    "SoftwareCertificate",
    OpcUaId_SoftwareCertificate,
    OpcUaId_SoftwareCertificate_Encoding_DefaultBinary,
    OpcUaId_SoftwareCertificate_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SoftwareCertificate),
    OpcUa_SoftwareCertificate_Initialize,
    OpcUa_SoftwareCertificate_Clear,
    NULL,
    OpcUa_SoftwareCertificate_Encode,
    OpcUa_SoftwareCertificate_Decode,
    sizeof SoftwareCertificate_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SoftwareCertificate_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_QueryDataDescription
/*============================================================================
 * OpcUa_QueryDataDescription_Initialize
 *===========================================================================*/
void OpcUa_QueryDataDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_QueryDataDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryDataDescription_Clear
 *===========================================================================*/
void OpcUa_QueryDataDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_QueryDataDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryDataDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryDataDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_QueryDataDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_QueryDataDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryDataDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_QueryDataDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the QueryDataDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor QueryDataDescription_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_RelativePath, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataDescription, RelativePath) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataDescription, AttributeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataDescription, IndexRange) // offset
    },
};

/*============================================================================
 * Descriptor of the QueryDataDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_QueryDataDescription_EncodeableType =
{
    "QueryDataDescription",
    OpcUaId_QueryDataDescription,
    OpcUaId_QueryDataDescription_Encoding_DefaultBinary,
    OpcUaId_QueryDataDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_QueryDataDescription),
    OpcUa_QueryDataDescription_Initialize,
    OpcUa_QueryDataDescription_Clear,
    NULL,
    OpcUa_QueryDataDescription_Encode,
    OpcUa_QueryDataDescription_Decode,
    sizeof QueryDataDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    QueryDataDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_NodeTypeDescription
/*============================================================================
 * OpcUa_NodeTypeDescription_Initialize
 *===========================================================================*/
void OpcUa_NodeTypeDescription_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_NodeTypeDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NodeTypeDescription_Clear
 *===========================================================================*/
void OpcUa_NodeTypeDescription_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_NodeTypeDescription_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NodeTypeDescription_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NodeTypeDescription_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_NodeTypeDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_NodeTypeDescription_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NodeTypeDescription_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_NodeTypeDescription_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the NodeTypeDescription encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor NodeTypeDescription_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeTypeDescription, TypeDefinitionNode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeTypeDescription, IncludeSubTypes) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeTypeDescription, NoOfDataToReturn) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_QueryDataDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeTypeDescription, DataToReturn) // offset
    },
};

/*============================================================================
 * Descriptor of the NodeTypeDescription encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_NodeTypeDescription_EncodeableType =
{
    "NodeTypeDescription",
    OpcUaId_NodeTypeDescription,
    OpcUaId_NodeTypeDescription_Encoding_DefaultBinary,
    OpcUaId_NodeTypeDescription_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_NodeTypeDescription),
    OpcUa_NodeTypeDescription_Initialize,
    OpcUa_NodeTypeDescription_Clear,
    NULL,
    OpcUa_NodeTypeDescription_Encode,
    OpcUa_NodeTypeDescription_Decode,
    sizeof NodeTypeDescription_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    NodeTypeDescription_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_QueryDataSet
/*============================================================================
 * OpcUa_QueryDataSet_Initialize
 *===========================================================================*/
void OpcUa_QueryDataSet_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_QueryDataSet_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryDataSet_Clear
 *===========================================================================*/
void OpcUa_QueryDataSet_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_QueryDataSet_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryDataSet_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryDataSet_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_QueryDataSet_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_QueryDataSet_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryDataSet_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_QueryDataSet_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the QueryDataSet encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor QueryDataSet_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataSet, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExpandedNodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataSet, TypeDefinitionNode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataSet, NoOfValues) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryDataSet, Values) // offset
    },
};

/*============================================================================
 * Descriptor of the QueryDataSet encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_QueryDataSet_EncodeableType =
{
    "QueryDataSet",
    OpcUaId_QueryDataSet,
    OpcUaId_QueryDataSet_Encoding_DefaultBinary,
    OpcUaId_QueryDataSet_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_QueryDataSet),
    OpcUa_QueryDataSet_Initialize,
    OpcUa_QueryDataSet_Clear,
    NULL,
    OpcUa_QueryDataSet_Encode,
    OpcUa_QueryDataSet_Decode,
    sizeof QueryDataSet_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    QueryDataSet_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_NodeReference
/*============================================================================
 * OpcUa_NodeReference_Initialize
 *===========================================================================*/
void OpcUa_NodeReference_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_NodeReference_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NodeReference_Clear
 *===========================================================================*/
void OpcUa_NodeReference_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_NodeReference_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NodeReference_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NodeReference_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_NodeReference_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_NodeReference_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NodeReference_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_NodeReference_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the NodeReference encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor NodeReference_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeReference, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeReference, ReferenceTypeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeReference, IsForward) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeReference, NoOfReferencedNodeIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NodeReference, ReferencedNodeIds) // offset
    },
};

/*============================================================================
 * Descriptor of the NodeReference encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_NodeReference_EncodeableType =
{
    "NodeReference",
    OpcUaId_NodeReference,
    OpcUaId_NodeReference_Encoding_DefaultBinary,
    OpcUaId_NodeReference_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_NodeReference),
    OpcUa_NodeReference_Initialize,
    OpcUa_NodeReference_Clear,
    NULL,
    OpcUa_NodeReference_Encode,
    OpcUa_NodeReference_Decode,
    sizeof NodeReference_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    NodeReference_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ContentFilterElement
/*============================================================================
 * OpcUa_ContentFilterElement_Initialize
 *===========================================================================*/
void OpcUa_ContentFilterElement_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ContentFilterElement_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilterElement_Clear
 *===========================================================================*/
void OpcUa_ContentFilterElement_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ContentFilterElement_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilterElement_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilterElement_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ContentFilterElement_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ContentFilterElement_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilterElement_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ContentFilterElement_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ContentFilterElement encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ContentFilterElement_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElement, FilterOperator) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElement, NoOfFilterOperands) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElement, FilterOperands) // offset
    },
};

/*============================================================================
 * Descriptor of the ContentFilterElement encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ContentFilterElement_EncodeableType =
{
    "ContentFilterElement",
    OpcUaId_ContentFilterElement,
    OpcUaId_ContentFilterElement_Encoding_DefaultBinary,
    OpcUaId_ContentFilterElement_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ContentFilterElement),
    OpcUa_ContentFilterElement_Initialize,
    OpcUa_ContentFilterElement_Clear,
    NULL,
    OpcUa_ContentFilterElement_Encode,
    OpcUa_ContentFilterElement_Decode,
    sizeof ContentFilterElement_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ContentFilterElement_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ContentFilter
/*============================================================================
 * OpcUa_ContentFilter_Initialize
 *===========================================================================*/
void OpcUa_ContentFilter_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ContentFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilter_Clear
 *===========================================================================*/
void OpcUa_ContentFilter_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ContentFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilter_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilter_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ContentFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ContentFilter_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilter_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ContentFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ContentFilter encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ContentFilter_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilter, NoOfElements) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ContentFilterElement, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilter, Elements) // offset
    },
};

/*============================================================================
 * Descriptor of the ContentFilter encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ContentFilter_EncodeableType =
{
    "ContentFilter",
    OpcUaId_ContentFilter,
    OpcUaId_ContentFilter_Encoding_DefaultBinary,
    OpcUaId_ContentFilter_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ContentFilter),
    OpcUa_ContentFilter_Initialize,
    OpcUa_ContentFilter_Clear,
    NULL,
    OpcUa_ContentFilter_Encode,
    OpcUa_ContentFilter_Decode,
    sizeof ContentFilter_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ContentFilter_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ElementOperand
/*============================================================================
 * OpcUa_ElementOperand_Initialize
 *===========================================================================*/
void OpcUa_ElementOperand_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ElementOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ElementOperand_Clear
 *===========================================================================*/
void OpcUa_ElementOperand_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ElementOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ElementOperand_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ElementOperand_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ElementOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ElementOperand_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ElementOperand_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ElementOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ElementOperand encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ElementOperand_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ElementOperand, Index) // offset
    },
};

/*============================================================================
 * Descriptor of the ElementOperand encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ElementOperand_EncodeableType =
{
    "ElementOperand",
    OpcUaId_ElementOperand,
    OpcUaId_ElementOperand_Encoding_DefaultBinary,
    OpcUaId_ElementOperand_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ElementOperand),
    OpcUa_ElementOperand_Initialize,
    OpcUa_ElementOperand_Clear,
    NULL,
    OpcUa_ElementOperand_Encode,
    OpcUa_ElementOperand_Decode,
    sizeof ElementOperand_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ElementOperand_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_LiteralOperand
/*============================================================================
 * OpcUa_LiteralOperand_Initialize
 *===========================================================================*/
void OpcUa_LiteralOperand_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_LiteralOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_LiteralOperand_Clear
 *===========================================================================*/
void OpcUa_LiteralOperand_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_LiteralOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_LiteralOperand_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_LiteralOperand_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_LiteralOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_LiteralOperand_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_LiteralOperand_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_LiteralOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the LiteralOperand encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor LiteralOperand_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_LiteralOperand, Value) // offset
    },
};

/*============================================================================
 * Descriptor of the LiteralOperand encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_LiteralOperand_EncodeableType =
{
    "LiteralOperand",
    OpcUaId_LiteralOperand,
    OpcUaId_LiteralOperand_Encoding_DefaultBinary,
    OpcUaId_LiteralOperand_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_LiteralOperand),
    OpcUa_LiteralOperand_Initialize,
    OpcUa_LiteralOperand_Clear,
    NULL,
    OpcUa_LiteralOperand_Encode,
    OpcUa_LiteralOperand_Decode,
    sizeof LiteralOperand_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    LiteralOperand_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AttributeOperand
/*============================================================================
 * OpcUa_AttributeOperand_Initialize
 *===========================================================================*/
void OpcUa_AttributeOperand_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AttributeOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AttributeOperand_Clear
 *===========================================================================*/
void OpcUa_AttributeOperand_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AttributeOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AttributeOperand_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AttributeOperand_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AttributeOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AttributeOperand_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AttributeOperand_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AttributeOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AttributeOperand encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AttributeOperand_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AttributeOperand, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AttributeOperand, Alias) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_RelativePath, // typeIndex
        (uint32_t) offsetof(OpcUa_AttributeOperand, BrowsePath) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AttributeOperand, AttributeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AttributeOperand, IndexRange) // offset
    },
};

/*============================================================================
 * Descriptor of the AttributeOperand encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AttributeOperand_EncodeableType =
{
    "AttributeOperand",
    OpcUaId_AttributeOperand,
    OpcUaId_AttributeOperand_Encoding_DefaultBinary,
    OpcUaId_AttributeOperand_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AttributeOperand),
    OpcUa_AttributeOperand_Initialize,
    OpcUa_AttributeOperand_Clear,
    NULL,
    OpcUa_AttributeOperand_Encode,
    OpcUa_AttributeOperand_Decode,
    sizeof AttributeOperand_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AttributeOperand_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SimpleAttributeOperand
/*============================================================================
 * OpcUa_SimpleAttributeOperand_Initialize
 *===========================================================================*/
void OpcUa_SimpleAttributeOperand_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SimpleAttributeOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SimpleAttributeOperand_Clear
 *===========================================================================*/
void OpcUa_SimpleAttributeOperand_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SimpleAttributeOperand_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SimpleAttributeOperand_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SimpleAttributeOperand_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SimpleAttributeOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SimpleAttributeOperand_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SimpleAttributeOperand_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SimpleAttributeOperand_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SimpleAttributeOperand encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SimpleAttributeOperand_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SimpleAttributeOperand, TypeDefinitionId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SimpleAttributeOperand, NoOfBrowsePath) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SimpleAttributeOperand, BrowsePath) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SimpleAttributeOperand, AttributeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SimpleAttributeOperand, IndexRange) // offset
    },
};

/*============================================================================
 * Descriptor of the SimpleAttributeOperand encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SimpleAttributeOperand_EncodeableType =
{
    "SimpleAttributeOperand",
    OpcUaId_SimpleAttributeOperand,
    OpcUaId_SimpleAttributeOperand_Encoding_DefaultBinary,
    OpcUaId_SimpleAttributeOperand_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SimpleAttributeOperand),
    OpcUa_SimpleAttributeOperand_Initialize,
    OpcUa_SimpleAttributeOperand_Clear,
    NULL,
    OpcUa_SimpleAttributeOperand_Encode,
    OpcUa_SimpleAttributeOperand_Decode,
    sizeof SimpleAttributeOperand_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SimpleAttributeOperand_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ContentFilterElementResult
/*============================================================================
 * OpcUa_ContentFilterElementResult_Initialize
 *===========================================================================*/
void OpcUa_ContentFilterElementResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ContentFilterElementResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilterElementResult_Clear
 *===========================================================================*/
void OpcUa_ContentFilterElementResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ContentFilterElementResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilterElementResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilterElementResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ContentFilterElementResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ContentFilterElementResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilterElementResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ContentFilterElementResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ContentFilterElementResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ContentFilterElementResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElementResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElementResult, NoOfOperandStatusCodes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElementResult, OperandStatusCodes) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElementResult, NoOfOperandDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterElementResult, OperandDiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the ContentFilterElementResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ContentFilterElementResult_EncodeableType =
{
    "ContentFilterElementResult",
    OpcUaId_ContentFilterElementResult,
    OpcUaId_ContentFilterElementResult_Encoding_DefaultBinary,
    OpcUaId_ContentFilterElementResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ContentFilterElementResult),
    OpcUa_ContentFilterElementResult_Initialize,
    OpcUa_ContentFilterElementResult_Clear,
    NULL,
    OpcUa_ContentFilterElementResult_Encode,
    OpcUa_ContentFilterElementResult_Decode,
    sizeof ContentFilterElementResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ContentFilterElementResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ContentFilterResult
/*============================================================================
 * OpcUa_ContentFilterResult_Initialize
 *===========================================================================*/
void OpcUa_ContentFilterResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ContentFilterResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilterResult_Clear
 *===========================================================================*/
void OpcUa_ContentFilterResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ContentFilterResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ContentFilterResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilterResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ContentFilterResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ContentFilterResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ContentFilterResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ContentFilterResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ContentFilterResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ContentFilterResult_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterResult, NoOfElementResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ContentFilterElementResult, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterResult, ElementResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterResult, NoOfElementDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ContentFilterResult, ElementDiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the ContentFilterResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ContentFilterResult_EncodeableType =
{
    "ContentFilterResult",
    OpcUaId_ContentFilterResult,
    OpcUaId_ContentFilterResult_Encoding_DefaultBinary,
    OpcUaId_ContentFilterResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ContentFilterResult),
    OpcUa_ContentFilterResult_Initialize,
    OpcUa_ContentFilterResult_Clear,
    NULL,
    OpcUa_ContentFilterResult_Encode,
    OpcUa_ContentFilterResult_Decode,
    sizeof ContentFilterResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ContentFilterResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ParsingResult
/*============================================================================
 * OpcUa_ParsingResult_Initialize
 *===========================================================================*/
void OpcUa_ParsingResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ParsingResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ParsingResult_Clear
 *===========================================================================*/
void OpcUa_ParsingResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ParsingResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ParsingResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ParsingResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ParsingResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ParsingResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ParsingResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ParsingResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ParsingResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ParsingResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ParsingResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ParsingResult, NoOfDataStatusCodes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ParsingResult, DataStatusCodes) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ParsingResult, NoOfDataDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ParsingResult, DataDiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the ParsingResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ParsingResult_EncodeableType =
{
    "ParsingResult",
    OpcUaId_ParsingResult,
    OpcUaId_ParsingResult_Encoding_DefaultBinary,
    OpcUaId_ParsingResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ParsingResult),
    OpcUa_ParsingResult_Initialize,
    OpcUa_ParsingResult_Clear,
    NULL,
    OpcUa_ParsingResult_Encode,
    OpcUa_ParsingResult_Decode,
    sizeof ParsingResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ParsingResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_QueryFirst
#ifndef OPCUA_EXCLUDE_QueryFirstRequest
/*============================================================================
 * OpcUa_QueryFirstRequest_Initialize
 *===========================================================================*/
void OpcUa_QueryFirstRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_QueryFirstRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryFirstRequest_Clear
 *===========================================================================*/
void OpcUa_QueryFirstRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_QueryFirstRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryFirstRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryFirstRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_QueryFirstRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_QueryFirstRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryFirstRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_QueryFirstRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the QueryFirstRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor QueryFirstRequest_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ViewDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstRequest, View) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstRequest, NoOfNodeTypes) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_NodeTypeDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstRequest, NodeTypes) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ContentFilter, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstRequest, Filter) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstRequest, MaxDataSetsToReturn) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstRequest, MaxReferencesToReturn) // offset
    },
};

/*============================================================================
 * Descriptor of the QueryFirstRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_QueryFirstRequest_EncodeableType =
{
    "QueryFirstRequest",
    OpcUaId_QueryFirstRequest,
    OpcUaId_QueryFirstRequest_Encoding_DefaultBinary,
    OpcUaId_QueryFirstRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_QueryFirstRequest),
    OpcUa_QueryFirstRequest_Initialize,
    OpcUa_QueryFirstRequest_Clear,
    NULL,
    OpcUa_QueryFirstRequest_Encode,
    OpcUa_QueryFirstRequest_Decode,
    sizeof QueryFirstRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    QueryFirstRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_QueryFirstResponse
/*============================================================================
 * OpcUa_QueryFirstResponse_Initialize
 *===========================================================================*/
void OpcUa_QueryFirstResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_QueryFirstResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryFirstResponse_Clear
 *===========================================================================*/
void OpcUa_QueryFirstResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_QueryFirstResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryFirstResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryFirstResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_QueryFirstResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_QueryFirstResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryFirstResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_QueryFirstResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the QueryFirstResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor QueryFirstResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, NoOfQueryDataSets) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_QueryDataSet, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, QueryDataSets) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, ContinuationPoint) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, NoOfParsingResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ParsingResult, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, ParsingResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, DiagnosticInfos) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ContentFilterResult, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryFirstResponse, FilterResult) // offset
    },
};

/*============================================================================
 * Descriptor of the QueryFirstResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_QueryFirstResponse_EncodeableType =
{
    "QueryFirstResponse",
    OpcUaId_QueryFirstResponse,
    OpcUaId_QueryFirstResponse_Encoding_DefaultBinary,
    OpcUaId_QueryFirstResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_QueryFirstResponse),
    OpcUa_QueryFirstResponse_Initialize,
    OpcUa_QueryFirstResponse_Clear,
    NULL,
    OpcUa_QueryFirstResponse_Encode,
    OpcUa_QueryFirstResponse_Decode,
    sizeof QueryFirstResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    QueryFirstResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_QueryNext
#ifndef OPCUA_EXCLUDE_QueryNextRequest
/*============================================================================
 * OpcUa_QueryNextRequest_Initialize
 *===========================================================================*/
void OpcUa_QueryNextRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_QueryNextRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryNextRequest_Clear
 *===========================================================================*/
void OpcUa_QueryNextRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_QueryNextRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryNextRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryNextRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_QueryNextRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_QueryNextRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryNextRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_QueryNextRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the QueryNextRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor QueryNextRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryNextRequest, ReleaseContinuationPoint) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryNextRequest, ContinuationPoint) // offset
    },
};

/*============================================================================
 * Descriptor of the QueryNextRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_QueryNextRequest_EncodeableType =
{
    "QueryNextRequest",
    OpcUaId_QueryNextRequest,
    OpcUaId_QueryNextRequest_Encoding_DefaultBinary,
    OpcUaId_QueryNextRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_QueryNextRequest),
    OpcUa_QueryNextRequest_Initialize,
    OpcUa_QueryNextRequest_Clear,
    NULL,
    OpcUa_QueryNextRequest_Encode,
    OpcUa_QueryNextRequest_Decode,
    sizeof QueryNextRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    QueryNextRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_QueryNextResponse
/*============================================================================
 * OpcUa_QueryNextResponse_Initialize
 *===========================================================================*/
void OpcUa_QueryNextResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_QueryNextResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryNextResponse_Clear
 *===========================================================================*/
void OpcUa_QueryNextResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_QueryNextResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_QueryNextResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryNextResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_QueryNextResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_QueryNextResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_QueryNextResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_QueryNextResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the QueryNextResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor QueryNextResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryNextResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryNextResponse, NoOfQueryDataSets) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_QueryDataSet, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryNextResponse, QueryDataSets) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_QueryNextResponse, RevisedContinuationPoint) // offset
    },
};

/*============================================================================
 * Descriptor of the QueryNextResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_QueryNextResponse_EncodeableType =
{
    "QueryNextResponse",
    OpcUaId_QueryNextResponse,
    OpcUaId_QueryNextResponse_Encoding_DefaultBinary,
    OpcUaId_QueryNextResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_QueryNextResponse),
    OpcUa_QueryNextResponse_Initialize,
    OpcUa_QueryNextResponse_Clear,
    NULL,
    OpcUa_QueryNextResponse_Encode,
    OpcUa_QueryNextResponse_Decode,
    sizeof QueryNextResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    QueryNextResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_ReadValueId
/*============================================================================
 * OpcUa_ReadValueId_Initialize
 *===========================================================================*/
void OpcUa_ReadValueId_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadValueId_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadValueId_Clear
 *===========================================================================*/
void OpcUa_ReadValueId_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadValueId_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadValueId_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadValueId_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadValueId_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadValueId_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadValueId_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadValueId_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadValueId encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadValueId_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadValueId, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadValueId, AttributeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadValueId, IndexRange) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadValueId, DataEncoding) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadValueId encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadValueId_EncodeableType =
{
    "ReadValueId",
    OpcUaId_ReadValueId,
    OpcUaId_ReadValueId_Encoding_DefaultBinary,
    OpcUaId_ReadValueId_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadValueId),
    OpcUa_ReadValueId_Initialize,
    OpcUa_ReadValueId_Clear,
    NULL,
    OpcUa_ReadValueId_Encode,
    OpcUa_ReadValueId_Decode,
    sizeof ReadValueId_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadValueId_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Read
#ifndef OPCUA_EXCLUDE_ReadRequest
/*============================================================================
 * OpcUa_ReadRequest_Initialize
 *===========================================================================*/
void OpcUa_ReadRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadRequest_Clear
 *===========================================================================*/
void OpcUa_ReadRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRequest, MaxAge) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRequest, TimestampsToReturn) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRequest, NoOfNodesToRead) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReadValueId, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRequest, NodesToRead) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadRequest_EncodeableType =
{
    "ReadRequest",
    OpcUaId_ReadRequest,
    OpcUaId_ReadRequest_Encoding_DefaultBinary,
    OpcUaId_ReadRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadRequest),
    OpcUa_ReadRequest_Initialize,
    OpcUa_ReadRequest_Clear,
    NULL,
    OpcUa_ReadRequest_Encode,
    OpcUa_ReadRequest_Decode,
    sizeof ReadRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReadResponse
/*============================================================================
 * OpcUa_ReadResponse_Initialize
 *===========================================================================*/
void OpcUa_ReadResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadResponse_Clear
 *===========================================================================*/
void OpcUa_ReadResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadResponse_EncodeableType =
{
    "ReadResponse",
    OpcUaId_ReadResponse,
    OpcUaId_ReadResponse_Encoding_DefaultBinary,
    OpcUaId_ReadResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadResponse),
    OpcUa_ReadResponse_Initialize,
    OpcUa_ReadResponse_Clear,
    NULL,
    OpcUa_ReadResponse_Encode,
    OpcUa_ReadResponse_Decode,
    sizeof ReadResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_HistoryReadValueId
/*============================================================================
 * OpcUa_HistoryReadValueId_Initialize
 *===========================================================================*/
void OpcUa_HistoryReadValueId_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryReadValueId_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadValueId_Clear
 *===========================================================================*/
void OpcUa_HistoryReadValueId_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryReadValueId_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadValueId_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadValueId_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryReadValueId_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryReadValueId_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadValueId_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryReadValueId_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryReadValueId encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryReadValueId_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadValueId, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadValueId, IndexRange) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_QualifiedName_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadValueId, DataEncoding) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadValueId, ContinuationPoint) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryReadValueId encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryReadValueId_EncodeableType =
{
    "HistoryReadValueId",
    OpcUaId_HistoryReadValueId,
    OpcUaId_HistoryReadValueId_Encoding_DefaultBinary,
    OpcUaId_HistoryReadValueId_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryReadValueId),
    OpcUa_HistoryReadValueId_Initialize,
    OpcUa_HistoryReadValueId_Clear,
    NULL,
    OpcUa_HistoryReadValueId_Encode,
    OpcUa_HistoryReadValueId_Decode,
    sizeof HistoryReadValueId_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryReadValueId_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryReadResult
/*============================================================================
 * OpcUa_HistoryReadResult_Initialize
 *===========================================================================*/
void OpcUa_HistoryReadResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryReadResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadResult_Clear
 *===========================================================================*/
void OpcUa_HistoryReadResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryReadResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryReadResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryReadResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryReadResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryReadResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryReadResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResult, ContinuationPoint) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResult, HistoryData) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryReadResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryReadResult_EncodeableType =
{
    "HistoryReadResult",
    OpcUaId_HistoryReadResult,
    OpcUaId_HistoryReadResult_Encoding_DefaultBinary,
    OpcUaId_HistoryReadResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryReadResult),
    OpcUa_HistoryReadResult_Initialize,
    OpcUa_HistoryReadResult_Clear,
    NULL,
    OpcUa_HistoryReadResult_Encode,
    OpcUa_HistoryReadResult_Decode,
    sizeof HistoryReadResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryReadResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EventFilter
/*============================================================================
 * OpcUa_EventFilter_Initialize
 *===========================================================================*/
void OpcUa_EventFilter_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EventFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventFilter_Clear
 *===========================================================================*/
void OpcUa_EventFilter_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EventFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventFilter_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventFilter_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EventFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EventFilter_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventFilter_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EventFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EventFilter encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EventFilter_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilter, NoOfSelectClauses) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SimpleAttributeOperand, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilter, SelectClauses) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ContentFilter, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilter, WhereClause) // offset
    },
};

/*============================================================================
 * Descriptor of the EventFilter encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EventFilter_EncodeableType =
{
    "EventFilter",
    OpcUaId_EventFilter,
    OpcUaId_EventFilter_Encoding_DefaultBinary,
    OpcUaId_EventFilter_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EventFilter),
    OpcUa_EventFilter_Initialize,
    OpcUa_EventFilter_Clear,
    NULL,
    OpcUa_EventFilter_Encode,
    OpcUa_EventFilter_Decode,
    sizeof EventFilter_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EventFilter_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReadEventDetails
/*============================================================================
 * OpcUa_ReadEventDetails_Initialize
 *===========================================================================*/
void OpcUa_ReadEventDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadEventDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadEventDetails_Clear
 *===========================================================================*/
void OpcUa_ReadEventDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadEventDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadEventDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadEventDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadEventDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadEventDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadEventDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadEventDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadEventDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadEventDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadEventDetails, NumValuesPerNode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadEventDetails, StartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadEventDetails, EndTime) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EventFilter, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadEventDetails, Filter) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadEventDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadEventDetails_EncodeableType =
{
    "ReadEventDetails",
    OpcUaId_ReadEventDetails,
    OpcUaId_ReadEventDetails_Encoding_DefaultBinary,
    OpcUaId_ReadEventDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadEventDetails),
    OpcUa_ReadEventDetails_Initialize,
    OpcUa_ReadEventDetails_Clear,
    NULL,
    OpcUa_ReadEventDetails_Encode,
    OpcUa_ReadEventDetails_Decode,
    sizeof ReadEventDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadEventDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReadRawModifiedDetails
/*============================================================================
 * OpcUa_ReadRawModifiedDetails_Initialize
 *===========================================================================*/
void OpcUa_ReadRawModifiedDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadRawModifiedDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadRawModifiedDetails_Clear
 *===========================================================================*/
void OpcUa_ReadRawModifiedDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadRawModifiedDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadRawModifiedDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadRawModifiedDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadRawModifiedDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadRawModifiedDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadRawModifiedDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadRawModifiedDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadRawModifiedDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadRawModifiedDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRawModifiedDetails, IsReadModified) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRawModifiedDetails, StartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRawModifiedDetails, EndTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRawModifiedDetails, NumValuesPerNode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadRawModifiedDetails, ReturnBounds) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadRawModifiedDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadRawModifiedDetails_EncodeableType =
{
    "ReadRawModifiedDetails",
    OpcUaId_ReadRawModifiedDetails,
    OpcUaId_ReadRawModifiedDetails_Encoding_DefaultBinary,
    OpcUaId_ReadRawModifiedDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadRawModifiedDetails),
    OpcUa_ReadRawModifiedDetails_Initialize,
    OpcUa_ReadRawModifiedDetails_Clear,
    NULL,
    OpcUa_ReadRawModifiedDetails_Encode,
    OpcUa_ReadRawModifiedDetails_Decode,
    sizeof ReadRawModifiedDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadRawModifiedDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AggregateConfiguration
/*============================================================================
 * OpcUa_AggregateConfiguration_Initialize
 *===========================================================================*/
void OpcUa_AggregateConfiguration_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AggregateConfiguration_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AggregateConfiguration_Clear
 *===========================================================================*/
void OpcUa_AggregateConfiguration_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AggregateConfiguration_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AggregateConfiguration_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AggregateConfiguration_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AggregateConfiguration_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AggregateConfiguration_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AggregateConfiguration_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AggregateConfiguration_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AggregateConfiguration encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AggregateConfiguration_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateConfiguration, UseServerCapabilitiesDefaults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateConfiguration, TreatUncertainAsBad) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateConfiguration, PercentDataBad) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateConfiguration, PercentDataGood) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateConfiguration, UseSlopedExtrapolation) // offset
    },
};

/*============================================================================
 * Descriptor of the AggregateConfiguration encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AggregateConfiguration_EncodeableType =
{
    "AggregateConfiguration",
    OpcUaId_AggregateConfiguration,
    OpcUaId_AggregateConfiguration_Encoding_DefaultBinary,
    OpcUaId_AggregateConfiguration_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AggregateConfiguration),
    OpcUa_AggregateConfiguration_Initialize,
    OpcUa_AggregateConfiguration_Clear,
    NULL,
    OpcUa_AggregateConfiguration_Encode,
    OpcUa_AggregateConfiguration_Decode,
    sizeof AggregateConfiguration_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AggregateConfiguration_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReadProcessedDetails
/*============================================================================
 * OpcUa_ReadProcessedDetails_Initialize
 *===========================================================================*/
void OpcUa_ReadProcessedDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadProcessedDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadProcessedDetails_Clear
 *===========================================================================*/
void OpcUa_ReadProcessedDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadProcessedDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadProcessedDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadProcessedDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadProcessedDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadProcessedDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadProcessedDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadProcessedDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadProcessedDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadProcessedDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadProcessedDetails, StartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadProcessedDetails, EndTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadProcessedDetails, ProcessingInterval) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadProcessedDetails, NoOfAggregateType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadProcessedDetails, AggregateType) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_AggregateConfiguration, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadProcessedDetails, AggregateConfiguration) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadProcessedDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadProcessedDetails_EncodeableType =
{
    "ReadProcessedDetails",
    OpcUaId_ReadProcessedDetails,
    OpcUaId_ReadProcessedDetails_Encoding_DefaultBinary,
    OpcUaId_ReadProcessedDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadProcessedDetails),
    OpcUa_ReadProcessedDetails_Initialize,
    OpcUa_ReadProcessedDetails_Clear,
    NULL,
    OpcUa_ReadProcessedDetails_Encode,
    OpcUa_ReadProcessedDetails_Decode,
    sizeof ReadProcessedDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadProcessedDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ReadAtTimeDetails
/*============================================================================
 * OpcUa_ReadAtTimeDetails_Initialize
 *===========================================================================*/
void OpcUa_ReadAtTimeDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ReadAtTimeDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadAtTimeDetails_Clear
 *===========================================================================*/
void OpcUa_ReadAtTimeDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ReadAtTimeDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ReadAtTimeDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadAtTimeDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ReadAtTimeDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ReadAtTimeDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ReadAtTimeDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ReadAtTimeDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ReadAtTimeDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ReadAtTimeDetails_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadAtTimeDetails, NoOfReqTimes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadAtTimeDetails, ReqTimes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ReadAtTimeDetails, UseSimpleBounds) // offset
    },
};

/*============================================================================
 * Descriptor of the ReadAtTimeDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ReadAtTimeDetails_EncodeableType =
{
    "ReadAtTimeDetails",
    OpcUaId_ReadAtTimeDetails,
    OpcUaId_ReadAtTimeDetails_Encoding_DefaultBinary,
    OpcUaId_ReadAtTimeDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ReadAtTimeDetails),
    OpcUa_ReadAtTimeDetails_Initialize,
    OpcUa_ReadAtTimeDetails_Clear,
    NULL,
    OpcUa_ReadAtTimeDetails_Encode,
    OpcUa_ReadAtTimeDetails_Decode,
    sizeof ReadAtTimeDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ReadAtTimeDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryData
/*============================================================================
 * OpcUa_HistoryData_Initialize
 *===========================================================================*/
void OpcUa_HistoryData_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryData_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryData_Clear
 *===========================================================================*/
void OpcUa_HistoryData_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryData_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryData_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryData_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryData_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryData_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryData_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryData_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryData encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryData_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryData, NoOfDataValues) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryData, DataValues) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryData encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryData_EncodeableType =
{
    "HistoryData",
    OpcUaId_HistoryData,
    OpcUaId_HistoryData_Encoding_DefaultBinary,
    OpcUaId_HistoryData_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryData),
    OpcUa_HistoryData_Initialize,
    OpcUa_HistoryData_Clear,
    NULL,
    OpcUa_HistoryData_Encode,
    OpcUa_HistoryData_Decode,
    sizeof HistoryData_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryData_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ModificationInfo
/*============================================================================
 * OpcUa_ModificationInfo_Initialize
 *===========================================================================*/
void OpcUa_ModificationInfo_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ModificationInfo_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModificationInfo_Clear
 *===========================================================================*/
void OpcUa_ModificationInfo_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ModificationInfo_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModificationInfo_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModificationInfo_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ModificationInfo_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ModificationInfo_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModificationInfo_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ModificationInfo_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ModificationInfo encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ModificationInfo_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModificationInfo, ModificationTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModificationInfo, UpdateType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModificationInfo, UserName) // offset
    },
};

/*============================================================================
 * Descriptor of the ModificationInfo encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ModificationInfo_EncodeableType =
{
    "ModificationInfo",
    OpcUaId_ModificationInfo,
    OpcUaId_ModificationInfo_Encoding_DefaultBinary,
    OpcUaId_ModificationInfo_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ModificationInfo),
    OpcUa_ModificationInfo_Initialize,
    OpcUa_ModificationInfo_Clear,
    NULL,
    OpcUa_ModificationInfo_Encode,
    OpcUa_ModificationInfo_Decode,
    sizeof ModificationInfo_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ModificationInfo_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryModifiedData
/*============================================================================
 * OpcUa_HistoryModifiedData_Initialize
 *===========================================================================*/
void OpcUa_HistoryModifiedData_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryModifiedData_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryModifiedData_Clear
 *===========================================================================*/
void OpcUa_HistoryModifiedData_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryModifiedData_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryModifiedData_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryModifiedData_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryModifiedData_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryModifiedData_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryModifiedData_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryModifiedData_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryModifiedData encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryModifiedData_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryModifiedData, NoOfDataValues) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryModifiedData, DataValues) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryModifiedData, NoOfModificationInfos) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ModificationInfo, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryModifiedData, ModificationInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryModifiedData encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryModifiedData_EncodeableType =
{
    "HistoryModifiedData",
    OpcUaId_HistoryModifiedData,
    OpcUaId_HistoryModifiedData_Encoding_DefaultBinary,
    OpcUaId_HistoryModifiedData_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryModifiedData),
    OpcUa_HistoryModifiedData_Initialize,
    OpcUa_HistoryModifiedData_Clear,
    NULL,
    OpcUa_HistoryModifiedData_Encode,
    OpcUa_HistoryModifiedData_Decode,
    sizeof HistoryModifiedData_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryModifiedData_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryEventFieldList
/*============================================================================
 * OpcUa_HistoryEventFieldList_Initialize
 *===========================================================================*/
void OpcUa_HistoryEventFieldList_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryEventFieldList_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryEventFieldList_Clear
 *===========================================================================*/
void OpcUa_HistoryEventFieldList_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryEventFieldList_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryEventFieldList_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryEventFieldList_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryEventFieldList_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryEventFieldList_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryEventFieldList_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryEventFieldList_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryEventFieldList encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryEventFieldList_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryEventFieldList, NoOfEventFields) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryEventFieldList, EventFields) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryEventFieldList encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryEventFieldList_EncodeableType =
{
    "HistoryEventFieldList",
    OpcUaId_HistoryEventFieldList,
    OpcUaId_HistoryEventFieldList_Encoding_DefaultBinary,
    OpcUaId_HistoryEventFieldList_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryEventFieldList),
    OpcUa_HistoryEventFieldList_Initialize,
    OpcUa_HistoryEventFieldList_Clear,
    NULL,
    OpcUa_HistoryEventFieldList_Encode,
    OpcUa_HistoryEventFieldList_Decode,
    sizeof HistoryEventFieldList_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryEventFieldList_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryEvent
/*============================================================================
 * OpcUa_HistoryEvent_Initialize
 *===========================================================================*/
void OpcUa_HistoryEvent_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryEvent_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryEvent_Clear
 *===========================================================================*/
void OpcUa_HistoryEvent_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryEvent_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryEvent_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryEvent_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryEvent_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryEvent_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryEvent_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryEvent_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryEvent encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryEvent_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryEvent, NoOfEvents) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_HistoryEventFieldList, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryEvent, Events) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryEvent encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryEvent_EncodeableType =
{
    "HistoryEvent",
    OpcUaId_HistoryEvent,
    OpcUaId_HistoryEvent_Encoding_DefaultBinary,
    OpcUaId_HistoryEvent_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryEvent),
    OpcUa_HistoryEvent_Initialize,
    OpcUa_HistoryEvent_Clear,
    NULL,
    OpcUa_HistoryEvent_Encode,
    OpcUa_HistoryEvent_Decode,
    sizeof HistoryEvent_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryEvent_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryRead
#ifndef OPCUA_EXCLUDE_HistoryReadRequest
/*============================================================================
 * OpcUa_HistoryReadRequest_Initialize
 *===========================================================================*/
void OpcUa_HistoryReadRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryReadRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadRequest_Clear
 *===========================================================================*/
void OpcUa_HistoryReadRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryReadRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryReadRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryReadRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryReadRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryReadRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryReadRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadRequest, HistoryReadDetails) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadRequest, TimestampsToReturn) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadRequest, ReleaseContinuationPoints) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadRequest, NoOfNodesToRead) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_HistoryReadValueId, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadRequest, NodesToRead) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryReadRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryReadRequest_EncodeableType =
{
    "HistoryReadRequest",
    OpcUaId_HistoryReadRequest,
    OpcUaId_HistoryReadRequest_Encoding_DefaultBinary,
    OpcUaId_HistoryReadRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryReadRequest),
    OpcUa_HistoryReadRequest_Initialize,
    OpcUa_HistoryReadRequest_Clear,
    NULL,
    OpcUa_HistoryReadRequest_Encode,
    OpcUa_HistoryReadRequest_Decode,
    sizeof HistoryReadRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryReadRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryReadResponse
/*============================================================================
 * OpcUa_HistoryReadResponse_Initialize
 *===========================================================================*/
void OpcUa_HistoryReadResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryReadResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadResponse_Clear
 *===========================================================================*/
void OpcUa_HistoryReadResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryReadResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryReadResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryReadResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryReadResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryReadResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryReadResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryReadResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryReadResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_HistoryReadResult, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryReadResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryReadResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryReadResponse_EncodeableType =
{
    "HistoryReadResponse",
    OpcUaId_HistoryReadResponse,
    OpcUaId_HistoryReadResponse_Encoding_DefaultBinary,
    OpcUaId_HistoryReadResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryReadResponse),
    OpcUa_HistoryReadResponse_Initialize,
    OpcUa_HistoryReadResponse_Clear,
    NULL,
    OpcUa_HistoryReadResponse_Encode,
    OpcUa_HistoryReadResponse_Decode,
    sizeof HistoryReadResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryReadResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_WriteValue
/*============================================================================
 * OpcUa_WriteValue_Initialize
 *===========================================================================*/
void OpcUa_WriteValue_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_WriteValue_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_WriteValue_Clear
 *===========================================================================*/
void OpcUa_WriteValue_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_WriteValue_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_WriteValue_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_WriteValue_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_WriteValue_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_WriteValue_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_WriteValue_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_WriteValue_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the WriteValue encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor WriteValue_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteValue, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteValue, AttributeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteValue, IndexRange) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteValue, Value) // offset
    },
};

/*============================================================================
 * Descriptor of the WriteValue encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_WriteValue_EncodeableType =
{
    "WriteValue",
    OpcUaId_WriteValue,
    OpcUaId_WriteValue_Encoding_DefaultBinary,
    OpcUaId_WriteValue_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_WriteValue),
    OpcUa_WriteValue_Initialize,
    OpcUa_WriteValue_Clear,
    NULL,
    OpcUa_WriteValue_Encode,
    OpcUa_WriteValue_Decode,
    sizeof WriteValue_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    WriteValue_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Write
#ifndef OPCUA_EXCLUDE_WriteRequest
/*============================================================================
 * OpcUa_WriteRequest_Initialize
 *===========================================================================*/
void OpcUa_WriteRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_WriteRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_WriteRequest_Clear
 *===========================================================================*/
void OpcUa_WriteRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_WriteRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_WriteRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_WriteRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_WriteRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_WriteRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_WriteRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_WriteRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the WriteRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor WriteRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteRequest, NoOfNodesToWrite) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_WriteValue, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteRequest, NodesToWrite) // offset
    },
};

/*============================================================================
 * Descriptor of the WriteRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_WriteRequest_EncodeableType =
{
    "WriteRequest",
    OpcUaId_WriteRequest,
    OpcUaId_WriteRequest_Encoding_DefaultBinary,
    OpcUaId_WriteRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_WriteRequest),
    OpcUa_WriteRequest_Initialize,
    OpcUa_WriteRequest_Clear,
    NULL,
    OpcUa_WriteRequest_Encode,
    OpcUa_WriteRequest_Decode,
    sizeof WriteRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    WriteRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_WriteResponse
/*============================================================================
 * OpcUa_WriteResponse_Initialize
 *===========================================================================*/
void OpcUa_WriteResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_WriteResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_WriteResponse_Clear
 *===========================================================================*/
void OpcUa_WriteResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_WriteResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_WriteResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_WriteResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_WriteResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_WriteResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_WriteResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_WriteResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the WriteResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor WriteResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_WriteResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the WriteResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_WriteResponse_EncodeableType =
{
    "WriteResponse",
    OpcUaId_WriteResponse,
    OpcUaId_WriteResponse_Encoding_DefaultBinary,
    OpcUaId_WriteResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_WriteResponse),
    OpcUa_WriteResponse_Initialize,
    OpcUa_WriteResponse_Clear,
    NULL,
    OpcUa_WriteResponse_Encode,
    OpcUa_WriteResponse_Decode,
    sizeof WriteResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    WriteResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_HistoryUpdateDetails
/*============================================================================
 * OpcUa_HistoryUpdateDetails_Initialize
 *===========================================================================*/
void OpcUa_HistoryUpdateDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryUpdateDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateDetails_Clear
 *===========================================================================*/
void OpcUa_HistoryUpdateDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryUpdateDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryUpdateDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryUpdateDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryUpdateDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryUpdateDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryUpdateDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateDetails, NodeId) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryUpdateDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryUpdateDetails_EncodeableType =
{
    "HistoryUpdateDetails",
    OpcUaId_HistoryUpdateDetails,
    OpcUaId_HistoryUpdateDetails_Encoding_DefaultBinary,
    OpcUaId_HistoryUpdateDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryUpdateDetails),
    OpcUa_HistoryUpdateDetails_Initialize,
    OpcUa_HistoryUpdateDetails_Clear,
    NULL,
    OpcUa_HistoryUpdateDetails_Encode,
    OpcUa_HistoryUpdateDetails_Decode,
    sizeof HistoryUpdateDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryUpdateDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_UpdateDataDetails
/*============================================================================
 * OpcUa_UpdateDataDetails_Initialize
 *===========================================================================*/
void OpcUa_UpdateDataDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UpdateDataDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UpdateDataDetails_Clear
 *===========================================================================*/
void OpcUa_UpdateDataDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UpdateDataDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UpdateDataDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UpdateDataDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UpdateDataDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UpdateDataDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UpdateDataDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UpdateDataDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UpdateDataDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UpdateDataDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateDataDetails, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateDataDetails, PerformInsertReplace) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateDataDetails, NoOfUpdateValues) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateDataDetails, UpdateValues) // offset
    },
};

/*============================================================================
 * Descriptor of the UpdateDataDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UpdateDataDetails_EncodeableType =
{
    "UpdateDataDetails",
    OpcUaId_UpdateDataDetails,
    OpcUaId_UpdateDataDetails_Encoding_DefaultBinary,
    OpcUaId_UpdateDataDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UpdateDataDetails),
    OpcUa_UpdateDataDetails_Initialize,
    OpcUa_UpdateDataDetails_Clear,
    NULL,
    OpcUa_UpdateDataDetails_Encode,
    OpcUa_UpdateDataDetails_Decode,
    sizeof UpdateDataDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UpdateDataDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_UpdateStructureDataDetails
/*============================================================================
 * OpcUa_UpdateStructureDataDetails_Initialize
 *===========================================================================*/
void OpcUa_UpdateStructureDataDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UpdateStructureDataDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UpdateStructureDataDetails_Clear
 *===========================================================================*/
void OpcUa_UpdateStructureDataDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UpdateStructureDataDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UpdateStructureDataDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UpdateStructureDataDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UpdateStructureDataDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UpdateStructureDataDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UpdateStructureDataDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UpdateStructureDataDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UpdateStructureDataDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UpdateStructureDataDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateStructureDataDetails, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateStructureDataDetails, PerformInsertReplace) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateStructureDataDetails, NoOfUpdateValues) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateStructureDataDetails, UpdateValues) // offset
    },
};

/*============================================================================
 * Descriptor of the UpdateStructureDataDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UpdateStructureDataDetails_EncodeableType =
{
    "UpdateStructureDataDetails",
    OpcUaId_UpdateStructureDataDetails,
    OpcUaId_UpdateStructureDataDetails_Encoding_DefaultBinary,
    OpcUaId_UpdateStructureDataDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UpdateStructureDataDetails),
    OpcUa_UpdateStructureDataDetails_Initialize,
    OpcUa_UpdateStructureDataDetails_Clear,
    NULL,
    OpcUa_UpdateStructureDataDetails_Encode,
    OpcUa_UpdateStructureDataDetails_Decode,
    sizeof UpdateStructureDataDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UpdateStructureDataDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_UpdateEventDetails
/*============================================================================
 * OpcUa_UpdateEventDetails_Initialize
 *===========================================================================*/
void OpcUa_UpdateEventDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_UpdateEventDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UpdateEventDetails_Clear
 *===========================================================================*/
void OpcUa_UpdateEventDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_UpdateEventDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_UpdateEventDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UpdateEventDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_UpdateEventDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_UpdateEventDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_UpdateEventDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_UpdateEventDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the UpdateEventDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor UpdateEventDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateEventDetails, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateEventDetails, PerformInsertReplace) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EventFilter, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateEventDetails, Filter) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateEventDetails, NoOfEventData) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_HistoryEventFieldList, // typeIndex
        (uint32_t) offsetof(OpcUa_UpdateEventDetails, EventData) // offset
    },
};

/*============================================================================
 * Descriptor of the UpdateEventDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_UpdateEventDetails_EncodeableType =
{
    "UpdateEventDetails",
    OpcUaId_UpdateEventDetails,
    OpcUaId_UpdateEventDetails_Encoding_DefaultBinary,
    OpcUaId_UpdateEventDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_UpdateEventDetails),
    OpcUa_UpdateEventDetails_Initialize,
    OpcUa_UpdateEventDetails_Clear,
    NULL,
    OpcUa_UpdateEventDetails_Encode,
    OpcUa_UpdateEventDetails_Decode,
    sizeof UpdateEventDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    UpdateEventDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteRawModifiedDetails
/*============================================================================
 * OpcUa_DeleteRawModifiedDetails_Initialize
 *===========================================================================*/
void OpcUa_DeleteRawModifiedDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteRawModifiedDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteRawModifiedDetails_Clear
 *===========================================================================*/
void OpcUa_DeleteRawModifiedDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteRawModifiedDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteRawModifiedDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteRawModifiedDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteRawModifiedDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteRawModifiedDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteRawModifiedDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteRawModifiedDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteRawModifiedDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteRawModifiedDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteRawModifiedDetails, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteRawModifiedDetails, IsDeleteModified) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteRawModifiedDetails, StartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteRawModifiedDetails, EndTime) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteRawModifiedDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteRawModifiedDetails_EncodeableType =
{
    "DeleteRawModifiedDetails",
    OpcUaId_DeleteRawModifiedDetails,
    OpcUaId_DeleteRawModifiedDetails_Encoding_DefaultBinary,
    OpcUaId_DeleteRawModifiedDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteRawModifiedDetails),
    OpcUa_DeleteRawModifiedDetails_Initialize,
    OpcUa_DeleteRawModifiedDetails_Clear,
    NULL,
    OpcUa_DeleteRawModifiedDetails_Encode,
    OpcUa_DeleteRawModifiedDetails_Decode,
    sizeof DeleteRawModifiedDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteRawModifiedDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteAtTimeDetails
/*============================================================================
 * OpcUa_DeleteAtTimeDetails_Initialize
 *===========================================================================*/
void OpcUa_DeleteAtTimeDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteAtTimeDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteAtTimeDetails_Clear
 *===========================================================================*/
void OpcUa_DeleteAtTimeDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteAtTimeDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteAtTimeDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteAtTimeDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteAtTimeDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteAtTimeDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteAtTimeDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteAtTimeDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteAtTimeDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteAtTimeDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteAtTimeDetails, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteAtTimeDetails, NoOfReqTimes) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteAtTimeDetails, ReqTimes) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteAtTimeDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteAtTimeDetails_EncodeableType =
{
    "DeleteAtTimeDetails",
    OpcUaId_DeleteAtTimeDetails,
    OpcUaId_DeleteAtTimeDetails_Encoding_DefaultBinary,
    OpcUaId_DeleteAtTimeDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteAtTimeDetails),
    OpcUa_DeleteAtTimeDetails_Initialize,
    OpcUa_DeleteAtTimeDetails_Clear,
    NULL,
    OpcUa_DeleteAtTimeDetails_Encode,
    OpcUa_DeleteAtTimeDetails_Decode,
    sizeof DeleteAtTimeDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteAtTimeDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteEventDetails
/*============================================================================
 * OpcUa_DeleteEventDetails_Initialize
 *===========================================================================*/
void OpcUa_DeleteEventDetails_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteEventDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteEventDetails_Clear
 *===========================================================================*/
void OpcUa_DeleteEventDetails_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteEventDetails_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteEventDetails_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteEventDetails_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteEventDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteEventDetails_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteEventDetails_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteEventDetails_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteEventDetails encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteEventDetails_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteEventDetails, NodeId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteEventDetails, NoOfEventIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteEventDetails, EventIds) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteEventDetails encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteEventDetails_EncodeableType =
{
    "DeleteEventDetails",
    OpcUaId_DeleteEventDetails,
    OpcUaId_DeleteEventDetails_Encoding_DefaultBinary,
    OpcUaId_DeleteEventDetails_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteEventDetails),
    OpcUa_DeleteEventDetails_Initialize,
    OpcUa_DeleteEventDetails_Clear,
    NULL,
    OpcUa_DeleteEventDetails_Encode,
    OpcUa_DeleteEventDetails_Decode,
    sizeof DeleteEventDetails_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteEventDetails_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryUpdateResult
/*============================================================================
 * OpcUa_HistoryUpdateResult_Initialize
 *===========================================================================*/
void OpcUa_HistoryUpdateResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryUpdateResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateResult_Clear
 *===========================================================================*/
void OpcUa_HistoryUpdateResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryUpdateResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryUpdateResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryUpdateResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryUpdateResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryUpdateResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryUpdateResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResult, NoOfOperationResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResult, OperationResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResult, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResult, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryUpdateResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryUpdateResult_EncodeableType =
{
    "HistoryUpdateResult",
    OpcUaId_HistoryUpdateResult,
    OpcUaId_HistoryUpdateResult_Encoding_DefaultBinary,
    OpcUaId_HistoryUpdateResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryUpdateResult),
    OpcUa_HistoryUpdateResult_Initialize,
    OpcUa_HistoryUpdateResult_Clear,
    NULL,
    OpcUa_HistoryUpdateResult_Encode,
    OpcUa_HistoryUpdateResult_Decode,
    sizeof HistoryUpdateResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryUpdateResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryUpdate
#ifndef OPCUA_EXCLUDE_HistoryUpdateRequest
/*============================================================================
 * OpcUa_HistoryUpdateRequest_Initialize
 *===========================================================================*/
void OpcUa_HistoryUpdateRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryUpdateRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateRequest_Clear
 *===========================================================================*/
void OpcUa_HistoryUpdateRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryUpdateRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryUpdateRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryUpdateRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryUpdateRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryUpdateRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryUpdateRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateRequest, NoOfHistoryUpdateDetails) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateRequest, HistoryUpdateDetails) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryUpdateRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryUpdateRequest_EncodeableType =
{
    "HistoryUpdateRequest",
    OpcUaId_HistoryUpdateRequest,
    OpcUaId_HistoryUpdateRequest_Encoding_DefaultBinary,
    OpcUaId_HistoryUpdateRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryUpdateRequest),
    OpcUa_HistoryUpdateRequest_Initialize,
    OpcUa_HistoryUpdateRequest_Clear,
    NULL,
    OpcUa_HistoryUpdateRequest_Encode,
    OpcUa_HistoryUpdateRequest_Decode,
    sizeof HistoryUpdateRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryUpdateRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_HistoryUpdateResponse
/*============================================================================
 * OpcUa_HistoryUpdateResponse_Initialize
 *===========================================================================*/
void OpcUa_HistoryUpdateResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_HistoryUpdateResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateResponse_Clear
 *===========================================================================*/
void OpcUa_HistoryUpdateResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_HistoryUpdateResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_HistoryUpdateResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_HistoryUpdateResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_HistoryUpdateResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_HistoryUpdateResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_HistoryUpdateResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the HistoryUpdateResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor HistoryUpdateResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_HistoryUpdateResult, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_HistoryUpdateResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the HistoryUpdateResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_HistoryUpdateResponse_EncodeableType =
{
    "HistoryUpdateResponse",
    OpcUaId_HistoryUpdateResponse,
    OpcUaId_HistoryUpdateResponse_Encoding_DefaultBinary,
    OpcUaId_HistoryUpdateResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_HistoryUpdateResponse),
    OpcUa_HistoryUpdateResponse_Initialize,
    OpcUa_HistoryUpdateResponse_Clear,
    NULL,
    OpcUa_HistoryUpdateResponse_Encode,
    OpcUa_HistoryUpdateResponse_Decode,
    sizeof HistoryUpdateResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    HistoryUpdateResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_CallMethodRequest
/*============================================================================
 * OpcUa_CallMethodRequest_Initialize
 *===========================================================================*/
void OpcUa_CallMethodRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CallMethodRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallMethodRequest_Clear
 *===========================================================================*/
void OpcUa_CallMethodRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CallMethodRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallMethodRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallMethodRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CallMethodRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CallMethodRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallMethodRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CallMethodRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CallMethodRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CallMethodRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodRequest, ObjectId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodRequest, MethodId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodRequest, NoOfInputArguments) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodRequest, InputArguments) // offset
    },
};

/*============================================================================
 * Descriptor of the CallMethodRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CallMethodRequest_EncodeableType =
{
    "CallMethodRequest",
    OpcUaId_CallMethodRequest,
    OpcUaId_CallMethodRequest_Encoding_DefaultBinary,
    OpcUaId_CallMethodRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CallMethodRequest),
    OpcUa_CallMethodRequest_Initialize,
    OpcUa_CallMethodRequest_Clear,
    NULL,
    OpcUa_CallMethodRequest_Encode,
    OpcUa_CallMethodRequest_Decode,
    sizeof CallMethodRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CallMethodRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CallMethodResult
/*============================================================================
 * OpcUa_CallMethodResult_Initialize
 *===========================================================================*/
void OpcUa_CallMethodResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CallMethodResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallMethodResult_Clear
 *===========================================================================*/
void OpcUa_CallMethodResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CallMethodResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallMethodResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallMethodResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CallMethodResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CallMethodResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallMethodResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CallMethodResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CallMethodResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CallMethodResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, NoOfInputArgumentResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, InputArgumentResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, NoOfInputArgumentDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, InputArgumentDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, NoOfOutputArguments) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallMethodResult, OutputArguments) // offset
    },
};

/*============================================================================
 * Descriptor of the CallMethodResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CallMethodResult_EncodeableType =
{
    "CallMethodResult",
    OpcUaId_CallMethodResult,
    OpcUaId_CallMethodResult_Encoding_DefaultBinary,
    OpcUaId_CallMethodResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CallMethodResult),
    OpcUa_CallMethodResult_Initialize,
    OpcUa_CallMethodResult_Clear,
    NULL,
    OpcUa_CallMethodResult_Encode,
    OpcUa_CallMethodResult_Decode,
    sizeof CallMethodResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CallMethodResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Call
#ifndef OPCUA_EXCLUDE_CallRequest
/*============================================================================
 * OpcUa_CallRequest_Initialize
 *===========================================================================*/
void OpcUa_CallRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CallRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallRequest_Clear
 *===========================================================================*/
void OpcUa_CallRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CallRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CallRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CallRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CallRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CallRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CallRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallRequest, NoOfMethodsToCall) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_CallMethodRequest, // typeIndex
        (uint32_t) offsetof(OpcUa_CallRequest, MethodsToCall) // offset
    },
};

/*============================================================================
 * Descriptor of the CallRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CallRequest_EncodeableType =
{
    "CallRequest",
    OpcUaId_CallRequest,
    OpcUaId_CallRequest_Encoding_DefaultBinary,
    OpcUaId_CallRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CallRequest),
    OpcUa_CallRequest_Initialize,
    OpcUa_CallRequest_Clear,
    NULL,
    OpcUa_CallRequest_Encode,
    OpcUa_CallRequest_Decode,
    sizeof CallRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CallRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CallResponse
/*============================================================================
 * OpcUa_CallResponse_Initialize
 *===========================================================================*/
void OpcUa_CallResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CallResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallResponse_Clear
 *===========================================================================*/
void OpcUa_CallResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CallResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CallResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CallResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CallResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CallResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CallResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CallResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CallResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CallResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_CallMethodResult, // typeIndex
        (uint32_t) offsetof(OpcUa_CallResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CallResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the CallResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CallResponse_EncodeableType =
{
    "CallResponse",
    OpcUaId_CallResponse,
    OpcUaId_CallResponse_Encoding_DefaultBinary,
    OpcUaId_CallResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CallResponse),
    OpcUa_CallResponse_Initialize,
    OpcUa_CallResponse_Clear,
    NULL,
    OpcUa_CallResponse_Encode,
    OpcUa_CallResponse_Decode,
    sizeof CallResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CallResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_DataChangeFilter
/*============================================================================
 * OpcUa_DataChangeFilter_Initialize
 *===========================================================================*/
void OpcUa_DataChangeFilter_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DataChangeFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataChangeFilter_Clear
 *===========================================================================*/
void OpcUa_DataChangeFilter_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DataChangeFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataChangeFilter_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataChangeFilter_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DataChangeFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DataChangeFilter_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataChangeFilter_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DataChangeFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DataChangeFilter encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DataChangeFilter_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeFilter, Trigger) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeFilter, DeadbandType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeFilter, DeadbandValue) // offset
    },
};

/*============================================================================
 * Descriptor of the DataChangeFilter encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DataChangeFilter_EncodeableType =
{
    "DataChangeFilter",
    OpcUaId_DataChangeFilter,
    OpcUaId_DataChangeFilter_Encoding_DefaultBinary,
    OpcUaId_DataChangeFilter_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DataChangeFilter),
    OpcUa_DataChangeFilter_Initialize,
    OpcUa_DataChangeFilter_Clear,
    NULL,
    OpcUa_DataChangeFilter_Encode,
    OpcUa_DataChangeFilter_Decode,
    sizeof DataChangeFilter_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DataChangeFilter_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AggregateFilter
/*============================================================================
 * OpcUa_AggregateFilter_Initialize
 *===========================================================================*/
void OpcUa_AggregateFilter_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AggregateFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AggregateFilter_Clear
 *===========================================================================*/
void OpcUa_AggregateFilter_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AggregateFilter_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AggregateFilter_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AggregateFilter_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AggregateFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AggregateFilter_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AggregateFilter_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AggregateFilter_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AggregateFilter encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AggregateFilter_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilter, StartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilter, AggregateType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilter, ProcessingInterval) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_AggregateConfiguration, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilter, AggregateConfiguration) // offset
    },
};

/*============================================================================
 * Descriptor of the AggregateFilter encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AggregateFilter_EncodeableType =
{
    "AggregateFilter",
    OpcUaId_AggregateFilter,
    OpcUaId_AggregateFilter_Encoding_DefaultBinary,
    OpcUaId_AggregateFilter_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AggregateFilter),
    OpcUa_AggregateFilter_Initialize,
    OpcUa_AggregateFilter_Clear,
    NULL,
    OpcUa_AggregateFilter_Encode,
    OpcUa_AggregateFilter_Decode,
    sizeof AggregateFilter_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AggregateFilter_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EventFilterResult
/*============================================================================
 * OpcUa_EventFilterResult_Initialize
 *===========================================================================*/
void OpcUa_EventFilterResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EventFilterResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventFilterResult_Clear
 *===========================================================================*/
void OpcUa_EventFilterResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EventFilterResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventFilterResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventFilterResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EventFilterResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EventFilterResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventFilterResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EventFilterResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EventFilterResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EventFilterResult_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilterResult, NoOfSelectClauseResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilterResult, SelectClauseResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilterResult, NoOfSelectClauseDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilterResult, SelectClauseDiagnosticInfos) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ContentFilterResult, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFilterResult, WhereClauseResult) // offset
    },
};

/*============================================================================
 * Descriptor of the EventFilterResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EventFilterResult_EncodeableType =
{
    "EventFilterResult",
    OpcUaId_EventFilterResult,
    OpcUaId_EventFilterResult_Encoding_DefaultBinary,
    OpcUaId_EventFilterResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EventFilterResult),
    OpcUa_EventFilterResult_Initialize,
    OpcUa_EventFilterResult_Clear,
    NULL,
    OpcUa_EventFilterResult_Encode,
    OpcUa_EventFilterResult_Decode,
    sizeof EventFilterResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EventFilterResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AggregateFilterResult
/*============================================================================
 * OpcUa_AggregateFilterResult_Initialize
 *===========================================================================*/
void OpcUa_AggregateFilterResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AggregateFilterResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AggregateFilterResult_Clear
 *===========================================================================*/
void OpcUa_AggregateFilterResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AggregateFilterResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AggregateFilterResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AggregateFilterResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AggregateFilterResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AggregateFilterResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AggregateFilterResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AggregateFilterResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AggregateFilterResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AggregateFilterResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilterResult, RevisedStartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilterResult, RevisedProcessingInterval) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_AggregateConfiguration, // typeIndex
        (uint32_t) offsetof(OpcUa_AggregateFilterResult, RevisedAggregateConfiguration) // offset
    },
};

/*============================================================================
 * Descriptor of the AggregateFilterResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AggregateFilterResult_EncodeableType =
{
    "AggregateFilterResult",
    OpcUaId_AggregateFilterResult,
    OpcUaId_AggregateFilterResult_Encoding_DefaultBinary,
    OpcUaId_AggregateFilterResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AggregateFilterResult),
    OpcUa_AggregateFilterResult_Initialize,
    OpcUa_AggregateFilterResult_Clear,
    NULL,
    OpcUa_AggregateFilterResult_Encode,
    OpcUa_AggregateFilterResult_Decode,
    sizeof AggregateFilterResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AggregateFilterResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MonitoringParameters
/*============================================================================
 * OpcUa_MonitoringParameters_Initialize
 *===========================================================================*/
void OpcUa_MonitoringParameters_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MonitoringParameters_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoringParameters_Clear
 *===========================================================================*/
void OpcUa_MonitoringParameters_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MonitoringParameters_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoringParameters_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoringParameters_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MonitoringParameters_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MonitoringParameters_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoringParameters_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MonitoringParameters_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MonitoringParameters encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MonitoringParameters_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoringParameters, ClientHandle) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoringParameters, SamplingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoringParameters, Filter) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoringParameters, QueueSize) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoringParameters, DiscardOldest) // offset
    },
};

/*============================================================================
 * Descriptor of the MonitoringParameters encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MonitoringParameters_EncodeableType =
{
    "MonitoringParameters",
    OpcUaId_MonitoringParameters,
    OpcUaId_MonitoringParameters_Encoding_DefaultBinary,
    OpcUaId_MonitoringParameters_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MonitoringParameters),
    OpcUa_MonitoringParameters_Initialize,
    OpcUa_MonitoringParameters_Clear,
    NULL,
    OpcUa_MonitoringParameters_Encode,
    OpcUa_MonitoringParameters_Decode,
    sizeof MonitoringParameters_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MonitoringParameters_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MonitoredItemCreateRequest
/*============================================================================
 * OpcUa_MonitoredItemCreateRequest_Initialize
 *===========================================================================*/
void OpcUa_MonitoredItemCreateRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MonitoredItemCreateRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemCreateRequest_Clear
 *===========================================================================*/
void OpcUa_MonitoredItemCreateRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MonitoredItemCreateRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemCreateRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemCreateRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MonitoredItemCreateRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MonitoredItemCreateRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemCreateRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MonitoredItemCreateRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MonitoredItemCreateRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MonitoredItemCreateRequest_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ReadValueId, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateRequest, ItemToMonitor) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateRequest, MonitoringMode) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoringParameters, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateRequest, RequestedParameters) // offset
    },
};

/*============================================================================
 * Descriptor of the MonitoredItemCreateRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MonitoredItemCreateRequest_EncodeableType =
{
    "MonitoredItemCreateRequest",
    OpcUaId_MonitoredItemCreateRequest,
    OpcUaId_MonitoredItemCreateRequest_Encoding_DefaultBinary,
    OpcUaId_MonitoredItemCreateRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MonitoredItemCreateRequest),
    OpcUa_MonitoredItemCreateRequest_Initialize,
    OpcUa_MonitoredItemCreateRequest_Clear,
    NULL,
    OpcUa_MonitoredItemCreateRequest_Encode,
    OpcUa_MonitoredItemCreateRequest_Decode,
    sizeof MonitoredItemCreateRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MonitoredItemCreateRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MonitoredItemCreateResult
/*============================================================================
 * OpcUa_MonitoredItemCreateResult_Initialize
 *===========================================================================*/
void OpcUa_MonitoredItemCreateResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MonitoredItemCreateResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemCreateResult_Clear
 *===========================================================================*/
void OpcUa_MonitoredItemCreateResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MonitoredItemCreateResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemCreateResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemCreateResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MonitoredItemCreateResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MonitoredItemCreateResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemCreateResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MonitoredItemCreateResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MonitoredItemCreateResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MonitoredItemCreateResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateResult, MonitoredItemId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateResult, RevisedSamplingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateResult, RevisedQueueSize) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemCreateResult, FilterResult) // offset
    },
};

/*============================================================================
 * Descriptor of the MonitoredItemCreateResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MonitoredItemCreateResult_EncodeableType =
{
    "MonitoredItemCreateResult",
    OpcUaId_MonitoredItemCreateResult,
    OpcUaId_MonitoredItemCreateResult_Encoding_DefaultBinary,
    OpcUaId_MonitoredItemCreateResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MonitoredItemCreateResult),
    OpcUa_MonitoredItemCreateResult_Initialize,
    OpcUa_MonitoredItemCreateResult_Clear,
    NULL,
    OpcUa_MonitoredItemCreateResult_Encode,
    OpcUa_MonitoredItemCreateResult_Decode,
    sizeof MonitoredItemCreateResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MonitoredItemCreateResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CreateMonitoredItems
#ifndef OPCUA_EXCLUDE_CreateMonitoredItemsRequest
/*============================================================================
 * OpcUa_CreateMonitoredItemsRequest_Initialize
 *===========================================================================*/
void OpcUa_CreateMonitoredItemsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CreateMonitoredItemsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateMonitoredItemsRequest_Clear
 *===========================================================================*/
void OpcUa_CreateMonitoredItemsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CreateMonitoredItemsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateMonitoredItemsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateMonitoredItemsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CreateMonitoredItemsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CreateMonitoredItemsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateMonitoredItemsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CreateMonitoredItemsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CreateMonitoredItemsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CreateMonitoredItemsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsRequest, TimestampsToReturn) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsRequest, NoOfItemsToCreate) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoredItemCreateRequest, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsRequest, ItemsToCreate) // offset
    },
};

/*============================================================================
 * Descriptor of the CreateMonitoredItemsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CreateMonitoredItemsRequest_EncodeableType =
{
    "CreateMonitoredItemsRequest",
    OpcUaId_CreateMonitoredItemsRequest,
    OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultBinary,
    OpcUaId_CreateMonitoredItemsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CreateMonitoredItemsRequest),
    OpcUa_CreateMonitoredItemsRequest_Initialize,
    OpcUa_CreateMonitoredItemsRequest_Clear,
    NULL,
    OpcUa_CreateMonitoredItemsRequest_Encode,
    OpcUa_CreateMonitoredItemsRequest_Decode,
    sizeof CreateMonitoredItemsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CreateMonitoredItemsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CreateMonitoredItemsResponse
/*============================================================================
 * OpcUa_CreateMonitoredItemsResponse_Initialize
 *===========================================================================*/
void OpcUa_CreateMonitoredItemsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CreateMonitoredItemsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateMonitoredItemsResponse_Clear
 *===========================================================================*/
void OpcUa_CreateMonitoredItemsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CreateMonitoredItemsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateMonitoredItemsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateMonitoredItemsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CreateMonitoredItemsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CreateMonitoredItemsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateMonitoredItemsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CreateMonitoredItemsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CreateMonitoredItemsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CreateMonitoredItemsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoredItemCreateResult, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateMonitoredItemsResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the CreateMonitoredItemsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CreateMonitoredItemsResponse_EncodeableType =
{
    "CreateMonitoredItemsResponse",
    OpcUaId_CreateMonitoredItemsResponse,
    OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultBinary,
    OpcUaId_CreateMonitoredItemsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CreateMonitoredItemsResponse),
    OpcUa_CreateMonitoredItemsResponse_Initialize,
    OpcUa_CreateMonitoredItemsResponse_Clear,
    NULL,
    OpcUa_CreateMonitoredItemsResponse_Encode,
    OpcUa_CreateMonitoredItemsResponse_Decode,
    sizeof CreateMonitoredItemsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CreateMonitoredItemsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_MonitoredItemModifyRequest
/*============================================================================
 * OpcUa_MonitoredItemModifyRequest_Initialize
 *===========================================================================*/
void OpcUa_MonitoredItemModifyRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MonitoredItemModifyRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemModifyRequest_Clear
 *===========================================================================*/
void OpcUa_MonitoredItemModifyRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MonitoredItemModifyRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemModifyRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemModifyRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MonitoredItemModifyRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MonitoredItemModifyRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemModifyRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MonitoredItemModifyRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MonitoredItemModifyRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MonitoredItemModifyRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemModifyRequest, MonitoredItemId) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoringParameters, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemModifyRequest, RequestedParameters) // offset
    },
};

/*============================================================================
 * Descriptor of the MonitoredItemModifyRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MonitoredItemModifyRequest_EncodeableType =
{
    "MonitoredItemModifyRequest",
    OpcUaId_MonitoredItemModifyRequest,
    OpcUaId_MonitoredItemModifyRequest_Encoding_DefaultBinary,
    OpcUaId_MonitoredItemModifyRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MonitoredItemModifyRequest),
    OpcUa_MonitoredItemModifyRequest_Initialize,
    OpcUa_MonitoredItemModifyRequest_Clear,
    NULL,
    OpcUa_MonitoredItemModifyRequest_Encode,
    OpcUa_MonitoredItemModifyRequest_Decode,
    sizeof MonitoredItemModifyRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MonitoredItemModifyRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MonitoredItemModifyResult
/*============================================================================
 * OpcUa_MonitoredItemModifyResult_Initialize
 *===========================================================================*/
void OpcUa_MonitoredItemModifyResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MonitoredItemModifyResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemModifyResult_Clear
 *===========================================================================*/
void OpcUa_MonitoredItemModifyResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MonitoredItemModifyResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemModifyResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemModifyResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MonitoredItemModifyResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MonitoredItemModifyResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemModifyResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MonitoredItemModifyResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MonitoredItemModifyResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MonitoredItemModifyResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemModifyResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemModifyResult, RevisedSamplingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemModifyResult, RevisedQueueSize) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemModifyResult, FilterResult) // offset
    },
};

/*============================================================================
 * Descriptor of the MonitoredItemModifyResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MonitoredItemModifyResult_EncodeableType =
{
    "MonitoredItemModifyResult",
    OpcUaId_MonitoredItemModifyResult,
    OpcUaId_MonitoredItemModifyResult_Encoding_DefaultBinary,
    OpcUaId_MonitoredItemModifyResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MonitoredItemModifyResult),
    OpcUa_MonitoredItemModifyResult_Initialize,
    OpcUa_MonitoredItemModifyResult_Clear,
    NULL,
    OpcUa_MonitoredItemModifyResult_Encode,
    OpcUa_MonitoredItemModifyResult_Decode,
    sizeof MonitoredItemModifyResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MonitoredItemModifyResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ModifyMonitoredItems
#ifndef OPCUA_EXCLUDE_ModifyMonitoredItemsRequest
/*============================================================================
 * OpcUa_ModifyMonitoredItemsRequest_Initialize
 *===========================================================================*/
void OpcUa_ModifyMonitoredItemsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ModifyMonitoredItemsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifyMonitoredItemsRequest_Clear
 *===========================================================================*/
void OpcUa_ModifyMonitoredItemsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ModifyMonitoredItemsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifyMonitoredItemsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifyMonitoredItemsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ModifyMonitoredItemsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ModifyMonitoredItemsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifyMonitoredItemsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ModifyMonitoredItemsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ModifyMonitoredItemsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ModifyMonitoredItemsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsRequest, TimestampsToReturn) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsRequest, NoOfItemsToModify) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoredItemModifyRequest, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsRequest, ItemsToModify) // offset
    },
};

/*============================================================================
 * Descriptor of the ModifyMonitoredItemsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ModifyMonitoredItemsRequest_EncodeableType =
{
    "ModifyMonitoredItemsRequest",
    OpcUaId_ModifyMonitoredItemsRequest,
    OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultBinary,
    OpcUaId_ModifyMonitoredItemsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ModifyMonitoredItemsRequest),
    OpcUa_ModifyMonitoredItemsRequest_Initialize,
    OpcUa_ModifyMonitoredItemsRequest_Clear,
    NULL,
    OpcUa_ModifyMonitoredItemsRequest_Encode,
    OpcUa_ModifyMonitoredItemsRequest_Decode,
    sizeof ModifyMonitoredItemsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ModifyMonitoredItemsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ModifyMonitoredItemsResponse
/*============================================================================
 * OpcUa_ModifyMonitoredItemsResponse_Initialize
 *===========================================================================*/
void OpcUa_ModifyMonitoredItemsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ModifyMonitoredItemsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifyMonitoredItemsResponse_Clear
 *===========================================================================*/
void OpcUa_ModifyMonitoredItemsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ModifyMonitoredItemsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifyMonitoredItemsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifyMonitoredItemsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ModifyMonitoredItemsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ModifyMonitoredItemsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifyMonitoredItemsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ModifyMonitoredItemsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ModifyMonitoredItemsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ModifyMonitoredItemsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoredItemModifyResult, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifyMonitoredItemsResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the ModifyMonitoredItemsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ModifyMonitoredItemsResponse_EncodeableType =
{
    "ModifyMonitoredItemsResponse",
    OpcUaId_ModifyMonitoredItemsResponse,
    OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultBinary,
    OpcUaId_ModifyMonitoredItemsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ModifyMonitoredItemsResponse),
    OpcUa_ModifyMonitoredItemsResponse_Initialize,
    OpcUa_ModifyMonitoredItemsResponse_Clear,
    NULL,
    OpcUa_ModifyMonitoredItemsResponse_Encode,
    OpcUa_ModifyMonitoredItemsResponse_Decode,
    sizeof ModifyMonitoredItemsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ModifyMonitoredItemsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_SetMonitoringMode
#ifndef OPCUA_EXCLUDE_SetMonitoringModeRequest
/*============================================================================
 * OpcUa_SetMonitoringModeRequest_Initialize
 *===========================================================================*/
void OpcUa_SetMonitoringModeRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SetMonitoringModeRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetMonitoringModeRequest_Clear
 *===========================================================================*/
void OpcUa_SetMonitoringModeRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SetMonitoringModeRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetMonitoringModeRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetMonitoringModeRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SetMonitoringModeRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SetMonitoringModeRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetMonitoringModeRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SetMonitoringModeRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SetMonitoringModeRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SetMonitoringModeRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeRequest, MonitoringMode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeRequest, NoOfMonitoredItemIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeRequest, MonitoredItemIds) // offset
    },
};

/*============================================================================
 * Descriptor of the SetMonitoringModeRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SetMonitoringModeRequest_EncodeableType =
{
    "SetMonitoringModeRequest",
    OpcUaId_SetMonitoringModeRequest,
    OpcUaId_SetMonitoringModeRequest_Encoding_DefaultBinary,
    OpcUaId_SetMonitoringModeRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SetMonitoringModeRequest),
    OpcUa_SetMonitoringModeRequest_Initialize,
    OpcUa_SetMonitoringModeRequest_Clear,
    NULL,
    OpcUa_SetMonitoringModeRequest_Encode,
    OpcUa_SetMonitoringModeRequest_Decode,
    sizeof SetMonitoringModeRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SetMonitoringModeRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SetMonitoringModeResponse
/*============================================================================
 * OpcUa_SetMonitoringModeResponse_Initialize
 *===========================================================================*/
void OpcUa_SetMonitoringModeResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SetMonitoringModeResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetMonitoringModeResponse_Clear
 *===========================================================================*/
void OpcUa_SetMonitoringModeResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SetMonitoringModeResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetMonitoringModeResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetMonitoringModeResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SetMonitoringModeResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SetMonitoringModeResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetMonitoringModeResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SetMonitoringModeResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SetMonitoringModeResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SetMonitoringModeResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetMonitoringModeResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the SetMonitoringModeResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SetMonitoringModeResponse_EncodeableType =
{
    "SetMonitoringModeResponse",
    OpcUaId_SetMonitoringModeResponse,
    OpcUaId_SetMonitoringModeResponse_Encoding_DefaultBinary,
    OpcUaId_SetMonitoringModeResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SetMonitoringModeResponse),
    OpcUa_SetMonitoringModeResponse_Initialize,
    OpcUa_SetMonitoringModeResponse_Clear,
    NULL,
    OpcUa_SetMonitoringModeResponse_Encode,
    OpcUa_SetMonitoringModeResponse_Decode,
    sizeof SetMonitoringModeResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SetMonitoringModeResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_SetTriggering
#ifndef OPCUA_EXCLUDE_SetTriggeringRequest
/*============================================================================
 * OpcUa_SetTriggeringRequest_Initialize
 *===========================================================================*/
void OpcUa_SetTriggeringRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SetTriggeringRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetTriggeringRequest_Clear
 *===========================================================================*/
void OpcUa_SetTriggeringRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SetTriggeringRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetTriggeringRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetTriggeringRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SetTriggeringRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SetTriggeringRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetTriggeringRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SetTriggeringRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SetTriggeringRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SetTriggeringRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringRequest, TriggeringItemId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringRequest, NoOfLinksToAdd) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringRequest, LinksToAdd) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringRequest, NoOfLinksToRemove) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringRequest, LinksToRemove) // offset
    },
};

/*============================================================================
 * Descriptor of the SetTriggeringRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SetTriggeringRequest_EncodeableType =
{
    "SetTriggeringRequest",
    OpcUaId_SetTriggeringRequest,
    OpcUaId_SetTriggeringRequest_Encoding_DefaultBinary,
    OpcUaId_SetTriggeringRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SetTriggeringRequest),
    OpcUa_SetTriggeringRequest_Initialize,
    OpcUa_SetTriggeringRequest_Clear,
    NULL,
    OpcUa_SetTriggeringRequest_Encode,
    OpcUa_SetTriggeringRequest_Decode,
    sizeof SetTriggeringRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SetTriggeringRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SetTriggeringResponse
/*============================================================================
 * OpcUa_SetTriggeringResponse_Initialize
 *===========================================================================*/
void OpcUa_SetTriggeringResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SetTriggeringResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetTriggeringResponse_Clear
 *===========================================================================*/
void OpcUa_SetTriggeringResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SetTriggeringResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetTriggeringResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetTriggeringResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SetTriggeringResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SetTriggeringResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetTriggeringResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SetTriggeringResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SetTriggeringResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SetTriggeringResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, NoOfAddResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, AddResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, NoOfAddDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, AddDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, NoOfRemoveResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, RemoveResults) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, NoOfRemoveDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetTriggeringResponse, RemoveDiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the SetTriggeringResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SetTriggeringResponse_EncodeableType =
{
    "SetTriggeringResponse",
    OpcUaId_SetTriggeringResponse,
    OpcUaId_SetTriggeringResponse_Encoding_DefaultBinary,
    OpcUaId_SetTriggeringResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SetTriggeringResponse),
    OpcUa_SetTriggeringResponse_Initialize,
    OpcUa_SetTriggeringResponse_Clear,
    NULL,
    OpcUa_SetTriggeringResponse_Encode,
    OpcUa_SetTriggeringResponse_Decode,
    sizeof SetTriggeringResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SetTriggeringResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItems
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItemsRequest
/*============================================================================
 * OpcUa_DeleteMonitoredItemsRequest_Initialize
 *===========================================================================*/
void OpcUa_DeleteMonitoredItemsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteMonitoredItemsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteMonitoredItemsRequest_Clear
 *===========================================================================*/
void OpcUa_DeleteMonitoredItemsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteMonitoredItemsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteMonitoredItemsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteMonitoredItemsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteMonitoredItemsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteMonitoredItemsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteMonitoredItemsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteMonitoredItemsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteMonitoredItemsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteMonitoredItemsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsRequest, NoOfMonitoredItemIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsRequest, MonitoredItemIds) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteMonitoredItemsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteMonitoredItemsRequest_EncodeableType =
{
    "DeleteMonitoredItemsRequest",
    OpcUaId_DeleteMonitoredItemsRequest,
    OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultBinary,
    OpcUaId_DeleteMonitoredItemsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteMonitoredItemsRequest),
    OpcUa_DeleteMonitoredItemsRequest_Initialize,
    OpcUa_DeleteMonitoredItemsRequest_Clear,
    NULL,
    OpcUa_DeleteMonitoredItemsRequest_Encode,
    OpcUa_DeleteMonitoredItemsRequest_Decode,
    sizeof DeleteMonitoredItemsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteMonitoredItemsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteMonitoredItemsResponse
/*============================================================================
 * OpcUa_DeleteMonitoredItemsResponse_Initialize
 *===========================================================================*/
void OpcUa_DeleteMonitoredItemsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteMonitoredItemsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteMonitoredItemsResponse_Clear
 *===========================================================================*/
void OpcUa_DeleteMonitoredItemsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteMonitoredItemsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteMonitoredItemsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteMonitoredItemsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteMonitoredItemsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteMonitoredItemsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteMonitoredItemsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteMonitoredItemsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteMonitoredItemsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteMonitoredItemsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteMonitoredItemsResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteMonitoredItemsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteMonitoredItemsResponse_EncodeableType =
{
    "DeleteMonitoredItemsResponse",
    OpcUaId_DeleteMonitoredItemsResponse,
    OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultBinary,
    OpcUaId_DeleteMonitoredItemsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteMonitoredItemsResponse),
    OpcUa_DeleteMonitoredItemsResponse_Initialize,
    OpcUa_DeleteMonitoredItemsResponse_Clear,
    NULL,
    OpcUa_DeleteMonitoredItemsResponse_Encode,
    OpcUa_DeleteMonitoredItemsResponse_Decode,
    sizeof DeleteMonitoredItemsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteMonitoredItemsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_CreateSubscription
#ifndef OPCUA_EXCLUDE_CreateSubscriptionRequest
/*============================================================================
 * OpcUa_CreateSubscriptionRequest_Initialize
 *===========================================================================*/
void OpcUa_CreateSubscriptionRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CreateSubscriptionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSubscriptionRequest_Clear
 *===========================================================================*/
void OpcUa_CreateSubscriptionRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CreateSubscriptionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSubscriptionRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSubscriptionRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CreateSubscriptionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CreateSubscriptionRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSubscriptionRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CreateSubscriptionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CreateSubscriptionRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CreateSubscriptionRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionRequest, RequestedPublishingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionRequest, RequestedLifetimeCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionRequest, RequestedMaxKeepAliveCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionRequest, MaxNotificationsPerPublish) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionRequest, PublishingEnabled) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionRequest, Priority) // offset
    },
};

/*============================================================================
 * Descriptor of the CreateSubscriptionRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CreateSubscriptionRequest_EncodeableType =
{
    "CreateSubscriptionRequest",
    OpcUaId_CreateSubscriptionRequest,
    OpcUaId_CreateSubscriptionRequest_Encoding_DefaultBinary,
    OpcUaId_CreateSubscriptionRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CreateSubscriptionRequest),
    OpcUa_CreateSubscriptionRequest_Initialize,
    OpcUa_CreateSubscriptionRequest_Clear,
    NULL,
    OpcUa_CreateSubscriptionRequest_Encode,
    OpcUa_CreateSubscriptionRequest_Decode,
    sizeof CreateSubscriptionRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CreateSubscriptionRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_CreateSubscriptionResponse
/*============================================================================
 * OpcUa_CreateSubscriptionResponse_Initialize
 *===========================================================================*/
void OpcUa_CreateSubscriptionResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_CreateSubscriptionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSubscriptionResponse_Clear
 *===========================================================================*/
void OpcUa_CreateSubscriptionResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_CreateSubscriptionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_CreateSubscriptionResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSubscriptionResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_CreateSubscriptionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_CreateSubscriptionResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_CreateSubscriptionResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_CreateSubscriptionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the CreateSubscriptionResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor CreateSubscriptionResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionResponse, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionResponse, RevisedPublishingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionResponse, RevisedLifetimeCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_CreateSubscriptionResponse, RevisedMaxKeepAliveCount) // offset
    },
};

/*============================================================================
 * Descriptor of the CreateSubscriptionResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_CreateSubscriptionResponse_EncodeableType =
{
    "CreateSubscriptionResponse",
    OpcUaId_CreateSubscriptionResponse,
    OpcUaId_CreateSubscriptionResponse_Encoding_DefaultBinary,
    OpcUaId_CreateSubscriptionResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_CreateSubscriptionResponse),
    OpcUa_CreateSubscriptionResponse_Initialize,
    OpcUa_CreateSubscriptionResponse_Clear,
    NULL,
    OpcUa_CreateSubscriptionResponse_Encode,
    OpcUa_CreateSubscriptionResponse_Decode,
    sizeof CreateSubscriptionResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    CreateSubscriptionResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_ModifySubscription
#ifndef OPCUA_EXCLUDE_ModifySubscriptionRequest
/*============================================================================
 * OpcUa_ModifySubscriptionRequest_Initialize
 *===========================================================================*/
void OpcUa_ModifySubscriptionRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ModifySubscriptionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifySubscriptionRequest_Clear
 *===========================================================================*/
void OpcUa_ModifySubscriptionRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ModifySubscriptionRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifySubscriptionRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifySubscriptionRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ModifySubscriptionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ModifySubscriptionRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifySubscriptionRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ModifySubscriptionRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ModifySubscriptionRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ModifySubscriptionRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionRequest, RequestedPublishingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionRequest, RequestedLifetimeCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionRequest, RequestedMaxKeepAliveCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionRequest, MaxNotificationsPerPublish) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionRequest, Priority) // offset
    },
};

/*============================================================================
 * Descriptor of the ModifySubscriptionRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ModifySubscriptionRequest_EncodeableType =
{
    "ModifySubscriptionRequest",
    OpcUaId_ModifySubscriptionRequest,
    OpcUaId_ModifySubscriptionRequest_Encoding_DefaultBinary,
    OpcUaId_ModifySubscriptionRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ModifySubscriptionRequest),
    OpcUa_ModifySubscriptionRequest_Initialize,
    OpcUa_ModifySubscriptionRequest_Clear,
    NULL,
    OpcUa_ModifySubscriptionRequest_Encode,
    OpcUa_ModifySubscriptionRequest_Decode,
    sizeof ModifySubscriptionRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ModifySubscriptionRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ModifySubscriptionResponse
/*============================================================================
 * OpcUa_ModifySubscriptionResponse_Initialize
 *===========================================================================*/
void OpcUa_ModifySubscriptionResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ModifySubscriptionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifySubscriptionResponse_Clear
 *===========================================================================*/
void OpcUa_ModifySubscriptionResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ModifySubscriptionResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModifySubscriptionResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifySubscriptionResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ModifySubscriptionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ModifySubscriptionResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModifySubscriptionResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ModifySubscriptionResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ModifySubscriptionResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ModifySubscriptionResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionResponse, RevisedPublishingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionResponse, RevisedLifetimeCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModifySubscriptionResponse, RevisedMaxKeepAliveCount) // offset
    },
};

/*============================================================================
 * Descriptor of the ModifySubscriptionResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ModifySubscriptionResponse_EncodeableType =
{
    "ModifySubscriptionResponse",
    OpcUaId_ModifySubscriptionResponse,
    OpcUaId_ModifySubscriptionResponse_Encoding_DefaultBinary,
    OpcUaId_ModifySubscriptionResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ModifySubscriptionResponse),
    OpcUa_ModifySubscriptionResponse_Initialize,
    OpcUa_ModifySubscriptionResponse_Clear,
    NULL,
    OpcUa_ModifySubscriptionResponse_Encode,
    OpcUa_ModifySubscriptionResponse_Decode,
    sizeof ModifySubscriptionResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ModifySubscriptionResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_SetPublishingMode
#ifndef OPCUA_EXCLUDE_SetPublishingModeRequest
/*============================================================================
 * OpcUa_SetPublishingModeRequest_Initialize
 *===========================================================================*/
void OpcUa_SetPublishingModeRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SetPublishingModeRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetPublishingModeRequest_Clear
 *===========================================================================*/
void OpcUa_SetPublishingModeRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SetPublishingModeRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetPublishingModeRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetPublishingModeRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SetPublishingModeRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SetPublishingModeRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetPublishingModeRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SetPublishingModeRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SetPublishingModeRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SetPublishingModeRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeRequest, PublishingEnabled) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeRequest, NoOfSubscriptionIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeRequest, SubscriptionIds) // offset
    },
};

/*============================================================================
 * Descriptor of the SetPublishingModeRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SetPublishingModeRequest_EncodeableType =
{
    "SetPublishingModeRequest",
    OpcUaId_SetPublishingModeRequest,
    OpcUaId_SetPublishingModeRequest_Encoding_DefaultBinary,
    OpcUaId_SetPublishingModeRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SetPublishingModeRequest),
    OpcUa_SetPublishingModeRequest_Initialize,
    OpcUa_SetPublishingModeRequest_Clear,
    NULL,
    OpcUa_SetPublishingModeRequest_Encode,
    OpcUa_SetPublishingModeRequest_Decode,
    sizeof SetPublishingModeRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SetPublishingModeRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SetPublishingModeResponse
/*============================================================================
 * OpcUa_SetPublishingModeResponse_Initialize
 *===========================================================================*/
void OpcUa_SetPublishingModeResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SetPublishingModeResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetPublishingModeResponse_Clear
 *===========================================================================*/
void OpcUa_SetPublishingModeResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SetPublishingModeResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SetPublishingModeResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetPublishingModeResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SetPublishingModeResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SetPublishingModeResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SetPublishingModeResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SetPublishingModeResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SetPublishingModeResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SetPublishingModeResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SetPublishingModeResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the SetPublishingModeResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SetPublishingModeResponse_EncodeableType =
{
    "SetPublishingModeResponse",
    OpcUaId_SetPublishingModeResponse,
    OpcUaId_SetPublishingModeResponse_Encoding_DefaultBinary,
    OpcUaId_SetPublishingModeResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SetPublishingModeResponse),
    OpcUa_SetPublishingModeResponse_Initialize,
    OpcUa_SetPublishingModeResponse_Clear,
    NULL,
    OpcUa_SetPublishingModeResponse_Encode,
    OpcUa_SetPublishingModeResponse_Decode,
    sizeof SetPublishingModeResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SetPublishingModeResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_NotificationMessage
/*============================================================================
 * OpcUa_NotificationMessage_Initialize
 *===========================================================================*/
void OpcUa_NotificationMessage_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_NotificationMessage_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NotificationMessage_Clear
 *===========================================================================*/
void OpcUa_NotificationMessage_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_NotificationMessage_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NotificationMessage_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NotificationMessage_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_NotificationMessage_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_NotificationMessage_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NotificationMessage_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_NotificationMessage_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the NotificationMessage encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor NotificationMessage_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NotificationMessage, SequenceNumber) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NotificationMessage, PublishTime) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NotificationMessage, NoOfNotificationData) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ExtensionObject_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NotificationMessage, NotificationData) // offset
    },
};

/*============================================================================
 * Descriptor of the NotificationMessage encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_NotificationMessage_EncodeableType =
{
    "NotificationMessage",
    OpcUaId_NotificationMessage,
    OpcUaId_NotificationMessage_Encoding_DefaultBinary,
    OpcUaId_NotificationMessage_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_NotificationMessage),
    OpcUa_NotificationMessage_Initialize,
    OpcUa_NotificationMessage_Clear,
    NULL,
    OpcUa_NotificationMessage_Encode,
    OpcUa_NotificationMessage_Decode,
    sizeof NotificationMessage_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    NotificationMessage_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_MonitoredItemNotification
/*============================================================================
 * OpcUa_MonitoredItemNotification_Initialize
 *===========================================================================*/
void OpcUa_MonitoredItemNotification_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_MonitoredItemNotification_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemNotification_Clear
 *===========================================================================*/
void OpcUa_MonitoredItemNotification_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_MonitoredItemNotification_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_MonitoredItemNotification_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemNotification_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_MonitoredItemNotification_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_MonitoredItemNotification_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_MonitoredItemNotification_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_MonitoredItemNotification_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the MonitoredItemNotification encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor MonitoredItemNotification_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemNotification, ClientHandle) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DataValue_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_MonitoredItemNotification, Value) // offset
    },
};

/*============================================================================
 * Descriptor of the MonitoredItemNotification encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_MonitoredItemNotification_EncodeableType =
{
    "MonitoredItemNotification",
    OpcUaId_MonitoredItemNotification,
    OpcUaId_MonitoredItemNotification_Encoding_DefaultBinary,
    OpcUaId_MonitoredItemNotification_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_MonitoredItemNotification),
    OpcUa_MonitoredItemNotification_Initialize,
    OpcUa_MonitoredItemNotification_Clear,
    NULL,
    OpcUa_MonitoredItemNotification_Encode,
    OpcUa_MonitoredItemNotification_Decode,
    sizeof MonitoredItemNotification_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    MonitoredItemNotification_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DataChangeNotification
/*============================================================================
 * OpcUa_DataChangeNotification_Initialize
 *===========================================================================*/
void OpcUa_DataChangeNotification_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DataChangeNotification_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataChangeNotification_Clear
 *===========================================================================*/
void OpcUa_DataChangeNotification_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DataChangeNotification_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DataChangeNotification_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataChangeNotification_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DataChangeNotification_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DataChangeNotification_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DataChangeNotification_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DataChangeNotification_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DataChangeNotification encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DataChangeNotification_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeNotification, NoOfMonitoredItems) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_MonitoredItemNotification, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeNotification, MonitoredItems) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeNotification, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DataChangeNotification, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the DataChangeNotification encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DataChangeNotification_EncodeableType =
{
    "DataChangeNotification",
    OpcUaId_DataChangeNotification,
    OpcUaId_DataChangeNotification_Encoding_DefaultBinary,
    OpcUaId_DataChangeNotification_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DataChangeNotification),
    OpcUa_DataChangeNotification_Initialize,
    OpcUa_DataChangeNotification_Clear,
    NULL,
    OpcUa_DataChangeNotification_Encode,
    OpcUa_DataChangeNotification_Decode,
    sizeof DataChangeNotification_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DataChangeNotification_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EventFieldList
/*============================================================================
 * OpcUa_EventFieldList_Initialize
 *===========================================================================*/
void OpcUa_EventFieldList_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EventFieldList_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventFieldList_Clear
 *===========================================================================*/
void OpcUa_EventFieldList_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EventFieldList_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventFieldList_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventFieldList_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EventFieldList_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EventFieldList_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventFieldList_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EventFieldList_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EventFieldList encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EventFieldList_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFieldList, ClientHandle) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFieldList, NoOfEventFields) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Variant_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventFieldList, EventFields) // offset
    },
};

/*============================================================================
 * Descriptor of the EventFieldList encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EventFieldList_EncodeableType =
{
    "EventFieldList",
    OpcUaId_EventFieldList,
    OpcUaId_EventFieldList_Encoding_DefaultBinary,
    OpcUaId_EventFieldList_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EventFieldList),
    OpcUa_EventFieldList_Initialize,
    OpcUa_EventFieldList_Clear,
    NULL,
    OpcUa_EventFieldList_Encode,
    OpcUa_EventFieldList_Decode,
    sizeof EventFieldList_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EventFieldList_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EventNotificationList
/*============================================================================
 * OpcUa_EventNotificationList_Initialize
 *===========================================================================*/
void OpcUa_EventNotificationList_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EventNotificationList_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventNotificationList_Clear
 *===========================================================================*/
void OpcUa_EventNotificationList_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EventNotificationList_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EventNotificationList_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventNotificationList_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EventNotificationList_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EventNotificationList_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EventNotificationList_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EventNotificationList_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EventNotificationList encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EventNotificationList_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EventNotificationList, NoOfEvents) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EventFieldList, // typeIndex
        (uint32_t) offsetof(OpcUa_EventNotificationList, Events) // offset
    },
};

/*============================================================================
 * Descriptor of the EventNotificationList encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EventNotificationList_EncodeableType =
{
    "EventNotificationList",
    OpcUaId_EventNotificationList,
    OpcUaId_EventNotificationList_Encoding_DefaultBinary,
    OpcUaId_EventNotificationList_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EventNotificationList),
    OpcUa_EventNotificationList_Initialize,
    OpcUa_EventNotificationList_Clear,
    NULL,
    OpcUa_EventNotificationList_Encode,
    OpcUa_EventNotificationList_Decode,
    sizeof EventNotificationList_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EventNotificationList_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_StatusChangeNotification
/*============================================================================
 * OpcUa_StatusChangeNotification_Initialize
 *===========================================================================*/
void OpcUa_StatusChangeNotification_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_StatusChangeNotification_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_StatusChangeNotification_Clear
 *===========================================================================*/
void OpcUa_StatusChangeNotification_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_StatusChangeNotification_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_StatusChangeNotification_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_StatusChangeNotification_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_StatusChangeNotification_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_StatusChangeNotification_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_StatusChangeNotification_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_StatusChangeNotification_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the StatusChangeNotification encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor StatusChangeNotification_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_StatusChangeNotification, Status) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_StatusChangeNotification, DiagnosticInfo) // offset
    },
};

/*============================================================================
 * Descriptor of the StatusChangeNotification encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_StatusChangeNotification_EncodeableType =
{
    "StatusChangeNotification",
    OpcUaId_StatusChangeNotification,
    OpcUaId_StatusChangeNotification_Encoding_DefaultBinary,
    OpcUaId_StatusChangeNotification_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_StatusChangeNotification),
    OpcUa_StatusChangeNotification_Initialize,
    OpcUa_StatusChangeNotification_Clear,
    NULL,
    OpcUa_StatusChangeNotification_Encode,
    OpcUa_StatusChangeNotification_Decode,
    sizeof StatusChangeNotification_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    StatusChangeNotification_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SubscriptionAcknowledgement
/*============================================================================
 * OpcUa_SubscriptionAcknowledgement_Initialize
 *===========================================================================*/
void OpcUa_SubscriptionAcknowledgement_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SubscriptionAcknowledgement_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SubscriptionAcknowledgement_Clear
 *===========================================================================*/
void OpcUa_SubscriptionAcknowledgement_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SubscriptionAcknowledgement_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SubscriptionAcknowledgement_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SubscriptionAcknowledgement_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SubscriptionAcknowledgement_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SubscriptionAcknowledgement_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SubscriptionAcknowledgement_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SubscriptionAcknowledgement_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SubscriptionAcknowledgement encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SubscriptionAcknowledgement_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionAcknowledgement, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionAcknowledgement, SequenceNumber) // offset
    },
};

/*============================================================================
 * Descriptor of the SubscriptionAcknowledgement encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SubscriptionAcknowledgement_EncodeableType =
{
    "SubscriptionAcknowledgement",
    OpcUaId_SubscriptionAcknowledgement,
    OpcUaId_SubscriptionAcknowledgement_Encoding_DefaultBinary,
    OpcUaId_SubscriptionAcknowledgement_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SubscriptionAcknowledgement),
    OpcUa_SubscriptionAcknowledgement_Initialize,
    OpcUa_SubscriptionAcknowledgement_Clear,
    NULL,
    OpcUa_SubscriptionAcknowledgement_Encode,
    OpcUa_SubscriptionAcknowledgement_Decode,
    sizeof SubscriptionAcknowledgement_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SubscriptionAcknowledgement_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Publish
#ifndef OPCUA_EXCLUDE_PublishRequest
/*============================================================================
 * OpcUa_PublishRequest_Initialize
 *===========================================================================*/
void OpcUa_PublishRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_PublishRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_PublishRequest_Clear
 *===========================================================================*/
void OpcUa_PublishRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_PublishRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_PublishRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_PublishRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_PublishRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_PublishRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_PublishRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_PublishRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the PublishRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor PublishRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishRequest, NoOfSubscriptionAcknowledgements) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_SubscriptionAcknowledgement, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishRequest, SubscriptionAcknowledgements) // offset
    },
};

/*============================================================================
 * Descriptor of the PublishRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_PublishRequest_EncodeableType =
{
    "PublishRequest",
    OpcUaId_PublishRequest,
    OpcUaId_PublishRequest_Encoding_DefaultBinary,
    OpcUaId_PublishRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_PublishRequest),
    OpcUa_PublishRequest_Initialize,
    OpcUa_PublishRequest_Clear,
    NULL,
    OpcUa_PublishRequest_Encode,
    OpcUa_PublishRequest_Decode,
    sizeof PublishRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    PublishRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_PublishResponse
/*============================================================================
 * OpcUa_PublishResponse_Initialize
 *===========================================================================*/
void OpcUa_PublishResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_PublishResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_PublishResponse_Clear
 *===========================================================================*/
void OpcUa_PublishResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_PublishResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_PublishResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_PublishResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_PublishResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_PublishResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_PublishResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_PublishResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the PublishResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor PublishResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, NoOfAvailableSequenceNumbers) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, AvailableSequenceNumbers) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, MoreNotifications) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_NotificationMessage, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, NotificationMessage) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_PublishResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the PublishResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_PublishResponse_EncodeableType =
{
    "PublishResponse",
    OpcUaId_PublishResponse,
    OpcUaId_PublishResponse_Encoding_DefaultBinary,
    OpcUaId_PublishResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_PublishResponse),
    OpcUa_PublishResponse_Initialize,
    OpcUa_PublishResponse_Clear,
    NULL,
    OpcUa_PublishResponse_Encode,
    OpcUa_PublishResponse_Decode,
    sizeof PublishResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    PublishResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_Republish
#ifndef OPCUA_EXCLUDE_RepublishRequest
/*============================================================================
 * OpcUa_RepublishRequest_Initialize
 *===========================================================================*/
void OpcUa_RepublishRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RepublishRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RepublishRequest_Clear
 *===========================================================================*/
void OpcUa_RepublishRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RepublishRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RepublishRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RepublishRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RepublishRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RepublishRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RepublishRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RepublishRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RepublishRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RepublishRequest_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RepublishRequest, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RepublishRequest, RetransmitSequenceNumber) // offset
    },
};

/*============================================================================
 * Descriptor of the RepublishRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RepublishRequest_EncodeableType =
{
    "RepublishRequest",
    OpcUaId_RepublishRequest,
    OpcUaId_RepublishRequest_Encoding_DefaultBinary,
    OpcUaId_RepublishRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RepublishRequest),
    OpcUa_RepublishRequest_Initialize,
    OpcUa_RepublishRequest_Clear,
    NULL,
    OpcUa_RepublishRequest_Encode,
    OpcUa_RepublishRequest_Decode,
    sizeof RepublishRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RepublishRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RepublishResponse
/*============================================================================
 * OpcUa_RepublishResponse_Initialize
 *===========================================================================*/
void OpcUa_RepublishResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RepublishResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RepublishResponse_Clear
 *===========================================================================*/
void OpcUa_RepublishResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RepublishResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RepublishResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RepublishResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RepublishResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RepublishResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RepublishResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RepublishResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RepublishResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RepublishResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_RepublishResponse, ResponseHeader) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_NotificationMessage, // typeIndex
        (uint32_t) offsetof(OpcUa_RepublishResponse, NotificationMessage) // offset
    },
};

/*============================================================================
 * Descriptor of the RepublishResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RepublishResponse_EncodeableType =
{
    "RepublishResponse",
    OpcUaId_RepublishResponse,
    OpcUaId_RepublishResponse_Encoding_DefaultBinary,
    OpcUaId_RepublishResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RepublishResponse),
    OpcUa_RepublishResponse_Initialize,
    OpcUa_RepublishResponse_Clear,
    NULL,
    OpcUa_RepublishResponse_Encode,
    OpcUa_RepublishResponse_Decode,
    sizeof RepublishResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RepublishResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_TransferResult
/*============================================================================
 * OpcUa_TransferResult_Initialize
 *===========================================================================*/
void OpcUa_TransferResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TransferResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TransferResult_Clear
 *===========================================================================*/
void OpcUa_TransferResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TransferResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TransferResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TransferResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TransferResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TransferResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TransferResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TransferResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TransferResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TransferResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferResult, NoOfAvailableSequenceNumbers) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferResult, AvailableSequenceNumbers) // offset
    },
};

/*============================================================================
 * Descriptor of the TransferResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TransferResult_EncodeableType =
{
    "TransferResult",
    OpcUaId_TransferResult,
    OpcUaId_TransferResult_Encoding_DefaultBinary,
    OpcUaId_TransferResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TransferResult),
    OpcUa_TransferResult_Initialize,
    OpcUa_TransferResult_Clear,
    NULL,
    OpcUa_TransferResult_Encode,
    OpcUa_TransferResult_Decode,
    sizeof TransferResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TransferResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_TransferSubscriptions
#ifndef OPCUA_EXCLUDE_TransferSubscriptionsRequest
/*============================================================================
 * OpcUa_TransferSubscriptionsRequest_Initialize
 *===========================================================================*/
void OpcUa_TransferSubscriptionsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TransferSubscriptionsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TransferSubscriptionsRequest_Clear
 *===========================================================================*/
void OpcUa_TransferSubscriptionsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TransferSubscriptionsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TransferSubscriptionsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TransferSubscriptionsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TransferSubscriptionsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TransferSubscriptionsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TransferSubscriptionsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TransferSubscriptionsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TransferSubscriptionsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TransferSubscriptionsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsRequest, NoOfSubscriptionIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsRequest, SubscriptionIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsRequest, SendInitialValues) // offset
    },
};

/*============================================================================
 * Descriptor of the TransferSubscriptionsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TransferSubscriptionsRequest_EncodeableType =
{
    "TransferSubscriptionsRequest",
    OpcUaId_TransferSubscriptionsRequest,
    OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultBinary,
    OpcUaId_TransferSubscriptionsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TransferSubscriptionsRequest),
    OpcUa_TransferSubscriptionsRequest_Initialize,
    OpcUa_TransferSubscriptionsRequest_Clear,
    NULL,
    OpcUa_TransferSubscriptionsRequest_Encode,
    OpcUa_TransferSubscriptionsRequest_Decode,
    sizeof TransferSubscriptionsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TransferSubscriptionsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_TransferSubscriptionsResponse
/*============================================================================
 * OpcUa_TransferSubscriptionsResponse_Initialize
 *===========================================================================*/
void OpcUa_TransferSubscriptionsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_TransferSubscriptionsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TransferSubscriptionsResponse_Clear
 *===========================================================================*/
void OpcUa_TransferSubscriptionsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_TransferSubscriptionsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_TransferSubscriptionsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TransferSubscriptionsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_TransferSubscriptionsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_TransferSubscriptionsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_TransferSubscriptionsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_TransferSubscriptionsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the TransferSubscriptionsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor TransferSubscriptionsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsResponse, NoOfResults) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_TransferResult, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_TransferSubscriptionsResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the TransferSubscriptionsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_TransferSubscriptionsResponse_EncodeableType =
{
    "TransferSubscriptionsResponse",
    OpcUaId_TransferSubscriptionsResponse,
    OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultBinary,
    OpcUaId_TransferSubscriptionsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_TransferSubscriptionsResponse),
    OpcUa_TransferSubscriptionsResponse_Initialize,
    OpcUa_TransferSubscriptionsResponse_Clear,
    NULL,
    OpcUa_TransferSubscriptionsResponse_Encode,
    OpcUa_TransferSubscriptionsResponse_Decode,
    sizeof TransferSubscriptionsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    TransferSubscriptionsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_DeleteSubscriptions
#ifndef OPCUA_EXCLUDE_DeleteSubscriptionsRequest
/*============================================================================
 * OpcUa_DeleteSubscriptionsRequest_Initialize
 *===========================================================================*/
void OpcUa_DeleteSubscriptionsRequest_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteSubscriptionsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteSubscriptionsRequest_Clear
 *===========================================================================*/
void OpcUa_DeleteSubscriptionsRequest_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteSubscriptionsRequest_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteSubscriptionsRequest_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteSubscriptionsRequest_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteSubscriptionsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteSubscriptionsRequest_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteSubscriptionsRequest_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteSubscriptionsRequest_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteSubscriptionsRequest encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteSubscriptionsRequest_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsRequest, NoOfSubscriptionIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsRequest, SubscriptionIds) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteSubscriptionsRequest encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteSubscriptionsRequest_EncodeableType =
{
    "DeleteSubscriptionsRequest",
    OpcUaId_DeleteSubscriptionsRequest,
    OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultBinary,
    OpcUaId_DeleteSubscriptionsRequest_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteSubscriptionsRequest),
    OpcUa_DeleteSubscriptionsRequest_Initialize,
    OpcUa_DeleteSubscriptionsRequest_Clear,
    NULL,
    OpcUa_DeleteSubscriptionsRequest_Encode,
    OpcUa_DeleteSubscriptionsRequest_Decode,
    sizeof DeleteSubscriptionsRequest_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteSubscriptionsRequest_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DeleteSubscriptionsResponse
/*============================================================================
 * OpcUa_DeleteSubscriptionsResponse_Initialize
 *===========================================================================*/
void OpcUa_DeleteSubscriptionsResponse_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DeleteSubscriptionsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteSubscriptionsResponse_Clear
 *===========================================================================*/
void OpcUa_DeleteSubscriptionsResponse_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DeleteSubscriptionsResponse_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DeleteSubscriptionsResponse_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteSubscriptionsResponse_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DeleteSubscriptionsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DeleteSubscriptionsResponse_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DeleteSubscriptionsResponse_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DeleteSubscriptionsResponse_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DeleteSubscriptionsResponse encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DeleteSubscriptionsResponse_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        false, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ResponseHeader, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsResponse, ResponseHeader) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsResponse, NoOfResults) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsResponse, Results) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsResponse, NoOfDiagnosticInfos) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DeleteSubscriptionsResponse, DiagnosticInfos) // offset
    },
};

/*============================================================================
 * Descriptor of the DeleteSubscriptionsResponse encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DeleteSubscriptionsResponse_EncodeableType =
{
    "DeleteSubscriptionsResponse",
    OpcUaId_DeleteSubscriptionsResponse,
    OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultBinary,
    OpcUaId_DeleteSubscriptionsResponse_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DeleteSubscriptionsResponse),
    OpcUa_DeleteSubscriptionsResponse_Initialize,
    OpcUa_DeleteSubscriptionsResponse_Clear,
    NULL,
    OpcUa_DeleteSubscriptionsResponse_Encode,
    OpcUa_DeleteSubscriptionsResponse_Decode,
    sizeof DeleteSubscriptionsResponse_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DeleteSubscriptionsResponse_Fields
};
#endif

#endif
#ifndef OPCUA_EXCLUDE_BuildInfo
/*============================================================================
 * OpcUa_BuildInfo_Initialize
 *===========================================================================*/
void OpcUa_BuildInfo_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_BuildInfo_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BuildInfo_Clear
 *===========================================================================*/
void OpcUa_BuildInfo_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_BuildInfo_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_BuildInfo_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BuildInfo_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_BuildInfo_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_BuildInfo_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_BuildInfo_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_BuildInfo_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the BuildInfo encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor BuildInfo_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BuildInfo, ProductUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BuildInfo, ManufacturerName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BuildInfo, ProductName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BuildInfo, SoftwareVersion) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BuildInfo, BuildNumber) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_BuildInfo, BuildDate) // offset
    },
};

/*============================================================================
 * Descriptor of the BuildInfo encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_BuildInfo_EncodeableType =
{
    "BuildInfo",
    OpcUaId_BuildInfo,
    OpcUaId_BuildInfo_Encoding_DefaultBinary,
    OpcUaId_BuildInfo_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_BuildInfo),
    OpcUa_BuildInfo_Initialize,
    OpcUa_BuildInfo_Clear,
    NULL,
    OpcUa_BuildInfo_Encode,
    OpcUa_BuildInfo_Decode,
    sizeof BuildInfo_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    BuildInfo_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_RedundantServerDataType
/*============================================================================
 * OpcUa_RedundantServerDataType_Initialize
 *===========================================================================*/
void OpcUa_RedundantServerDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_RedundantServerDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RedundantServerDataType_Clear
 *===========================================================================*/
void OpcUa_RedundantServerDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_RedundantServerDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_RedundantServerDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RedundantServerDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_RedundantServerDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_RedundantServerDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_RedundantServerDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_RedundantServerDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the RedundantServerDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor RedundantServerDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RedundantServerDataType, ServerId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RedundantServerDataType, ServiceLevel) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_RedundantServerDataType, ServerState) // offset
    },
};

/*============================================================================
 * Descriptor of the RedundantServerDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_RedundantServerDataType_EncodeableType =
{
    "RedundantServerDataType",
    OpcUaId_RedundantServerDataType,
    OpcUaId_RedundantServerDataType_Encoding_DefaultBinary,
    OpcUaId_RedundantServerDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_RedundantServerDataType),
    OpcUa_RedundantServerDataType_Initialize,
    OpcUa_RedundantServerDataType_Clear,
    NULL,
    OpcUa_RedundantServerDataType_Encode,
    OpcUa_RedundantServerDataType_Decode,
    sizeof RedundantServerDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    RedundantServerDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EndpointUrlListDataType
/*============================================================================
 * OpcUa_EndpointUrlListDataType_Initialize
 *===========================================================================*/
void OpcUa_EndpointUrlListDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EndpointUrlListDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EndpointUrlListDataType_Clear
 *===========================================================================*/
void OpcUa_EndpointUrlListDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EndpointUrlListDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EndpointUrlListDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EndpointUrlListDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EndpointUrlListDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EndpointUrlListDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EndpointUrlListDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EndpointUrlListDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EndpointUrlListDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EndpointUrlListDataType_Fields[] = {
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointUrlListDataType, NoOfEndpointUrlList) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EndpointUrlListDataType, EndpointUrlList) // offset
    },
};

/*============================================================================
 * Descriptor of the EndpointUrlListDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EndpointUrlListDataType_EncodeableType =
{
    "EndpointUrlListDataType",
    OpcUaId_EndpointUrlListDataType,
    OpcUaId_EndpointUrlListDataType_Encoding_DefaultBinary,
    OpcUaId_EndpointUrlListDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EndpointUrlListDataType),
    OpcUa_EndpointUrlListDataType_Initialize,
    OpcUa_EndpointUrlListDataType_Clear,
    NULL,
    OpcUa_EndpointUrlListDataType_Encode,
    OpcUa_EndpointUrlListDataType_Decode,
    sizeof EndpointUrlListDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EndpointUrlListDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_NetworkGroupDataType
/*============================================================================
 * OpcUa_NetworkGroupDataType_Initialize
 *===========================================================================*/
void OpcUa_NetworkGroupDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_NetworkGroupDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NetworkGroupDataType_Clear
 *===========================================================================*/
void OpcUa_NetworkGroupDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_NetworkGroupDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_NetworkGroupDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NetworkGroupDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_NetworkGroupDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_NetworkGroupDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_NetworkGroupDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_NetworkGroupDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the NetworkGroupDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor NetworkGroupDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NetworkGroupDataType, ServerUri) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_NetworkGroupDataType, NoOfNetworkPaths) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EndpointUrlListDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_NetworkGroupDataType, NetworkPaths) // offset
    },
};

/*============================================================================
 * Descriptor of the NetworkGroupDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_NetworkGroupDataType_EncodeableType =
{
    "NetworkGroupDataType",
    OpcUaId_NetworkGroupDataType,
    OpcUaId_NetworkGroupDataType_Encoding_DefaultBinary,
    OpcUaId_NetworkGroupDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_NetworkGroupDataType),
    OpcUa_NetworkGroupDataType_Initialize,
    OpcUa_NetworkGroupDataType_Clear,
    NULL,
    OpcUa_NetworkGroupDataType_Encode,
    OpcUa_NetworkGroupDataType_Decode,
    sizeof NetworkGroupDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    NetworkGroupDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SamplingIntervalDiagnosticsDataType
/*============================================================================
 * OpcUa_SamplingIntervalDiagnosticsDataType_Initialize
 *===========================================================================*/
void OpcUa_SamplingIntervalDiagnosticsDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SamplingIntervalDiagnosticsDataType_Clear
 *===========================================================================*/
void OpcUa_SamplingIntervalDiagnosticsDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SamplingIntervalDiagnosticsDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SamplingIntervalDiagnosticsDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SamplingIntervalDiagnosticsDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SamplingIntervalDiagnosticsDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SamplingIntervalDiagnosticsDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SamplingIntervalDiagnosticsDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SamplingIntervalDiagnosticsDataType, SamplingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SamplingIntervalDiagnosticsDataType, MonitoredItemCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SamplingIntervalDiagnosticsDataType, MaxMonitoredItemCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SamplingIntervalDiagnosticsDataType, DisabledMonitoredItemCount) // offset
    },
};

/*============================================================================
 * Descriptor of the SamplingIntervalDiagnosticsDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType =
{
    "SamplingIntervalDiagnosticsDataType",
    OpcUaId_SamplingIntervalDiagnosticsDataType,
    OpcUaId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultBinary,
    OpcUaId_SamplingIntervalDiagnosticsDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SamplingIntervalDiagnosticsDataType),
    OpcUa_SamplingIntervalDiagnosticsDataType_Initialize,
    OpcUa_SamplingIntervalDiagnosticsDataType_Clear,
    NULL,
    OpcUa_SamplingIntervalDiagnosticsDataType_Encode,
    OpcUa_SamplingIntervalDiagnosticsDataType_Decode,
    sizeof SamplingIntervalDiagnosticsDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SamplingIntervalDiagnosticsDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ServerDiagnosticsSummaryDataType
/*============================================================================
 * OpcUa_ServerDiagnosticsSummaryDataType_Initialize
 *===========================================================================*/
void OpcUa_ServerDiagnosticsSummaryDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServerDiagnosticsSummaryDataType_Clear
 *===========================================================================*/
void OpcUa_ServerDiagnosticsSummaryDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServerDiagnosticsSummaryDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServerDiagnosticsSummaryDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ServerDiagnosticsSummaryDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServerDiagnosticsSummaryDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ServerDiagnosticsSummaryDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ServerDiagnosticsSummaryDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, ServerViewCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, CurrentSessionCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, CumulatedSessionCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, SecurityRejectedSessionCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, RejectedSessionCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, SessionTimeoutCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, SessionAbortCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, CurrentSubscriptionCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, CumulatedSubscriptionCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, PublishingIntervalCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, SecurityRejectedRequestsCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerDiagnosticsSummaryDataType, RejectedRequestsCount) // offset
    },
};

/*============================================================================
 * Descriptor of the ServerDiagnosticsSummaryDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType =
{
    "ServerDiagnosticsSummaryDataType",
    OpcUaId_ServerDiagnosticsSummaryDataType,
    OpcUaId_ServerDiagnosticsSummaryDataType_Encoding_DefaultBinary,
    OpcUaId_ServerDiagnosticsSummaryDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ServerDiagnosticsSummaryDataType),
    OpcUa_ServerDiagnosticsSummaryDataType_Initialize,
    OpcUa_ServerDiagnosticsSummaryDataType_Clear,
    NULL,
    OpcUa_ServerDiagnosticsSummaryDataType_Encode,
    OpcUa_ServerDiagnosticsSummaryDataType_Decode,
    sizeof ServerDiagnosticsSummaryDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ServerDiagnosticsSummaryDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ServerStatusDataType
/*============================================================================
 * OpcUa_ServerStatusDataType_Initialize
 *===========================================================================*/
void OpcUa_ServerStatusDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ServerStatusDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServerStatusDataType_Clear
 *===========================================================================*/
void OpcUa_ServerStatusDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ServerStatusDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServerStatusDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServerStatusDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ServerStatusDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ServerStatusDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServerStatusDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ServerStatusDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ServerStatusDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ServerStatusDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerStatusDataType, StartTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerStatusDataType, CurrentTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerStatusDataType, State) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_BuildInfo, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerStatusDataType, BuildInfo) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerStatusDataType, SecondsTillShutdown) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServerStatusDataType, ShutdownReason) // offset
    },
};

/*============================================================================
 * Descriptor of the ServerStatusDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ServerStatusDataType_EncodeableType =
{
    "ServerStatusDataType",
    OpcUaId_ServerStatusDataType,
    OpcUaId_ServerStatusDataType_Encoding_DefaultBinary,
    OpcUaId_ServerStatusDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ServerStatusDataType),
    OpcUa_ServerStatusDataType_Initialize,
    OpcUa_ServerStatusDataType_Clear,
    NULL,
    OpcUa_ServerStatusDataType_Encode,
    OpcUa_ServerStatusDataType_Decode,
    sizeof ServerStatusDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ServerStatusDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ServiceCounterDataType
/*============================================================================
 * OpcUa_ServiceCounterDataType_Initialize
 *===========================================================================*/
void OpcUa_ServiceCounterDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ServiceCounterDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServiceCounterDataType_Clear
 *===========================================================================*/
void OpcUa_ServiceCounterDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ServiceCounterDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ServiceCounterDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServiceCounterDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ServiceCounterDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ServiceCounterDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ServiceCounterDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ServiceCounterDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ServiceCounterDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ServiceCounterDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServiceCounterDataType, TotalCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ServiceCounterDataType, ErrorCount) // offset
    },
};

/*============================================================================
 * Descriptor of the ServiceCounterDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ServiceCounterDataType_EncodeableType =
{
    "ServiceCounterDataType",
    OpcUaId_ServiceCounterDataType,
    OpcUaId_ServiceCounterDataType_Encoding_DefaultBinary,
    OpcUaId_ServiceCounterDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ServiceCounterDataType),
    OpcUa_ServiceCounterDataType_Initialize,
    OpcUa_ServiceCounterDataType_Clear,
    NULL,
    OpcUa_ServiceCounterDataType_Encode,
    OpcUa_ServiceCounterDataType_Decode,
    sizeof ServiceCounterDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ServiceCounterDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SessionDiagnosticsDataType
/*============================================================================
 * OpcUa_SessionDiagnosticsDataType_Initialize
 *===========================================================================*/
void OpcUa_SessionDiagnosticsDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SessionDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SessionDiagnosticsDataType_Clear
 *===========================================================================*/
void OpcUa_SessionDiagnosticsDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SessionDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SessionDiagnosticsDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SessionDiagnosticsDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SessionDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SessionDiagnosticsDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SessionDiagnosticsDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SessionDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SessionDiagnosticsDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SessionDiagnosticsDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, SessionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, SessionName) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ApplicationDescription, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ClientDescription) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ServerUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, EndpointUrl) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, NoOfLocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, LocaleIds) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ActualSessionTimeout) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, MaxResponseMessageSize) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ClientConnectionTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ClientLastContactTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, CurrentSubscriptionsCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, CurrentMonitoredItemsCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, CurrentPublishRequestsInQueue) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, TotalRequestCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, UnauthorizedRequestCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ReadCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, HistoryReadCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, WriteCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, HistoryUpdateCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, CallCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, CreateMonitoredItemsCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ModifyMonitoredItemsCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, SetMonitoringModeCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, SetTriggeringCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, DeleteMonitoredItemsCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, CreateSubscriptionCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, ModifySubscriptionCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, SetPublishingModeCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, PublishCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, RepublishCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, TransferSubscriptionsCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, DeleteSubscriptionsCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, AddNodesCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, AddReferencesCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, DeleteNodesCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, DeleteReferencesCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, BrowseCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, BrowseNextCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, TranslateBrowsePathsToNodeIdsCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, QueryFirstCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, QueryNextCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, RegisterNodesCount) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_ServiceCounterDataType, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionDiagnosticsDataType, UnregisterNodesCount) // offset
    },
};

/*============================================================================
 * Descriptor of the SessionDiagnosticsDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SessionDiagnosticsDataType_EncodeableType =
{
    "SessionDiagnosticsDataType",
    OpcUaId_SessionDiagnosticsDataType,
    OpcUaId_SessionDiagnosticsDataType_Encoding_DefaultBinary,
    OpcUaId_SessionDiagnosticsDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SessionDiagnosticsDataType),
    OpcUa_SessionDiagnosticsDataType_Initialize,
    OpcUa_SessionDiagnosticsDataType_Clear,
    NULL,
    OpcUa_SessionDiagnosticsDataType_Encode,
    OpcUa_SessionDiagnosticsDataType_Decode,
    sizeof SessionDiagnosticsDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SessionDiagnosticsDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SessionSecurityDiagnosticsDataType
/*============================================================================
 * OpcUa_SessionSecurityDiagnosticsDataType_Initialize
 *===========================================================================*/
void OpcUa_SessionSecurityDiagnosticsDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SessionSecurityDiagnosticsDataType_Clear
 *===========================================================================*/
void OpcUa_SessionSecurityDiagnosticsDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SessionSecurityDiagnosticsDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SessionSecurityDiagnosticsDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SessionSecurityDiagnosticsDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SessionSecurityDiagnosticsDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SessionSecurityDiagnosticsDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SessionSecurityDiagnosticsDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, SessionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, ClientUserIdOfSession) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, NoOfClientUserIdHistory) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, ClientUserIdHistory) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, AuthenticationMechanism) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, Encoding) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, TransportProtocol) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, SecurityMode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, SecurityPolicyUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_ByteString_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SessionSecurityDiagnosticsDataType, ClientCertificate) // offset
    },
};

/*============================================================================
 * Descriptor of the SessionSecurityDiagnosticsDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType =
{
    "SessionSecurityDiagnosticsDataType",
    OpcUaId_SessionSecurityDiagnosticsDataType,
    OpcUaId_SessionSecurityDiagnosticsDataType_Encoding_DefaultBinary,
    OpcUaId_SessionSecurityDiagnosticsDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SessionSecurityDiagnosticsDataType),
    OpcUa_SessionSecurityDiagnosticsDataType_Initialize,
    OpcUa_SessionSecurityDiagnosticsDataType_Clear,
    NULL,
    OpcUa_SessionSecurityDiagnosticsDataType_Encode,
    OpcUa_SessionSecurityDiagnosticsDataType_Decode,
    sizeof SessionSecurityDiagnosticsDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SessionSecurityDiagnosticsDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_StatusResult
/*============================================================================
 * OpcUa_StatusResult_Initialize
 *===========================================================================*/
void OpcUa_StatusResult_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_StatusResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_StatusResult_Clear
 *===========================================================================*/
void OpcUa_StatusResult_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_StatusResult_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_StatusResult_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_StatusResult_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_StatusResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_StatusResult_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_StatusResult_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_StatusResult_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the StatusResult encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor StatusResult_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_StatusCode_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_StatusResult, StatusCode) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DiagnosticInfo_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_StatusResult, DiagnosticInfo) // offset
    },
};

/*============================================================================
 * Descriptor of the StatusResult encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_StatusResult_EncodeableType =
{
    "StatusResult",
    OpcUaId_StatusResult,
    OpcUaId_StatusResult_Encoding_DefaultBinary,
    OpcUaId_StatusResult_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_StatusResult),
    OpcUa_StatusResult_Initialize,
    OpcUa_StatusResult_Clear,
    NULL,
    OpcUa_StatusResult_Encode,
    OpcUa_StatusResult_Decode,
    sizeof StatusResult_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    StatusResult_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SubscriptionDiagnosticsDataType
/*============================================================================
 * OpcUa_SubscriptionDiagnosticsDataType_Initialize
 *===========================================================================*/
void OpcUa_SubscriptionDiagnosticsDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SubscriptionDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SubscriptionDiagnosticsDataType_Clear
 *===========================================================================*/
void OpcUa_SubscriptionDiagnosticsDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SubscriptionDiagnosticsDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SubscriptionDiagnosticsDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SubscriptionDiagnosticsDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SubscriptionDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SubscriptionDiagnosticsDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SubscriptionDiagnosticsDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SubscriptionDiagnosticsDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SubscriptionDiagnosticsDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SubscriptionDiagnosticsDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, SessionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, SubscriptionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, Priority) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, PublishingInterval) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, MaxKeepAliveCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, MaxLifetimeCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, MaxNotificationsPerPublish) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Boolean_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, PublishingEnabled) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, ModifyCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, EnableCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, DisableCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, RepublishRequestCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, RepublishMessageRequestCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, RepublishMessageCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, TransferRequestCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, TransferredToAltClientCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, TransferredToSameClientCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, PublishRequestCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, DataChangeNotificationsCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, EventNotificationsCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, NotificationsCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, LatePublishRequestCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, CurrentKeepAliveCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, CurrentLifetimeCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, UnacknowledgedMessageCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, DiscardedMessageCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, MonitoredItemCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, DisabledMonitoredItemCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, MonitoringQueueOverflowCount) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, NextSequenceNumber) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_UInt32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SubscriptionDiagnosticsDataType, EventQueueOverFlowCount) // offset
    },
};

/*============================================================================
 * Descriptor of the SubscriptionDiagnosticsDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SubscriptionDiagnosticsDataType_EncodeableType =
{
    "SubscriptionDiagnosticsDataType",
    OpcUaId_SubscriptionDiagnosticsDataType,
    OpcUaId_SubscriptionDiagnosticsDataType_Encoding_DefaultBinary,
    OpcUaId_SubscriptionDiagnosticsDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SubscriptionDiagnosticsDataType),
    OpcUa_SubscriptionDiagnosticsDataType_Initialize,
    OpcUa_SubscriptionDiagnosticsDataType_Clear,
    NULL,
    OpcUa_SubscriptionDiagnosticsDataType_Encode,
    OpcUa_SubscriptionDiagnosticsDataType_Decode,
    sizeof SubscriptionDiagnosticsDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SubscriptionDiagnosticsDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ModelChangeStructureDataType
/*============================================================================
 * OpcUa_ModelChangeStructureDataType_Initialize
 *===========================================================================*/
void OpcUa_ModelChangeStructureDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ModelChangeStructureDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModelChangeStructureDataType_Clear
 *===========================================================================*/
void OpcUa_ModelChangeStructureDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ModelChangeStructureDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ModelChangeStructureDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModelChangeStructureDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ModelChangeStructureDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ModelChangeStructureDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ModelChangeStructureDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ModelChangeStructureDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ModelChangeStructureDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ModelChangeStructureDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModelChangeStructureDataType, Affected) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModelChangeStructureDataType, AffectedType) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Byte_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ModelChangeStructureDataType, Verb) // offset
    },
};

/*============================================================================
 * Descriptor of the ModelChangeStructureDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ModelChangeStructureDataType_EncodeableType =
{
    "ModelChangeStructureDataType",
    OpcUaId_ModelChangeStructureDataType,
    OpcUaId_ModelChangeStructureDataType_Encoding_DefaultBinary,
    OpcUaId_ModelChangeStructureDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ModelChangeStructureDataType),
    OpcUa_ModelChangeStructureDataType_Initialize,
    OpcUa_ModelChangeStructureDataType_Clear,
    NULL,
    OpcUa_ModelChangeStructureDataType_Encode,
    OpcUa_ModelChangeStructureDataType_Decode,
    sizeof ModelChangeStructureDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ModelChangeStructureDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_SemanticChangeStructureDataType
/*============================================================================
 * OpcUa_SemanticChangeStructureDataType_Initialize
 *===========================================================================*/
void OpcUa_SemanticChangeStructureDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_SemanticChangeStructureDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SemanticChangeStructureDataType_Clear
 *===========================================================================*/
void OpcUa_SemanticChangeStructureDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_SemanticChangeStructureDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_SemanticChangeStructureDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SemanticChangeStructureDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_SemanticChangeStructureDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_SemanticChangeStructureDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_SemanticChangeStructureDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_SemanticChangeStructureDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the SemanticChangeStructureDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor SemanticChangeStructureDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SemanticChangeStructureDataType, Affected) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_SemanticChangeStructureDataType, AffectedType) // offset
    },
};

/*============================================================================
 * Descriptor of the SemanticChangeStructureDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_SemanticChangeStructureDataType_EncodeableType =
{
    "SemanticChangeStructureDataType",
    OpcUaId_SemanticChangeStructureDataType,
    OpcUaId_SemanticChangeStructureDataType_Encoding_DefaultBinary,
    OpcUaId_SemanticChangeStructureDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_SemanticChangeStructureDataType),
    OpcUa_SemanticChangeStructureDataType_Initialize,
    OpcUa_SemanticChangeStructureDataType_Clear,
    NULL,
    OpcUa_SemanticChangeStructureDataType_Encode,
    OpcUa_SemanticChangeStructureDataType_Decode,
    sizeof SemanticChangeStructureDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    SemanticChangeStructureDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Range
/*============================================================================
 * OpcUa_Range_Initialize
 *===========================================================================*/
void OpcUa_Range_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_Range_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Range_Clear
 *===========================================================================*/
void OpcUa_Range_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_Range_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Range_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Range_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_Range_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_Range_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Range_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_Range_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the Range encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor Range_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Range, Low) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Range, High) // offset
    },
};

/*============================================================================
 * Descriptor of the Range encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_Range_EncodeableType =
{
    "Range",
    OpcUaId_Range,
    OpcUaId_Range_Encoding_DefaultBinary,
    OpcUaId_Range_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_Range),
    OpcUa_Range_Initialize,
    OpcUa_Range_Clear,
    NULL,
    OpcUa_Range_Encode,
    OpcUa_Range_Decode,
    sizeof Range_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    Range_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_EUInformation
/*============================================================================
 * OpcUa_EUInformation_Initialize
 *===========================================================================*/
void OpcUa_EUInformation_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_EUInformation_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EUInformation_Clear
 *===========================================================================*/
void OpcUa_EUInformation_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_EUInformation_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_EUInformation_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EUInformation_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_EUInformation_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_EUInformation_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_EUInformation_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_EUInformation_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the EUInformation encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor EUInformation_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EUInformation, NamespaceUri) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EUInformation, UnitId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EUInformation, DisplayName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_EUInformation, Description) // offset
    },
};

/*============================================================================
 * Descriptor of the EUInformation encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_EUInformation_EncodeableType =
{
    "EUInformation",
    OpcUaId_EUInformation,
    OpcUaId_EUInformation_Encoding_DefaultBinary,
    OpcUaId_EUInformation_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_EUInformation),
    OpcUa_EUInformation_Initialize,
    OpcUa_EUInformation_Clear,
    NULL,
    OpcUa_EUInformation_Encode,
    OpcUa_EUInformation_Decode,
    sizeof EUInformation_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    EUInformation_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ComplexNumberType
/*============================================================================
 * OpcUa_ComplexNumberType_Initialize
 *===========================================================================*/
void OpcUa_ComplexNumberType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ComplexNumberType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ComplexNumberType_Clear
 *===========================================================================*/
void OpcUa_ComplexNumberType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ComplexNumberType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ComplexNumberType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ComplexNumberType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ComplexNumberType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ComplexNumberType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ComplexNumberType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ComplexNumberType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ComplexNumberType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ComplexNumberType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Float_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ComplexNumberType, Real) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Float_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ComplexNumberType, Imaginary) // offset
    },
};

/*============================================================================
 * Descriptor of the ComplexNumberType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ComplexNumberType_EncodeableType =
{
    "ComplexNumberType",
    OpcUaId_ComplexNumberType,
    OpcUaId_ComplexNumberType_Encoding_DefaultBinary,
    OpcUaId_ComplexNumberType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ComplexNumberType),
    OpcUa_ComplexNumberType_Initialize,
    OpcUa_ComplexNumberType_Clear,
    NULL,
    OpcUa_ComplexNumberType_Encode,
    OpcUa_ComplexNumberType_Decode,
    sizeof ComplexNumberType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ComplexNumberType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_DoubleComplexNumberType
/*============================================================================
 * OpcUa_DoubleComplexNumberType_Initialize
 *===========================================================================*/
void OpcUa_DoubleComplexNumberType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_DoubleComplexNumberType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DoubleComplexNumberType_Clear
 *===========================================================================*/
void OpcUa_DoubleComplexNumberType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_DoubleComplexNumberType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_DoubleComplexNumberType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DoubleComplexNumberType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_DoubleComplexNumberType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_DoubleComplexNumberType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_DoubleComplexNumberType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_DoubleComplexNumberType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the DoubleComplexNumberType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor DoubleComplexNumberType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DoubleComplexNumberType, Real) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_DoubleComplexNumberType, Imaginary) // offset
    },
};

/*============================================================================
 * Descriptor of the DoubleComplexNumberType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_DoubleComplexNumberType_EncodeableType =
{
    "DoubleComplexNumberType",
    OpcUaId_DoubleComplexNumberType,
    OpcUaId_DoubleComplexNumberType_Encoding_DefaultBinary,
    OpcUaId_DoubleComplexNumberType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_DoubleComplexNumberType),
    OpcUa_DoubleComplexNumberType_Initialize,
    OpcUa_DoubleComplexNumberType_Clear,
    NULL,
    OpcUa_DoubleComplexNumberType_Encode,
    OpcUa_DoubleComplexNumberType_Decode,
    sizeof DoubleComplexNumberType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    DoubleComplexNumberType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_AxisInformation
/*============================================================================
 * OpcUa_AxisInformation_Initialize
 *===========================================================================*/
void OpcUa_AxisInformation_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_AxisInformation_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AxisInformation_Clear
 *===========================================================================*/
void OpcUa_AxisInformation_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_AxisInformation_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_AxisInformation_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AxisInformation_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_AxisInformation_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_AxisInformation_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_AxisInformation_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_AxisInformation_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the AxisInformation encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor AxisInformation_Fields[] = {
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_EUInformation, // typeIndex
        (uint32_t) offsetof(OpcUa_AxisInformation, EngineeringUnits) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_Range, // typeIndex
        (uint32_t) offsetof(OpcUa_AxisInformation, EURange) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_LocalizedText_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AxisInformation, Title) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AxisInformation, AxisScaleType) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AxisInformation, NoOfAxisSteps) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_AxisInformation, AxisSteps) // offset
    },
};

/*============================================================================
 * Descriptor of the AxisInformation encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_AxisInformation_EncodeableType =
{
    "AxisInformation",
    OpcUaId_AxisInformation,
    OpcUaId_AxisInformation_Encoding_DefaultBinary,
    OpcUaId_AxisInformation_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_AxisInformation),
    OpcUa_AxisInformation_Initialize,
    OpcUa_AxisInformation_Clear,
    NULL,
    OpcUa_AxisInformation_Encode,
    OpcUa_AxisInformation_Decode,
    sizeof AxisInformation_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    AxisInformation_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_XVType
/*============================================================================
 * OpcUa_XVType_Initialize
 *===========================================================================*/
void OpcUa_XVType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_XVType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_XVType_Clear
 *===========================================================================*/
void OpcUa_XVType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_XVType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_XVType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_XVType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_XVType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_XVType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_XVType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_XVType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the XVType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor XVType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Double_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_XVType, X) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Float_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_XVType, Value) // offset
    },
};

/*============================================================================
 * Descriptor of the XVType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_XVType_EncodeableType =
{
    "XVType",
    OpcUaId_XVType,
    OpcUaId_XVType_Encoding_DefaultBinary,
    OpcUaId_XVType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_XVType),
    OpcUa_XVType_Initialize,
    OpcUa_XVType_Clear,
    NULL,
    OpcUa_XVType_Encode,
    OpcUa_XVType_Decode,
    sizeof XVType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    XVType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_ProgramDiagnosticDataType
/*============================================================================
 * OpcUa_ProgramDiagnosticDataType_Initialize
 *===========================================================================*/
void OpcUa_ProgramDiagnosticDataType_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_ProgramDiagnosticDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ProgramDiagnosticDataType_Clear
 *===========================================================================*/
void OpcUa_ProgramDiagnosticDataType_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_ProgramDiagnosticDataType_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_ProgramDiagnosticDataType_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ProgramDiagnosticDataType_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_ProgramDiagnosticDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_ProgramDiagnosticDataType_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_ProgramDiagnosticDataType_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_ProgramDiagnosticDataType_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the ProgramDiagnosticDataType encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor ProgramDiagnosticDataType_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, CreateSessionId) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, CreateClientName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, InvocationCreationTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastTransitionTime) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastMethodCall) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_NodeId_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastMethodSessionId) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, NoOfLastMethodInputArguments) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_Argument, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastMethodInputArguments) // offset
    },
    {
        true,  // isBuiltIn
        true, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_Int32_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, NoOfLastMethodOutputArguments) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_Argument, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastMethodOutputArguments) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastMethodCallTime) // offset
    },
    {
        false,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_TypeInternalIndex_StatusResult, // typeIndex
        (uint32_t) offsetof(OpcUa_ProgramDiagnosticDataType, LastMethodReturnStatus) // offset
    },
};

/*============================================================================
 * Descriptor of the ProgramDiagnosticDataType encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_ProgramDiagnosticDataType_EncodeableType =
{
    "ProgramDiagnosticDataType",
    OpcUaId_ProgramDiagnosticDataType,
    OpcUaId_ProgramDiagnosticDataType_Encoding_DefaultBinary,
    OpcUaId_ProgramDiagnosticDataType_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_ProgramDiagnosticDataType),
    OpcUa_ProgramDiagnosticDataType_Initialize,
    OpcUa_ProgramDiagnosticDataType_Clear,
    NULL,
    OpcUa_ProgramDiagnosticDataType_Encode,
    OpcUa_ProgramDiagnosticDataType_Decode,
    sizeof ProgramDiagnosticDataType_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    ProgramDiagnosticDataType_Fields
};
#endif

#ifndef OPCUA_EXCLUDE_Annotation
/*============================================================================
 * OpcUa_Annotation_Initialize
 *===========================================================================*/
void OpcUa_Annotation_Initialize(void* pValue)
{
    SOPC_EncodeableObject_Initialize(&OpcUa_Annotation_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Annotation_Clear
 *===========================================================================*/
void OpcUa_Annotation_Clear(void* pValue)
{
    SOPC_EncodeableObject_Clear(&OpcUa_Annotation_EncodeableType, pValue);
}

/*============================================================================
 * OpcUa_Annotation_Encode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Annotation_Encode(const void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Encode(&OpcUa_Annotation_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * OpcUa_Annotation_Decode
 *===========================================================================*/
SOPC_ReturnStatus OpcUa_Annotation_Decode(void* pValue, SOPC_Buffer* buf, uint32_t nestedStructLevel)
{
    return SOPC_EncodeableObject_Decode(&OpcUa_Annotation_EncodeableType, pValue, buf, nestedStructLevel);
}

/*============================================================================
 * Field descriptors of the Annotation encodeable type.
 *===========================================================================*/
static const SOPC_EncodeableType_FieldDescriptor Annotation_Fields[] = {
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Annotation, Message) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_String_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Annotation, UserName) // offset
    },
    {
        true,  // isBuiltIn
        false, // isArrayLength
        true, // isToEncode
        (uint32_t) SOPC_DateTime_Id, // typeIndex
        (uint32_t) offsetof(OpcUa_Annotation, AnnotationTime) // offset
    },
};

/*============================================================================
 * Descriptor of the Annotation encodeable type.
 *===========================================================================*/
SOPC_EncodeableType OpcUa_Annotation_EncodeableType =
{
    "Annotation",
    OpcUaId_Annotation,
    OpcUaId_Annotation_Encoding_DefaultBinary,
    OpcUaId_Annotation_Encoding_DefaultXml,
    NULL,
    sizeof(OpcUa_Annotation),
    OpcUa_Annotation_Initialize,
    OpcUa_Annotation_Clear,
    NULL,
    OpcUa_Annotation_Encode,
    OpcUa_Annotation_Decode,
    sizeof Annotation_Fields / sizeof(SOPC_EncodeableType_FieldDescriptor),
    Annotation_Fields
};
#endif

/*============================================================================
 * Table of known types.
 *===========================================================================*/
static SOPC_EncodeableType* g_KnownEncodeableTypes[SOPC_TypeInternalIndex_SIZE + 1] = {
#ifndef OPCUA_EXCLUDE_ReferenceNode
    &OpcUa_ReferenceNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Node
    &OpcUa_Node_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_InstanceNode
    &OpcUa_InstanceNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_TypeNode
    &OpcUa_TypeNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ObjectNode
    &OpcUa_ObjectNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ObjectTypeNode
    &OpcUa_ObjectTypeNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_VariableNode
    &OpcUa_VariableNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_VariableTypeNode
    &OpcUa_VariableTypeNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReferenceTypeNode
    &OpcUa_ReferenceTypeNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MethodNode
    &OpcUa_MethodNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ViewNode
    &OpcUa_ViewNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DataTypeNode
    &OpcUa_DataTypeNode_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Argument
    &OpcUa_Argument_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EnumValueType
    &OpcUa_EnumValueType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EnumField
    &OpcUa_EnumField_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_OptionSet
    &OpcUa_OptionSet_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_TimeZoneDataType
    &OpcUa_TimeZoneDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ApplicationDescription
    &OpcUa_ApplicationDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RequestHeader
    &OpcUa_RequestHeader_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ResponseHeader
    &OpcUa_ResponseHeader_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ServiceFault
    &OpcUa_ServiceFault_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_FindServers
#ifndef OPCUA_EXCLUDE_FindServersRequest
    &OpcUa_FindServersRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_FindServersResponse
    &OpcUa_FindServersResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_ServerOnNetwork
    &OpcUa_ServerOnNetwork_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_FindServersOnNetwork
#ifndef OPCUA_EXCLUDE_FindServersOnNetworkRequest
    &OpcUa_FindServersOnNetworkRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_FindServersOnNetworkResponse
    &OpcUa_FindServersOnNetworkResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_UserTokenPolicy
    &OpcUa_UserTokenPolicy_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EndpointDescription
    &OpcUa_EndpointDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_GetEndpoints
#ifndef OPCUA_EXCLUDE_GetEndpointsRequest
    &OpcUa_GetEndpointsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_GetEndpointsResponse
    &OpcUa_GetEndpointsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_RegisteredServer
    &OpcUa_RegisteredServer_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RegisterServer
#ifndef OPCUA_EXCLUDE_RegisterServerRequest
    &OpcUa_RegisterServerRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RegisterServerResponse
    &OpcUa_RegisterServerResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_MdnsDiscoveryConfiguration
    &OpcUa_MdnsDiscoveryConfiguration_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RegisterServer2
#ifndef OPCUA_EXCLUDE_RegisterServer2Request
    &OpcUa_RegisterServer2Request_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RegisterServer2Response
    &OpcUa_RegisterServer2Response_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_ChannelSecurityToken
    &OpcUa_ChannelSecurityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_OpenSecureChannel
#ifndef OPCUA_EXCLUDE_OpenSecureChannelRequest
    &OpcUa_OpenSecureChannelRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_OpenSecureChannelResponse
    &OpcUa_OpenSecureChannelResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_CloseSecureChannel
#ifndef OPCUA_EXCLUDE_CloseSecureChannelRequest
    &OpcUa_CloseSecureChannelRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CloseSecureChannelResponse
    &OpcUa_CloseSecureChannelResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_SignedSoftwareCertificate
    &OpcUa_SignedSoftwareCertificate_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SignatureData
    &OpcUa_SignatureData_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CreateSession
#ifndef OPCUA_EXCLUDE_CreateSessionRequest
    &OpcUa_CreateSessionRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CreateSessionResponse
    &OpcUa_CreateSessionResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_UserIdentityToken
    &OpcUa_UserIdentityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AnonymousIdentityToken
    &OpcUa_AnonymousIdentityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_UserNameIdentityToken
    &OpcUa_UserNameIdentityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_X509IdentityToken
    &OpcUa_X509IdentityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_KerberosIdentityToken
    &OpcUa_KerberosIdentityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_IssuedIdentityToken
    &OpcUa_IssuedIdentityToken_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ActivateSession
#ifndef OPCUA_EXCLUDE_ActivateSessionRequest
    &OpcUa_ActivateSessionRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ActivateSessionResponse
    &OpcUa_ActivateSessionResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_CloseSession
#ifndef OPCUA_EXCLUDE_CloseSessionRequest
    &OpcUa_CloseSessionRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CloseSessionResponse
    &OpcUa_CloseSessionResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_Cancel
#ifndef OPCUA_EXCLUDE_CancelRequest
    &OpcUa_CancelRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CancelResponse
    &OpcUa_CancelResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_NodeAttributes
    &OpcUa_NodeAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ObjectAttributes
    &OpcUa_ObjectAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_VariableAttributes
    &OpcUa_VariableAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MethodAttributes
    &OpcUa_MethodAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ObjectTypeAttributes
    &OpcUa_ObjectTypeAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_VariableTypeAttributes
    &OpcUa_VariableTypeAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReferenceTypeAttributes
    &OpcUa_ReferenceTypeAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DataTypeAttributes
    &OpcUa_DataTypeAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ViewAttributes
    &OpcUa_ViewAttributes_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AddNodesItem
    &OpcUa_AddNodesItem_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AddNodesResult
    &OpcUa_AddNodesResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AddNodes
#ifndef OPCUA_EXCLUDE_AddNodesRequest
    &OpcUa_AddNodesRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AddNodesResponse
    &OpcUa_AddNodesResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_AddReferencesItem
    &OpcUa_AddReferencesItem_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AddReferences
#ifndef OPCUA_EXCLUDE_AddReferencesRequest
    &OpcUa_AddReferencesRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AddReferencesResponse
    &OpcUa_AddReferencesResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_DeleteNodesItem
    &OpcUa_DeleteNodesItem_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteNodes
#ifndef OPCUA_EXCLUDE_DeleteNodesRequest
    &OpcUa_DeleteNodesRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteNodesResponse
    &OpcUa_DeleteNodesResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_DeleteReferencesItem
    &OpcUa_DeleteReferencesItem_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteReferences
#ifndef OPCUA_EXCLUDE_DeleteReferencesRequest
    &OpcUa_DeleteReferencesRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteReferencesResponse
    &OpcUa_DeleteReferencesResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_ViewDescription
    &OpcUa_ViewDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowseDescription
    &OpcUa_BrowseDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReferenceDescription
    &OpcUa_ReferenceDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowseResult
    &OpcUa_BrowseResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Browse
#ifndef OPCUA_EXCLUDE_BrowseRequest
    &OpcUa_BrowseRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowseResponse
    &OpcUa_BrowseResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_BrowseNext
#ifndef OPCUA_EXCLUDE_BrowseNextRequest
    &OpcUa_BrowseNextRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowseNextResponse
    &OpcUa_BrowseNextResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_RelativePathElement
    &OpcUa_RelativePathElement_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RelativePath
    &OpcUa_RelativePath_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowsePath
    &OpcUa_BrowsePath_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowsePathTarget
    &OpcUa_BrowsePathTarget_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_BrowsePathResult
    &OpcUa_BrowsePathResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIds
#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIdsRequest
    &OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_TranslateBrowsePathsToNodeIdsResponse
    &OpcUa_TranslateBrowsePathsToNodeIdsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_RegisterNodes
#ifndef OPCUA_EXCLUDE_RegisterNodesRequest
    &OpcUa_RegisterNodesRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RegisterNodesResponse
    &OpcUa_RegisterNodesResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_UnregisterNodes
#ifndef OPCUA_EXCLUDE_UnregisterNodesRequest
    &OpcUa_UnregisterNodesRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_UnregisterNodesResponse
    &OpcUa_UnregisterNodesResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_EndpointConfiguration
    &OpcUa_EndpointConfiguration_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SupportedProfile
    &OpcUa_SupportedProfile_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SoftwareCertificate
    &OpcUa_SoftwareCertificate_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_QueryDataDescription
    &OpcUa_QueryDataDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_NodeTypeDescription
    &OpcUa_NodeTypeDescription_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_QueryDataSet
    &OpcUa_QueryDataSet_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_NodeReference
    &OpcUa_NodeReference_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ContentFilterElement
    &OpcUa_ContentFilterElement_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ContentFilter
    &OpcUa_ContentFilter_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ElementOperand
    &OpcUa_ElementOperand_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_LiteralOperand
    &OpcUa_LiteralOperand_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AttributeOperand
    &OpcUa_AttributeOperand_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SimpleAttributeOperand
    &OpcUa_SimpleAttributeOperand_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ContentFilterElementResult
    &OpcUa_ContentFilterElementResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ContentFilterResult
    &OpcUa_ContentFilterResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ParsingResult
    &OpcUa_ParsingResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_QueryFirst
#ifndef OPCUA_EXCLUDE_QueryFirstRequest
    &OpcUa_QueryFirstRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_QueryFirstResponse
    &OpcUa_QueryFirstResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_QueryNext
#ifndef OPCUA_EXCLUDE_QueryNextRequest
    &OpcUa_QueryNextRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_QueryNextResponse
    &OpcUa_QueryNextResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_ReadValueId
    &OpcUa_ReadValueId_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Read
#ifndef OPCUA_EXCLUDE_ReadRequest
    &OpcUa_ReadRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReadResponse
    &OpcUa_ReadResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_HistoryReadValueId
    &OpcUa_HistoryReadValueId_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryReadResult
    &OpcUa_HistoryReadResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EventFilter
    &OpcUa_EventFilter_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReadEventDetails
    &OpcUa_ReadEventDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReadRawModifiedDetails
    &OpcUa_ReadRawModifiedDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AggregateConfiguration
    &OpcUa_AggregateConfiguration_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReadProcessedDetails
    &OpcUa_ReadProcessedDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ReadAtTimeDetails
    &OpcUa_ReadAtTimeDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryData
    &OpcUa_HistoryData_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ModificationInfo
    &OpcUa_ModificationInfo_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryModifiedData
    &OpcUa_HistoryModifiedData_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryEventFieldList
    &OpcUa_HistoryEventFieldList_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryEvent
    &OpcUa_HistoryEvent_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryRead
#ifndef OPCUA_EXCLUDE_HistoryReadRequest
    &OpcUa_HistoryReadRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryReadResponse
    &OpcUa_HistoryReadResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_WriteValue
    &OpcUa_WriteValue_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Write
#ifndef OPCUA_EXCLUDE_WriteRequest
    &OpcUa_WriteRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_WriteResponse
    &OpcUa_WriteResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_HistoryUpdateDetails
    &OpcUa_HistoryUpdateDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_UpdateDataDetails
    &OpcUa_UpdateDataDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_UpdateStructureDataDetails
    &OpcUa_UpdateStructureDataDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_UpdateEventDetails
    &OpcUa_UpdateEventDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteRawModifiedDetails
    &OpcUa_DeleteRawModifiedDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteAtTimeDetails
    &OpcUa_DeleteAtTimeDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteEventDetails
    &OpcUa_DeleteEventDetails_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryUpdateResult
    &OpcUa_HistoryUpdateResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryUpdate
#ifndef OPCUA_EXCLUDE_HistoryUpdateRequest
    &OpcUa_HistoryUpdateRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_HistoryUpdateResponse
    &OpcUa_HistoryUpdateResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_CallMethodRequest
    &OpcUa_CallMethodRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CallMethodResult
    &OpcUa_CallMethodResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Call
#ifndef OPCUA_EXCLUDE_CallRequest
    &OpcUa_CallRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CallResponse
    &OpcUa_CallResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_DataChangeFilter
    &OpcUa_DataChangeFilter_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AggregateFilter
    &OpcUa_AggregateFilter_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EventFilterResult
    &OpcUa_EventFilterResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AggregateFilterResult
    &OpcUa_AggregateFilterResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MonitoringParameters
    &OpcUa_MonitoringParameters_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MonitoredItemCreateRequest
    &OpcUa_MonitoredItemCreateRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MonitoredItemCreateResult
    &OpcUa_MonitoredItemCreateResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CreateMonitoredItems
#ifndef OPCUA_EXCLUDE_CreateMonitoredItemsRequest
    &OpcUa_CreateMonitoredItemsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CreateMonitoredItemsResponse
    &OpcUa_CreateMonitoredItemsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_MonitoredItemModifyRequest
    &OpcUa_MonitoredItemModifyRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MonitoredItemModifyResult
    &OpcUa_MonitoredItemModifyResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ModifyMonitoredItems
#ifndef OPCUA_EXCLUDE_ModifyMonitoredItemsRequest
    &OpcUa_ModifyMonitoredItemsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ModifyMonitoredItemsResponse
    &OpcUa_ModifyMonitoredItemsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_SetMonitoringMode
#ifndef OPCUA_EXCLUDE_SetMonitoringModeRequest
    &OpcUa_SetMonitoringModeRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SetMonitoringModeResponse
    &OpcUa_SetMonitoringModeResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_SetTriggering
#ifndef OPCUA_EXCLUDE_SetTriggeringRequest
    &OpcUa_SetTriggeringRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SetTriggeringResponse
    &OpcUa_SetTriggeringResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItems
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItemsRequest
    &OpcUa_DeleteMonitoredItemsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteMonitoredItemsResponse
    &OpcUa_DeleteMonitoredItemsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_CreateSubscription
#ifndef OPCUA_EXCLUDE_CreateSubscriptionRequest
    &OpcUa_CreateSubscriptionRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_CreateSubscriptionResponse
    &OpcUa_CreateSubscriptionResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_ModifySubscription
#ifndef OPCUA_EXCLUDE_ModifySubscriptionRequest
    &OpcUa_ModifySubscriptionRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ModifySubscriptionResponse
    &OpcUa_ModifySubscriptionResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_SetPublishingMode
#ifndef OPCUA_EXCLUDE_SetPublishingModeRequest
    &OpcUa_SetPublishingModeRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SetPublishingModeResponse
    &OpcUa_SetPublishingModeResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_NotificationMessage
    &OpcUa_NotificationMessage_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_MonitoredItemNotification
    &OpcUa_MonitoredItemNotification_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DataChangeNotification
    &OpcUa_DataChangeNotification_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EventFieldList
    &OpcUa_EventFieldList_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EventNotificationList
    &OpcUa_EventNotificationList_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_StatusChangeNotification
    &OpcUa_StatusChangeNotification_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SubscriptionAcknowledgement
    &OpcUa_SubscriptionAcknowledgement_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Publish
#ifndef OPCUA_EXCLUDE_PublishRequest
    &OpcUa_PublishRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_PublishResponse
    &OpcUa_PublishResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_Republish
#ifndef OPCUA_EXCLUDE_RepublishRequest
    &OpcUa_RepublishRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RepublishResponse
    &OpcUa_RepublishResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_TransferResult
    &OpcUa_TransferResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_TransferSubscriptions
#ifndef OPCUA_EXCLUDE_TransferSubscriptionsRequest
    &OpcUa_TransferSubscriptionsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_TransferSubscriptionsResponse
    &OpcUa_TransferSubscriptionsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_DeleteSubscriptions
#ifndef OPCUA_EXCLUDE_DeleteSubscriptionsRequest
    &OpcUa_DeleteSubscriptionsRequest_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DeleteSubscriptionsResponse
    &OpcUa_DeleteSubscriptionsResponse_EncodeableType,
#endif
#endif
#ifndef OPCUA_EXCLUDE_BuildInfo
    &OpcUa_BuildInfo_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_RedundantServerDataType
    &OpcUa_RedundantServerDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EndpointUrlListDataType
    &OpcUa_EndpointUrlListDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_NetworkGroupDataType
    &OpcUa_NetworkGroupDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SamplingIntervalDiagnosticsDataType
    &OpcUa_SamplingIntervalDiagnosticsDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ServerDiagnosticsSummaryDataType
    &OpcUa_ServerDiagnosticsSummaryDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ServerStatusDataType
    &OpcUa_ServerStatusDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ServiceCounterDataType
    &OpcUa_ServiceCounterDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SessionDiagnosticsDataType
    &OpcUa_SessionDiagnosticsDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SessionSecurityDiagnosticsDataType
    &OpcUa_SessionSecurityDiagnosticsDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_StatusResult
    &OpcUa_StatusResult_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SubscriptionDiagnosticsDataType
    &OpcUa_SubscriptionDiagnosticsDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ModelChangeStructureDataType
    &OpcUa_ModelChangeStructureDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_SemanticChangeStructureDataType
    &OpcUa_SemanticChangeStructureDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Range
    &OpcUa_Range_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_EUInformation
    &OpcUa_EUInformation_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ComplexNumberType
    &OpcUa_ComplexNumberType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_DoubleComplexNumberType
    &OpcUa_DoubleComplexNumberType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_AxisInformation
    &OpcUa_AxisInformation_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_XVType
    &OpcUa_XVType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_ProgramDiagnosticDataType
    &OpcUa_ProgramDiagnosticDataType_EncodeableType,
#endif
#ifndef OPCUA_EXCLUDE_Annotation
    &OpcUa_Annotation_EncodeableType,
#endif
    NULL
};

SOPC_EncodeableType** SOPC_KnownEncodeableTypes = g_KnownEncodeableTypes;

void SOPC_Initialize_EnumeratedType(int32_t* enumerationValue)
{
    *enumerationValue = 0;
}

void SOPC_Clear_EnumeratedType(int32_t* enumerationValue)
{
    *enumerationValue = 0;
}

SOPC_ReturnStatus SOPC_Read_EnumeratedType(SOPC_Buffer* buffer, int32_t* enumerationValue, uint32_t nestedStructLevel)
{
    return SOPC_Int32_Read(enumerationValue, buffer, nestedStructLevel);
}

SOPC_ReturnStatus SOPC_Write_EnumeratedType(SOPC_Buffer* buffer, const int32_t* enumerationValue, uint32_t nestedStructLevel)
{
    return SOPC_Int32_Write(enumerationValue, buffer, nestedStructLevel);
}

/* This is the last line of an autogenerated file. */
