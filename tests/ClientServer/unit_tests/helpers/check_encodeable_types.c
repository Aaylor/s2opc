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

/** \file
 *
 * \brief Entry point for encodeable types tests. Tests use libcheck.
 *
 * If you want to debug the exe, you should define env var CK_FORK=no
 * http://check.sourceforge.net/doc/check_html/check_4.html#No-Fork-Mode
 */

#include <check.h>

#include "check_helpers.h"

#include "sopc_encodeable.h"
#include "sopc_helper_endianness_cfg.h"
#include "sopc_types.h"

static void setup(void)
{
    SOPC_Helper_EndiannessCfg_Initialize();
}

/**
 * Checks that the status is OK.
 */
static void ck_assert_ok(SOPC_ReturnStatus status)
{
    ck_assert(SOPC_STATUS_OK == status);
}

/**
 * Checks that the object carries the expected encodeable type.
 */
#define ck_assert_encodeable_type(obj, type) ck_assert_ptr_eq((obj)->encodeableType, &type##_EncodeableType)

/******************************************************************************
 * Generic checker for encodeable types
 * Test of Initialize, Decode and Encode functions
 * The type and the checker function are received as parameters, as well as the
 * buffer to be decoded.
 ******************************************************************************/
static void checkEncodeableType(SOPC_EncodeableType* encType,
                                void (*encodeableTypeChecker)(const void*),
                                uint8_t* frame,
                                uint32_t frameSize)
{
    // Allocation
    void* obj = NULL;
    SOPC_Buffer* input = NULL;
    SOPC_Buffer* output = NULL;

    // Buffer initialization
    input = SOPC_Buffer_Create(frameSize);
    output = SOPC_Buffer_Create(frameSize);

    ck_assert_ok(SOPC_Buffer_Write(input, frame, frameSize));
    ck_assert_ok(SOPC_Buffer_SetPosition(input, 0));

    // Initialization
    SOPC_Encodeable_Create(encType, &obj);
    ck_assert_ptr_nonnull(obj);

    // Decode
    ck_assert_ok(encType->Decode(obj, input, 0));

    // Check object content
    encodeableTypeChecker(obj);

    // Encode
    ck_assert_ok(encType->Encode(obj, output, 0));

    // Check buffers
    ck_assert_uint_eq(output->position, frameSize);
    ck_assert_mem_eq(input->data, output->data, frameSize);

    // Clear all objects
    SOPC_Encodeable_Delete(encType, &obj);
    SOPC_Buffer_Delete(input);
    SOPC_Buffer_Delete(output);
}

/******************************************************************************
 * TimeZoneDataType unitary test
 ******************************************************************************/

static void check_TimeZoneDataType(const void* untypedObject)
{
    const OpcUa_TimeZoneDataType* obj = untypedObject;

    ck_assert_encodeable_type(obj, OpcUa_TimeZoneDataType);
    ck_assert_int_eq(obj->Offset, -1);
    ck_assert_int_eq(obj->DaylightSavingInOffset, true);
}

START_TEST(test_TimeZoneDataType)
{
    uint8_t frame[] = {
        0xFF, 0xFF, // Offset == -1
        0x01        // DaylightSavingInOffset == true
    };

    checkEncodeableType(&OpcUa_TimeZoneDataType_EncodeableType, check_TimeZoneDataType, frame, (uint32_t) sizeof frame);
}
END_TEST

/******************************************************************************
 * AggregateFilterResult unitary test
 ******************************************************************************/

static void check_AggregateFilterResult(const void* untypedObject)
{
    const OpcUa_AggregateFilterResult* obj = untypedObject;
    const OpcUa_AggregateConfiguration* config = NULL;

    ck_assert_encodeable_type(obj, OpcUa_AggregateFilterResult);
    ck_assert_int_eq(obj->RevisedStartTime, -1);
    ck_assert_double_eq(obj->RevisedProcessingInterval, 6.5);

    config = &obj->RevisedAggregateConfiguration;
    ck_assert_encodeable_type(config, OpcUa_AggregateConfiguration);
    ck_assert_int_eq(config->UseServerCapabilitiesDefaults, true);
    ck_assert_int_eq(config->TreatUncertainAsBad, false);
    ck_assert_uint_eq(config->PercentDataBad, 0x2A);
    ck_assert_uint_eq(config->PercentDataGood, 0x3A);
    ck_assert_int_eq(config->UseSlopedExtrapolation, true);
}

