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

MACHINE
    address_space

SEES
    constants,
    constants_statuscodes_bs,
    service_write_decode_bs /* TODO: move to refinment */

DEFINITIONS
    "definitions.def";

    d_variables ==
        /* Attributes (mandatory) */
        a_NodeId,
        a_NodeClass,
        a_BrowseName,
        a_DisplayName,
        a_Value,
        a_Value_StatusCode,
        a_Value_SourceTimestamp,
        a_IsAbstract,
        a_EventNotifier,
        a_DataType,
        a_ValueRank,
        a_ArrayDimensions,
        a_AccessLevel,
        a_UserAccessLevel,
        a_Historizing,
        a_Executable,
        a_UserExecutable,
        a_ContainsNoLoops,
        a_Symmetric,

        /* Types */
        Type_IsTransitiveSubtype,
        Type_IsReferenceTypeIdValid,
        
       	/* Objects */
       	Object_HasMethod,
       	
        Variant_LocalDataType,
        Variant_ValueRank,
        
        /* References */
        Reference_SourceNode,
        Reference_ReferenceType,
        Reference_TargetNode,
        Reference_IsForward,

        Node_Reference,
        Node_RefIndexEnd,
        RefIndex_Reference,

        IsRangeDefined,
        IsValid_VariantIndex,
        HasRange_VariantIndex,
        
        /* Local treament */
        local_service_treatment,

        /* Service Write */
        ResponseWrite_allocated,
        ResponseWrite_StatusCode,

        /* A special reference, that we model because it is used by Browse.
         * This is the content of the TargetNode of all Variables and Objects. */
        Ref_HasTypeDefinition,

        /* User authorization */
        s_AuthorizedOperations

    ;

    d_inv ==
    (
        /* Node attributes */
        a_NodeId      : t_Node >-> t_NodeId        &
        a_NodeClass   : t_Node --> t_NodeClass     &
        a_BrowseName  : t_Node --> t_QualifiedName &
        a_DisplayName : t_Node --> t_LocalizedText &

        a_Value : t_Node +-> t_Variant &
        dom(a_NodeClass|>{e_ncl_Variable}) <: dom(a_Value) &
        dom(a_Value) <: dom(a_NodeClass|>{e_ncl_Variable, e_ncl_VariableType}) &
        dom(a_NodeClass|>{e_ncl_Variable}) <: dom(a_Value) & /* All Variable have value but not all VariableType */

        /* + Value attribute meta-data */
        a_Value_StatusCode : a_NodeClass~[{e_ncl_Variable}] --> t_RawStatusCode &

        a_Value_SourceTimestamp : a_NodeClass~[{e_ncl_Variable}] --> t_Timestamp &

        a_IsAbstract : a_NodeClass~[{e_ncl_ObjectType, e_ncl_VariableType, e_ncl_ReferenceType, e_ncl_DataType}] --> BOOL &

        a_EventNotifier : a_NodeClass~[{e_ncl_Object, e_ncl_View}] --> t_Byte &

        a_DataType : a_NodeClass~[{e_ncl_Variable, e_ncl_VariableType}] --> t_NodeId &

        a_ValueRank : a_NodeClass~[{e_ncl_Variable, e_ncl_VariableType}] --> t_ValueRank &

        a_ArrayDimensions : a_NodeClass~[{e_ncl_Variable, e_ncl_VariableType}] --> t_ArrayDimensions &

        a_AccessLevel : a_NodeClass~[{e_ncl_Variable}] --> t_access_level &

        a_UserAccessLevel : a_NodeClass~[{e_ncl_Variable}] --> t_access_level &

        a_Historizing : a_NodeClass~[{e_ncl_Variable}] --> BOOL &

        a_Executable : a_NodeClass~[{e_ncl_Method}] --> BOOL &

        a_UserExecutable : a_NodeClass~[{e_ncl_Method}] --> BOOL &

        a_ContainsNoLoops : a_NodeClass~[{e_ncl_View}] --> BOOL &

        a_Symmetric : a_NodeClass~[{e_ncl_ReferenceType}] --> BOOL &

        /* Types */
        Type_IsTransitiveSubtype : t_NodeId <-> t_NodeId &
        Type_IsReferenceTypeIdValid <: t_NodeId &
        
        /* Objects */
        Object_HasMethod : t_NodeId <-> t_NodeId &

        Variant_LocalDataType : t_Variant --> t_NodeId &
        Variant_ValueRank : t_Variant --> t_ConcreteValueRank &

        /* Special reference (see def) */
        Ref_HasTypeDefinition : t_Node +-> t_ExpandedNodeId &
        dom(Ref_HasTypeDefinition) = dom(a_NodeClass |> {e_ncl_Variable, e_ncl_Object}) &

        /* References */
        Reference_SourceNode    : t_Reference --> t_NodeId         &
        Reference_ReferenceType : t_Reference --> t_NodeId         &
        Reference_TargetNode    : t_Reference --> t_ExpandedNodeId &
        Reference_IsForward     : t_Reference --> BOOL             &

        Node_Reference          : t_Node     <-> t_Reference &
        Node_RefIndexEnd        : t_Node     --> t_RefIndex  &
        RefIndex_Reference      : t_Node * t_RefIndex --> t_Reference &

        IsRangeDefined : t_IndexRange_i --> BOOL &
        IsValid_VariantIndex : t_Variant * t_IndexRange_i --> BOOL &
        HasRange_VariantIndex  : t_Variant * t_IndexRange_i --> BOOL &

        /* Local treatment */
        local_service_treatment : NAT &

        /* Service Write */
        ResponseWrite_allocated : BOOL &
        ResponseWrite_StatusCode : t_WriteValue +-> t_StatusCode &
        (ResponseWrite_allocated = FALSE
         =>
         ResponseWrite_StatusCode = {}) &

        /* User authorization */
        s_AuthorizedOperations <: t_operation_type * t_NodeId * t_AttributeId * t_user
    )

