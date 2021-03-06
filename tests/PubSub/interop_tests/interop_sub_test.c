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

/**
 * This Subscriber is waiting for a single UDP message.
 * Expected message should contains :
 *  - opc.udp://232.1.2.100:4840
 *  - network message version = 1
 *  - group id = 10
 *  - group version = 0
 *  - publisher ID = 3
 *  - One DataSetMessage:
 *    - Field 1 with value 'The Ultimate Question of Life, the Universe and Everything' and type String
 *    - Field 2 with value 42 and type UInt32
 *    - Field 3 with value -314 and type Int16
 *    - Field 4 with value True and type Boolean
 */

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

#include "sopc_atomic.h"
#include "sopc_dataset_ll_layer.h"
#include "sopc_helper_endianness_cfg.h"
#include "sopc_network_layer.h"
#include "sopc_sub_udp_sockets_mgr.h"
#include "sopc_time.h"
#include "sopc_udp_sockets.h"

#define MCAST_PORT "4840"
#define MCAST_ADDR "232.1.2.100"

#define CTX_VALUE (uintptr_t) 1

static SOPC_Buffer* buffer = NULL;
static int32_t stop = 0;

static int returnCode = -1;
static int sleepCount = 20;

static void printVariant(const SOPC_Variant* variant)
{
    printf("DataSetField NOK\n");
    printf("   - Variant Type %d\n", variant->BuiltInTypeId);
    switch (variant->BuiltInTypeId)
    {
    case SOPC_Boolean_Id:
        printf("   - Variant Value %d\n", variant->Value.Boolean);
        break;
    case SOPC_Int16_Id:
        printf("   - Variant Value %d\n", variant->Value.Int16);
        break;
    case SOPC_UInt32_Id:
        printf("   - Variant Value %d\n", variant->Value.Uint32);
        break;
    case SOPC_String_Id:
        printf("   - Variant Value %s\n", SOPC_String_GetRawCString(&(variant->Value.String)));
        break;
    default:
        printf("   - Variant type not managed: %d\n", variant->BuiltInTypeId);
    }
}

static int TestNetworkMessage(const SOPC_UADP_NetworkMessage* uadp_nm)
{
    if (NULL == uadp_nm)
    {
        printf("Network Message NOK. Message is null\n");
        return -1;
    }
    int result = 0;
    SOPC_Dataset_LL_NetworkMessage* nm = uadp_nm->nm;
    if (1 != SOPC_Dataset_LL_NetworkMessage_Get_Version(nm))
    {
        printf("UADP Version NOK : %d\n", SOPC_Dataset_LL_NetworkMessage_Get_Version(nm));
        result = -1;
    }
    {
        SOPC_Dataset_LL_PublisherId* publisher_id = SOPC_Dataset_LL_NetworkMessage_Get_PublisherId(uadp_nm->nm);
        if (false == uadp_nm->conf.GroupIdFlag || DataSet_LL_PubId_UInt16_Id != publisher_id->type ||
            3 != publisher_id->data.uint16)
        {
            printf("Publisher Id NOK :\n - Enabled %d\n - Type %d\n - Value %d\n", uadp_nm->conf.GroupIdFlag,
                   publisher_id->type, publisher_id->data.byte);
            result = -1;
        }
    }
    if (!uadp_nm->conf.GroupHeaderFlag)
    {
        printf("Group Header should be enabled\n");
        result = -1;
    }
    if (false == uadp_nm->conf.GroupIdFlag || 10 != SOPC_Dataset_LL_NetworkMessage_Get_GroupId(nm))
    {
        printf("Writer Group Id NOK:\n - Enabled %d\n - Value %d\n", uadp_nm->conf.GroupIdFlag,
               SOPC_Dataset_LL_NetworkMessage_Get_GroupId(nm));
        result = -1;
    }

    if (false == uadp_nm->conf.GroupVersionFlag || 0 != SOPC_Dataset_LL_NetworkMessage_Get_GroupVersion(nm))
    {
        printf("Writer Group Version NOK:\n - Enabled %d\n - Value %d\n", uadp_nm->conf.GroupVersionFlag,
               SOPC_Dataset_LL_NetworkMessage_Get_GroupVersion(nm));
        result = -1;
    }

    const uint8_t nbDsm = SOPC_Dataset_LL_NetworkMessage_Nb_DataSetMsg(nm);
    if (1 != nbDsm)
    {
        printf("Nb DataSetMessage NOK. Should be 1 : %d\n", nbDsm);
        result = -1;
    }
    else
    {
        SOPC_Dataset_LL_DataSetMessage* dsm = SOPC_Dataset_LL_NetworkMessage_Get_DataSetMsg_At(nm, 0);
        uint16_t nbDsf = SOPC_Dataset_LL_DataSetMsg_Nb_DataSetField(dsm);
        if (4 != nbDsf)
        {
            printf("Nb DataSetField NOK. Should be 4 : %d\n", nbDsf);
            result = -1;
        }
        else
        {
            {
                const SOPC_Variant* variant = SOPC_Dataset_LL_DataSetMsg_Get_Variant_At(dsm, 0);
                if (SOPC_String_Id != variant->BuiltInTypeId ||
                    0 != strcmp("The Ultimate Question of Life, the Universe and Everything",
                                SOPC_String_GetRawCString(&(variant->Value.String))))
                {
                    printVariant(variant);
                    result = -1;
                }
            }
            {
                const SOPC_Variant* variant = SOPC_Dataset_LL_DataSetMsg_Get_Variant_At(dsm, 1);
                if (SOPC_UInt32_Id != variant->BuiltInTypeId || 42 != (variant->Value.Uint32))
                {
                    printVariant(variant);
                    result = -1;
                }
            }
            {
                const SOPC_Variant* variant = SOPC_Dataset_LL_DataSetMsg_Get_Variant_At(dsm, 2);
                if (SOPC_Int16_Id != variant->BuiltInTypeId || -314 != (variant->Value.Int16))
                {
                    printVariant(variant);
                    result = -1;
                }
            }

            {
                const SOPC_Variant* variant = SOPC_Dataset_LL_DataSetMsg_Get_Variant_At(dsm, 3);
                if (SOPC_Boolean_Id != variant->BuiltInTypeId || true != (variant->Value.Boolean))
                {
                    printVariant(variant);
                    result = -1;
                }
            }
        }
    }
    return result;
}