START_TEST(test_AggregateFilterResult)
{
    uint8_t frame[] = {
        // RevisedStartTime == -1
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,

        // RevisedProcessingInterval == 6.5
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x40,

        // AggregateConfiguration:
        0x01, // UseServerCapabilitiesDefaults == true
        0x00, // TreatUncertainAsBad           == false
        0x2A, // PercentDataBad                == 0x2A
        0x3A, // PercentDataGood               == 0x3A
        0x01  // UseSlopedExtrapolation        == true
    };

    checkEncodeableType(&OpcUa_AggregateFilterResult_EncodeableType, check_AggregateFilterResult, frame,
                        (uint32_t) sizeof frame);
}
END_TEST

/******************************************************************************
 * BrowsePath unitary test
 ******************************************************************************/

static void check_BrowsePath(const void* untypedObject)
{
    const OpcUa_BrowsePath* obj = untypedObject;
    const OpcUa_RelativePath* path = NULL;
    const OpcUa_RelativePathElement* elem = NULL;

    ck_assert_encodeable_type(obj, OpcUa_BrowsePath);
    ck_assert_int_eq(obj->StartingNode.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(obj->StartingNode.Namespace, 0x02);
    ck_assert_uint_eq(obj->StartingNode.Data.Numeric, 0x0403);

    path = &obj->RelativePath;
    ck_assert_encodeable_type(path, OpcUa_RelativePath);
    ck_assert_int_eq(path->NoOfElements, 2);
    ck_assert_ptr_nonnull(path->Elements);

    elem = &path->Elements[0];
    ck_assert_encodeable_type(elem, OpcUa_RelativePathElement);
    ck_assert_int_eq(elem->ReferenceTypeId.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(elem->ReferenceTypeId.Namespace, 0x05);
    ck_assert_uint_eq(elem->ReferenceTypeId.Data.Numeric, 0x0706);
    ck_assert_int_eq(elem->IsInverse, false);
    ck_assert_int_eq(elem->IncludeSubtypes, true);
    ck_assert_uint_eq(elem->TargetName.NamespaceIndex, 0x0908);
    ck_assert_int_eq(elem->TargetName.Name.Length, -1);
    ck_assert_int_eq(elem->TargetName.Name.DoNotClear, false);
    ck_assert_ptr_null(elem->TargetName.Name.Data);

    elem = &path->Elements[1];
    ck_assert_encodeable_type(elem, OpcUa_RelativePathElement);
    ck_assert_int_eq(elem->ReferenceTypeId.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(elem->ReferenceTypeId.Namespace, 0x0A);
    ck_assert_uint_eq(elem->ReferenceTypeId.Data.Numeric, 0x0C0B);
    ck_assert_int_eq(elem->IsInverse, true);
    ck_assert_int_eq(elem->IncludeSubtypes, false);
    ck_assert_uint_eq(elem->TargetName.NamespaceIndex, 0x0E0D);
    ck_assert_int_eq(elem->TargetName.Name.Length, 4);
    ck_assert_int_eq(elem->TargetName.Name.DoNotClear, false);
    ck_assert_str_eq((char*) elem->TargetName.Name.Data, "mugu");
}

START_TEST(test_BrowsePath)
{
    uint8_t frame[] = {
        // BrowsePath->StartingNodeId
        0x01,       // Four byte encoding of NodeId
        0x02,       // Namespace == 2
        0x03, 0x04, // Identifier == 0x0403

        // BrowsePath->RelativePath
        0x02, 0x00, 0x00, 0x00, // NoOfElements == 2

        // BrowsePath->RelativePath.Element[0]
        // ReferenceTypeId
        0x01,       // Four byte encoding of NodeId
        0x05,       // Namespace == 5
        0x06, 0x07, // Identifier == 0x0706

        0x00, // IsInverse == false
        0x01, // IncludeSubtypes == true

        // TargetName
        0x08, 0x09,             // NamespaceIndex == 0x0908
        0xff, 0xff, 0xff, 0xff, // Name (null)

        // BrowsePath->RelativePath.Element[1]
        // ReferenceTypeId
        0x01,       // Four byte encoding of NodeId
        0x0A,       // Namespace == 0x0A
        0x0B, 0x0C, // Identifier == 0x0C0B

        0x01, // IsInverse == true
        0x00, // IncludeSubtypes == false

        // TargetName
        0x0D, 0x0E,             // NamespaceIndex = 0x0E0D
        0x04, 0x00, 0x00, 0x00, // Name length == 4
        0x6D, 0x75, 0x67, 0x75  // Name Data == "mugu"
    };

    checkEncodeableType(&OpcUa_BrowsePath_EncodeableType, check_BrowsePath, frame, (uint32_t) sizeof frame);
}
END_TEST

/******************************************************************************
 * DeleteSubscriptionsRequest unitary test
 ******************************************************************************/

static void check_DeleteSubscriptionsRequest(const void* untypedObject)
{
    const OpcUa_DeleteSubscriptionsRequest* obj = untypedObject;

    ck_assert_encodeable_type(obj, OpcUa_DeleteSubscriptionsRequest);
    ck_assert_int_eq(obj->NoOfSubscriptionIds, 2);
    ck_assert_uint_eq(obj->SubscriptionIds[0], 5);
    ck_assert_uint_eq(obj->SubscriptionIds[1], 10);
}

START_TEST(test_DeleteSubscriptionsRequest)
{
    // Test frame creation (with cursor position reset)
    uint8_t frame[] = {
        0x02, 0x00, 0x00, 0x00, // NoOfSubscriptionIds == 2
        0x05, 0x00, 0x00, 0x00, // SubscriptionsIds[0] == 5
        0x0A, 0x00, 0x00, 0x00  // SubscriptionsIds[1] == 10
    };

    checkEncodeableType(&OpcUa_DeleteSubscriptionsRequest_EncodeableType, check_DeleteSubscriptionsRequest, frame,
                        (uint32_t) sizeof frame);
}
END_TEST

/******************************************************************************
 * FindServersResponse unitary test
 ******************************************************************************/

static void check_TranslateBrowsePathsToNodeIdsRequest(const void* untypedObject)
{
    const OpcUa_TranslateBrowsePathsToNodeIdsRequest* obj = untypedObject;
    const OpcUa_BrowsePath* browsePath = NULL;
    const OpcUa_RelativePath* path = NULL;
    const OpcUa_RelativePathElement* elem = NULL;

    ck_assert_encodeable_type(obj, OpcUa_TranslateBrowsePathsToNodeIdsRequest);

    ck_assert_int_eq(obj->NoOfBrowsePaths, 2);
    ck_assert_ptr_nonnull(obj->BrowsePaths);

    // BrowsePaths[0]
    browsePath = &obj->BrowsePaths[0];
    ck_assert_encodeable_type(browsePath, OpcUa_BrowsePath);
    ck_assert_int_eq(browsePath->StartingNode.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(browsePath->StartingNode.Namespace, 0x02);
    ck_assert_uint_eq(browsePath->StartingNode.Data.Numeric, 0x0605);

    // BrowsePaths[0].RelativePath
    path = &browsePath->RelativePath;
    ck_assert_encodeable_type(path, OpcUa_RelativePath);
    ck_assert_int_eq(path->NoOfElements, 2);
    ck_assert_ptr_nonnull(path->Elements);

    // BrowsePaths[0].RelativePath.Elements[0]
    elem = &path->Elements[0];
    ck_assert_encodeable_type(elem, OpcUa_RelativePathElement);
    ck_assert_int_eq(elem->ReferenceTypeId.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(elem->ReferenceTypeId.Namespace, 0x05);
    ck_assert_uint_eq(elem->ReferenceTypeId.Data.Numeric, 0x0B0A);
    ck_assert_int_eq(elem->IsInverse, false);
    ck_assert_int_eq(elem->IncludeSubtypes, true);
    ck_assert_uint_eq(elem->TargetName.NamespaceIndex, 0x0B0C);
    ck_assert_int_eq(elem->TargetName.Name.Length, -1);
    ck_assert_int_eq(elem->TargetName.Name.DoNotClear, false);
    ck_assert_ptr_null(elem->TargetName.Name.Data);

    // BrowsePaths[0].RelativePath.Elements[1]
    elem = &path->Elements[1];
    ck_assert_encodeable_type(elem, OpcUa_RelativePathElement);
    ck_assert_int_eq(elem->ReferenceTypeId.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(elem->ReferenceTypeId.Namespace, 0x0B);
    ck_assert_uint_eq(elem->ReferenceTypeId.Data.Numeric, 0x0D0C);
    ck_assert_int_eq(elem->IsInverse, true);
    ck_assert_int_eq(elem->IncludeSubtypes, false);
    ck_assert_uint_eq(elem->TargetName.NamespaceIndex, 0x0E0D);
    ck_assert_int_eq(elem->TargetName.Name.Length, 4);
    ck_assert_int_eq(elem->TargetName.Name.DoNotClear, false);
    ck_assert_str_eq((char*) elem->TargetName.Name.Data, "mugu");

    // BrowsePaths[1]
    browsePath = &obj->BrowsePaths[1];
    ck_assert_encodeable_type(browsePath, OpcUa_BrowsePath);
    ck_assert_int_eq(browsePath->StartingNode.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(browsePath->StartingNode.Namespace, 0x02);
    ck_assert_uint_eq(browsePath->StartingNode.Data.Numeric, 0x0403);

    // BrowsePaths[1].RelativePath
    path = &browsePath->RelativePath;
    ck_assert_encodeable_type(path, OpcUa_RelativePath);
    ck_assert_int_eq(path->NoOfElements, 1);
    ck_assert_ptr_nonnull(path->Elements);

    // BrowsePaths[1].RelativePath.Elements[0]
    elem = &path->Elements[0];
    ck_assert_encodeable_type(elem, OpcUa_RelativePathElement);
    ck_assert_int_eq(elem->ReferenceTypeId.IdentifierType, SOPC_IdentifierType_Numeric);
    ck_assert_int_eq(elem->ReferenceTypeId.Namespace, 0x05);
    ck_assert_uint_eq(elem->ReferenceTypeId.Data.Numeric, 0x0706);
    ck_assert_int_eq(elem->IsInverse, false);
    ck_assert_int_eq(elem->IncludeSubtypes, true);
    ck_assert_uint_eq(elem->TargetName.NamespaceIndex, 0x0908);
    ck_assert_int_eq(elem->TargetName.Name.Length, 3);
    ck_assert_int_eq(elem->TargetName.Name.DoNotClear, false);
    ck_assert_str_eq((const char*) elem->TargetName.Name.Data, "foo");
}

START_TEST(test_TranslateBrowsePathsToNodeIdsRequest)
{
    uint8_t frame[] = {
        0x02, 0x00, 0x00, 0x00, // NoOfBrowsePaths == 2

        // BrowsePaths[0].StartingNodeId
        0x01,       // Four byte encoding of NodeId
        0x02,       // Namespace == 2
        0x05, 0x06, // Identifier == 0x0605

        // BrowsePaths[0].RelativePath
        0x02, 0x00, 0x00, 0x00, // NoOfElements == 2

        // BrowsePaths[0].RelativePath.Elements[0]
        // ...ReferenceTypeId
        0x01,       // Four byte encoding of NodeId
        0x05,       // Namespace == 5
        0x0A, 0x0B, // Identifier == 0x0B0A

        0x00, // IsInverse == false
        0x01, // IncludeSubtypes == true

        // ...TargetName
        0x0C, 0x0B,             // NamespaceIndex == 0x0B0C
        0xff, 0xff, 0xff, 0xff, // Name (null)

        // BrowsePaths[0].RelativePath.Elements[1]
        // ...ReferenceTypeId
        0x01,       // Four byte encoding of NodeId
        0x0B,       // Namespace == 0x0B
        0x0C, 0x0D, // Identifier == 0x0D0C

        0x01, // IsInverse == true
        0x00, // IncludeSubtypes == false

        // ...TargetName
        0x0D, 0x0E,             // NamespaceIndex == 0x0E0D
        0x04, 0x00, 0x00, 0x00, // Name length == 4
        0x6D, 0x75, 0x67, 0x75, // Name Data == "mugu"

        // BrowsePaths[1].StartingNodeId
        0x01,       // Four byte encoding of NodeId
        0x02,       // Namespace == 2
        0x03, 0x04, // Identifier == 0x0403

        // BrowsePaths[1].RelativePath
        0x01, 0x00, 0x00, 0x00, // NoOfElements == 1

        // BrowsePaths[1].RelativePath.Elements[0]
        // ...ReferenceTypeId
        0x01,       // Four byte encoding of NodeId
        0x05,       // Namespace == 5
        0x06, 0x07, // Identifier == 0x0706

        0x00, // IsInverse == false
        0x01, // IncludeSubtypes == true

        // ...TargetName
        0x08, 0x09,             // NamespaceIndex = 0x0908
        0x03, 0x00, 0x00, 0x00, // Name length == 3
        0x66, 0x6F, 0X6F        // Name Data == "foo"
    };

    checkEncodeableType(&OpcUa_TranslateBrowsePathsToNodeIdsRequest_EncodeableType,
                        check_TranslateBrowsePathsToNodeIdsRequest, frame, (uint32_t) sizeof frame);
}
END_TEST

Suite* tests_make_suite_encodeable_types(void)
{
    Suite* s;
    TCase* tc_encodeable_types;

    s = suite_create("Tests for encodeable types");

    tc_encodeable_types = tcase_create("Encodeable_Types");

    tcase_add_checked_fixture(tc_encodeable_types, setup, NULL);
    tcase_add_test(tc_encodeable_types, test_TimeZoneDataType);
    tcase_add_test(tc_encodeable_types, test_AggregateFilterResult);
    tcase_add_test(tc_encodeable_types, test_BrowsePath);
    tcase_add_test(tc_encodeable_types, test_DeleteSubscriptionsRequest);
    tcase_add_test(tc_encodeable_types, test_TranslateBrowsePathsToNodeIdsRequest);
    suite_add_tcase(s, tc_encodeable_types);

    return s;
}