ABSTRACT_VARIABLES
    d_variables

INVARIANT
    d_inv

INITIALISATION
    d_variables
    :(
        d_inv
    )

OPERATIONS

    /* a_NodeClass(node) and any_attribute(node) */
    sc, val, val_sc, val_ts_src, val_ts_srv <-- read_Node_Attribute(p_user, p_locales, p_node, p_nid, p_aid, p_index_range) =
    PRE
        p_user : t_user_i &
        p_user : t_user   &
        p_locales  : t_LocaleIds_i &
        p_locales  : t_LocaleIds   &
        p_node : t_Node_i &
        p_node : t_Node &
        p_nid : t_NodeId_i &
        p_nid : t_NodeId &
        p_nid = a_NodeId(p_node) &
        p_aid : t_AttributeId_i &
        p_aid : t_AttributeId &
        p_index_range : t_IndexRange_i
    THEN
        LET ncl BE ncl = a_NodeClass(p_node) IN
        sc,
        val,
        val_sc,
        val_ts_src,
        val_ts_srv
        :(sc : t_StatusCode_i &
          sc : t_StatusCode &
          val : t_Variant_i &
          val_sc : t_RawStatusCode &
          val_ts_src : t_Timestamp &
          val_ts_srv : t_Timestamp &
          (p_node : dom(AttributeID_Node_Variant(p_aid))
           =>
           /* Specific treatement for Value of Variable attribute: check access rights + index range */
           (ncl = e_ncl_Variable & p_aid = e_aid_Value =>
             (local_service_treatment = 0 &
              conv_AccessLevel_CurrentRead(a_AccessLevel(p_node)) = FALSE =>
               val = c_Variant_indet &
               sc = e_sc_bad_not_readable) &
             (local_service_treatment = 0 &
              conv_AccessLevel_CurrentRead(a_AccessLevel(p_node)) = TRUE &
              not(e_operation_type_read |-> p_nid |-> p_aid |-> p_user : s_AuthorizedOperations) =>
                 val = c_Variant_indet &
                 sc = e_sc_bad_user_access_denied) &

             (local_service_treatment /= 0 or
              (conv_AccessLevel_CurrentRead(a_AccessLevel(p_node)) = TRUE &
               e_operation_type_read |-> p_nid |-> p_aid |-> p_user : s_AuthorizedOperations) &
              IsValid_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = FALSE =>
                 val = c_Variant_indet &
                 sc = e_sc_bad_index_range_invalid
             ) &

             (local_service_treatment /= 0 or
              (conv_AccessLevel_CurrentRead(a_AccessLevel(p_node)) = TRUE &
               e_operation_type_read |-> p_nid |-> p_aid |-> p_user : s_AuthorizedOperations) &
               IsValid_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = TRUE &
               HasRange_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = FALSE  =>
                 val = c_Variant_indet &
                 sc = e_sc_bad_index_range_no_data
             ) &

             (local_service_treatment /= 0 or
              (conv_AccessLevel_CurrentRead(a_AccessLevel(p_node)) = TRUE &
               e_operation_type_read |-> p_nid |-> p_aid |-> p_user : s_AuthorizedOperations) &
               IsValid_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = TRUE &
               HasRange_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = TRUE
              =>
                (val = AttributeID_Node_Variant(p_aid)(p_node) &
                sc = e_sc_ok) or
                (val = c_Variant_indet &
                  sc = e_sc_bad_out_of_memory)
             )

           ) &
           /* Specific treatement for Value of VariableType attribute: check index range */
           (not(ncl = e_ncl_Variable & p_aid = e_aid_Value) &
               ncl = e_ncl_VariableType & p_aid = e_aid_Value =>
               (IsValid_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = FALSE =>
                 sc = e_sc_bad_index_range_invalid
               ) &
               (IsValid_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = TRUE &
                HasRange_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = FALSE =>
                 sc = e_sc_bad_index_range_no_data
               ) &
               (IsValid_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = TRUE &
                HasRange_VariantIndex(AttributeID_Node_Variant(e_aid_Value)(p_node) |-> p_index_range) = TRUE =>
                (val = AttributeID_Node_Variant(p_aid)(p_node) &
                 sc = e_sc_ok) or
                (val = c_Variant_indet &
                  sc = e_sc_bad_out_of_memory)
                )
           ) &
           /* Generic treatment for all other attributes */
           (not(ncl = e_ncl_Variable & p_aid = e_aid_Value) &
             not(ncl = e_ncl_VariableType & p_aid = e_aid_Value) =>
               /* Other attributes are not expecting a defined index range */
               (IsRangeDefined(p_index_range) = TRUE =>
                 val = c_Variant_indet &
                 sc = e_sc_bad_index_range_invalid) &
               /* Nominal case */
               (IsRangeDefined(p_index_range) = FALSE =>
                (val = AttributeID_Node_Variant(p_aid)(p_node) &
                 sc = e_sc_ok) or
                 (val = c_Variant_indet &
                  sc = e_sc_bad_out_of_memory))
          ) &
          /* Specific treatement for status code and timestamps for Variable Value */
          (sc = e_sc_ok & ncl = e_ncl_Variable & p_aid = e_aid_Value =>
           val_sc = a_Value_StatusCode(p_node) &
           val_ts_src = a_Value_SourceTimestamp(p_node) &
           val_ts_srv /= c_Timestamp_null /* current date on S2OPC server*/ ) &
          /* Generic treatement for status code and timestamps     */
          (sc = e_sc_ok & not (ncl = e_ncl_Variable & p_aid = e_aid_Value) =>
           val_sc = c_RawStatusCode_Good &
           val_ts_src = c_Timestamp_null &
           val_ts_srv /= c_Timestamp_null /* current date on S2OPC server*/)
          ) &
          /* Invalid attribute for the given node */
          (not(p_node : dom(AttributeID_Node_Variant(p_aid)))
           =>
           val = c_Variant_indet &
           sc = e_sc_bad_attribute_id_invalid &
           val_sc = c_RawStatusCode_BadInvalidState &
           val_ts_src = c_Timestamp_null &
           val_ts_srv = c_Timestamp_null
          )
       )
    END /* LET END */
    END
    ;

    /* Promoted */
    /* a_NodeId~ */
    nid_valid, node <-- readall_AddressSpace_Node(nid) =
    PRE
        nid : t_NodeId_i
    THEN
        IF  nid : ran(a_NodeId) THEN
            nid_valid := TRUE ||
            node :( node : t_Node_i & node|->nid : a_NodeId )
        ELSE
            nid_valid := FALSE ||
            node := c_Node_indet
        END
    END
    ;

    p_node_class <-- get_NodeClass(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : t_Node
    THEN
        p_node_class :(p_node_class : t_NodeClass_i &
                       p_node_class = a_NodeClass(p_node))
    END
    ;

    p_browse_name <-- get_BrowseName(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : t_Node
    THEN
        p_browse_name :(p_browse_name : t_QualifiedName_i &
                        p_browse_name = a_BrowseName(p_node))
    END
    ;

    p_display_name <-- get_DisplayName(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : t_Node
    THEN
        p_display_name :(p_display_name : t_LocalizedText_i &
                         p_display_name = a_DisplayName(p_node))
    END
    ;

    /* Types */
    bres <-- is_transitive_subtype(p_subtype, p_parent_type) =
    PRE
        p_subtype : t_NodeId_i &
        p_subtype : t_NodeId &
        p_parent_type : t_NodeId_i &
        p_parent_type : t_NodeId
    THEN
        bres := bool(p_subtype |-> p_parent_type : Type_IsTransitiveSubtype)
    END
    ;

    bres <-- is_valid_ReferenceTypeId(p_nodeId) =
    PRE
        p_nodeId : t_NodeId_i &
        p_nodeId : t_NodeId
    THEN
        bres := bool(p_nodeId : Type_IsReferenceTypeIdValid)
    END
    ;

    bres <-- is_NodeId_equal(nid1, nid2) =
    PRE
        nid1 : t_NodeId_i &
        nid1 : t_NodeId &
        nid2 : t_NodeId_i &
        nid2 : t_NodeId
    THEN
        bres := bool(nid1 = nid2)
    END
    ;

    /* References */

    p_type_def <-- get_TypeDefinition(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : t_Node   &
        p_node : dom(Ref_HasTypeDefinition)
    THEN
        p_type_def :(p_type_def : t_ExpandedNodeId_i &
                     p_type_def = Ref_HasTypeDefinition(p_node))
    END
    ;

    p_RefType <-- get_Reference_ReferenceType(p_ref) =
    PRE
        p_ref : t_Reference_i &
        p_ref : t_Reference
    THEN
        p_RefType
        :(  p_RefType : t_NodeId_i &
            p_RefType = Reference_ReferenceType(p_ref)
         )
    END
    ;

    p_TargetNode <-- get_Reference_TargetNode(p_ref) =
    PRE
        p_ref : t_Reference_i &
        p_ref : t_Reference
    THEN
        p_TargetNode
        :(
            p_TargetNode : t_ExpandedNodeId_i &
            p_TargetNode = Reference_TargetNode(p_ref)
         )
    END
    ;

    p_IsForward <-- get_Reference_IsForward(p_ref) =
    PRE
        p_ref : t_Reference_i &
        p_ref : t_Reference
    THEN
        p_IsForward := Reference_IsForward(p_ref)
    END
    ;

    p_ref_index <-- get_Node_RefIndexEnd(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : t_Node
    THEN
        p_ref_index :(
            p_ref_index : NAT &
            p_ref_index = Node_RefIndexEnd(p_node)
        )
    END
    ;

    p_ref <-- get_RefIndex_Reference(p_node, p_ref_index) =
    PRE
        p_node : t_Node_i &
        p_node : t_Node &
        p_ref_index : NAT1 &
        p_ref_index : t_RefIndex &
        Node_RefIndexEnd(p_node) >= p_ref_index
    THEN
        p_ref :(p_ref : t_Reference_i &
                p_ref = RefIndex_Reference(p_node |-> p_ref_index))
    END
    ;

    /* Promoted */
    sc <-- get_Value_StatusCode(p_user, node) =
    PRE
        p_user : t_user_i &
        p_user : t_user   &
        node : t_Node_i &
        node : t_Node &
        a_NodeClass(node) = e_ncl_Variable
    THEN
        sc := a_Value_StatusCode(node)
    END
    ;

    /* Promoted */
    read_AddressSpace_clear_value(val) =
    PRE
        val : t_Variant_i
    THEN
        skip
    END
    ;

    /* Frees a value previously malloced with read_AddressSpace_Attribute_value */
    read_AddressSpace_free_variant(val) =
    PRE
        val : t_Variant_i
    THEN
        skip
    END
    ;

    set_local_service_treatment =
    BEGIN
        local_service_treatment := local_service_treatment + 1
    END
    ;

    unset_local_service_treatment =
    BEGIN
        IF local_service_treatment /= 0 THEN
            local_service_treatment := local_service_treatment - 1
        END
    END
    ;

    /* --------------------------------------------------------------------- */
    /* Service Write */

    StatusCode_service <-- treat_write_request_WriteValues (p_user, p_locales) =
    PRE
        p_user : t_user_i &
        p_user : t_user   &
        p_locales : t_LocaleIds_i &
        p_locales : t_LocaleIds   &
        ResponseWrite_allocated = TRUE
    THEN
        StatusCode_service,
        a_Value,
        a_Value_StatusCode,
        a_Value_SourceTimestamp,
        ResponseWrite_StatusCode
        :(
            StatusCode_service : t_StatusCode_i &
            StatusCode_service : t_StatusCode &

            a_Value : t_Node +-> t_Variant &
            dom(a_NodeClass|>{e_ncl_Variable}) <: dom(a_Value) &
            dom(a_Value) <: dom(a_NodeClass|>{e_ncl_Variable, e_ncl_VariableType}) &
            dom(a_NodeClass|>{e_ncl_Variable}) <: dom(a_Value) &
            a_Value_StatusCode : t_Node +-> t_RawStatusCode &
            dom(a_Value_StatusCode) = dom(a_NodeClass|>{e_ncl_Variable}) &
            a_Value_SourceTimestamp : t_Node +-> t_Timestamp &
            dom(a_Value_SourceTimestamp) = dom(a_NodeClass|>{e_ncl_Variable}) &
            ResponseWrite_StatusCode : t_WriteValue +-> t_StatusCode
        )
    END
    ;

    bret <-- alloc_write_request_responses(nb_req) =
    PRE
        nb_req : NAT &
        ResponseWrite_allocated = FALSE
    THEN
        bret,
        ResponseWrite_StatusCode,
        ResponseWrite_allocated
        :(
            bret : BOOL &
            ResponseWrite_StatusCode : t_WriteValue +-> t_StatusCode &
            ResponseWrite_allocated : BOOL &
            (ResponseWrite_allocated = FALSE
             =>
             ResponseWrite_StatusCode = {}) &
            bret = ResponseWrite_allocated
        )
    END
    ;

    dealloc_write_request_responses =
    PRE
        ResponseWrite_allocated = TRUE
    THEN
        ResponseWrite_allocated  := FALSE ||
        ResponseWrite_StatusCode := {}
    END
    ;

    /* Promoted */
    write_WriteResponse_msg_out(msg_out) =
    PRE
        msg_out : t_msg_i &
        msg_out : t_msg
    THEN
        skip
    END
    ;

    p_authorized <-- get_user_authorization (p_operation_type, p_node_id, p_attribute_id, p_user) =
    PRE
        p_operation_type : t_operation_type_i &
        p_operation_type : t_operation_type   &
        p_node_id        : t_NodeId_i         &
        p_node_id        : t_NodeId           &
        p_attribute_id   : t_AttributeId_i    &
        p_attribute_id   : t_AttributeId      &
        p_user           : t_user_i           &
        p_user           : t_user
    THEN
        p_authorized := bool(p_operation_type |-> p_node_id |-> p_attribute_id |-> p_user : s_AuthorizedOperations)
    END
    ;
    
    p_bool <-- get_Executable(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : dom(a_Executable)
    THEN
        p_bool := a_Executable(p_node)
    END
    ;
    
    p_input_arg <-- get_InputArguments(p_node) =
    PRE
        p_node : t_Node_i &
        p_node : dom(a_NodeClass) &
        a_NodeClass(p_node) = e_ncl_Method
    THEN
        p_input_arg :: t_Variant_i
    END
    ;
    
    p_valueRank <-- get_conv_Variant_ValueRank(p_variant) =
    PRE
        p_variant : t_Variant_i &
        p_variant : t_Variant 
    THEN
        p_valueRank := Variant_ValueRank(p_variant)
    END
    ;
    
    p_type <-- get_conv_Variant_Type(p_variant) =
    PRE
        p_variant : t_Variant_i &
        p_variant : t_Variant
    THEN
        p_type :( p_type : t_NodeId_i & p_type = Variant_LocalDataType(p_variant))
    END
    ;
    
    /* Computes if DataValue has a compatible type or compatible subtype */
    btyp_ok, btyp_need_conv <-- read_variable_compat_type(p_dv_typ_nid, p_dv_vr, p_var_typ_nid, p_var_vr) =
    PRE
        p_dv_typ_nid : t_NodeId_i &
        p_dv_vr : t_ConcreteValueRank &
        p_var_typ_nid : t_NodeId_i &
        p_var_typ_nid : t_NodeId &
        p_var_vr : t_ValueRank
    THEN
        btyp_ok :: BOOL ||
        btyp_need_conv :: BOOL
    END
    ;

    p_bool <-- check_object_has_method(p_object, p_method) =
    PRE
        p_method : t_NodeId_i &
        p_method : t_NodeId   &
		p_object : t_NodeId_i &
        p_object : t_NodeId
    THEN
        p_bool := bool(p_object |-> p_method : Object_HasMethod)
    END
    ;
    
    statusCode, node <-- check_nodeId_isValid(nodeid)=
    PRE
        nodeid : t_NodeId_i &
        nodeid : t_NodeId
    THEN
        IF nodeid = c_NodeId_indet
        THEN
            statusCode := e_sc_bad_node_id_invalid ||
            node := c_Node_indet
        ELSIF nodeid /: dom(a_NodeId~)
        THEN
            statusCode := e_sc_bad_node_id_unknown ||
            node := c_Node_indet
        ELSE
            statusCode := e_sc_ok ||
            node := a_NodeId~(nodeid)
        END
    END

END