static void readyToReceive(void* sockContext, Socket sock)
{
    (void) sockContext;
    if (SOPC_Atomic_Int_Get(&stop))
    {
        return;
    }

    SOPC_ReturnStatus status = SOPC_UDP_Socket_ReceiveFrom(sock, buffer);
    if (SOPC_STATUS_OK == status && buffer->length > 1)
    {
        uint64_t i = 0;
        status = SOPC_Buffer_Read((uint8_t*) &i, buffer, 8);
        buffer->position = 0;
        if (SOPC_STATUS_OK == status)
        {
            SOPC_UADP_NetworkMessage* uadp_nm = SOPC_UADP_NetworkMessage_Decode(buffer);
            returnCode = TestNetworkMessage(uadp_nm);
            SOPC_UADP_NetworkMessage_Delete(uadp_nm);
        }
        SOPC_Atomic_Int_Set(&stop, true);
    }
    else if (SOPC_STATUS_OK == status && buffer->length == 1)
    {
        assert(buffer->data[0] == 0);
        printf("Received 'empty' data, used to check that subscriber is running !\n");
    }
    else
    {
        SOPC_Atomic_Int_Set(&stop, true);
    }
    SOPC_Buffer_SetPosition(buffer, 0);
}

static void tick(void* tickCtx)
{
    assert(CTX_VALUE == (uintptr_t) tickCtx);
    // printf("tick !\n");
}

int main(void)
{
    Socket sock;
    SOPC_Socket_AddressInfo* listenAddr = SOPC_UDP_SocketAddress_Create(false, MCAST_ADDR, MCAST_PORT);
    SOPC_Socket_AddressInfo* localAddr = SOPC_UDP_SocketAddress_Create(false, NULL, MCAST_PORT);

    SOPC_Helper_EndiannessCfg_Initialize();

    SOPC_ReturnStatus status = SOPC_UDP_Socket_CreateToReceive(listenAddr, true, &sock);
    buffer = SOPC_Buffer_Create(4096);

    if (SOPC_STATUS_OK == status && buffer != NULL)
    {
        if (SOPC_STATUS_OK == status)
        {
            status = SOPC_UDP_Socket_AddMembership(sock, listenAddr, localAddr);
            if (SOPC_STATUS_OK != status)
            {
                printf("SOPC_UDP_Socket_AddMembership failed\n");
            }
        }
    }
    if (SOPC_STATUS_OK == status)
    {
        SOPC_UDP_SocketsMgr_Initialize(NULL, &sock, 1, readyToReceive, tick, (void*) CTX_VALUE);
    }

    while (SOPC_STATUS_OK == status && false == SOPC_Atomic_Int_Get(&stop) && sleepCount > 0)
    {
        SOPC_Sleep(100);
        sleepCount--;
    }
    SOPC_UDP_SocketsMgr_Clear();

    SOPC_Buffer_Delete(buffer);
    SOPC_UDP_Socket_Close(&sock);
    SOPC_UDP_SocketAddress_Delete(&listenAddr);
    SOPC_UDP_SocketAddress_Delete(&localAddr);

    return returnCode;
}
