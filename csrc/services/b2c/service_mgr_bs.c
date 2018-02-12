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

/*------------------------
   Exported Declarations
  ------------------------*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "message_out_bs.h"
#include "service_mgr_bs.h"

#include "sopc_services_api.h"
#include "sopc_singly_linked_list.h"

#define SOPC_MAX_WAITING_DISCOVERY_REQUESTS 5

static SOPC_SLinkedList*
    discovery_reqs_to_send[constants_bs__t_channel_config_idx_i_max + 1]; // index 0 is undet channel config

/*------------------------
   INITIALISATION Clause
  ------------------------*/
void service_mgr_bs__INITIALISATION(void)
{
    memset(discovery_reqs_to_send, 0, (constants_bs__t_channel_config_idx_i_max + 1) * sizeof(SOPC_SLinkedList*));
}

/*--------------------
   OPERATIONS Clause
  --------------------*/
void service_mgr_bs__client_async_discovery_request_without_channel(
    const constants__t_channel_config_idx_i service_mgr_bs__channel_config_idx,
    const constants__t_msg_i service_mgr_bs__req_msg,
    t_bool* const service_mgr_bs__bres)
{
    constants__t_msg_i* addedMsg = NULL;
    SOPC_SLinkedList* sLinkedList = NULL;
    *service_mgr_bs__bres = false;
    if (service_mgr_bs__channel_config_idx > 0 &&
        service_mgr_bs__channel_config_idx <= constants_bs__t_channel_config_idx_i_max)
    {
        sLinkedList = discovery_reqs_to_send[service_mgr_bs__channel_config_idx];
        if (NULL == sLinkedList)
        {
            sLinkedList = SOPC_SLinkedList_Create(SOPC_MAX_WAITING_DISCOVERY_REQUESTS);
            discovery_reqs_to_send[service_mgr_bs__channel_config_idx] = sLinkedList;
        }
        if (NULL != sLinkedList)
        {
            addedMsg = SOPC_SLinkedList_Append(sLinkedList, 0, service_mgr_bs__req_msg);
        }
        if (addedMsg == service_mgr_bs__req_msg)
        {
            *service_mgr_bs__bres = true;
        }
    }
}

void service_mgr_bs__client_channel_connected_event_discovery(
    const constants__t_channel_config_idx_i service_mgr_bs__channel_config_idx,
    const constants__t_channel_i service_mgr_bs__channel)
{
    (void) service_mgr_bs__channel;
    SOPC_SLinkedList* sLinkedList = NULL;
    SOPC_SLinkedListIterator listIt = NULL;
    constants__t_msg_i msgToSend = NULL;
    if (service_mgr_bs__channel_config_idx > 0 &&
        service_mgr_bs__channel_config_idx <= constants_bs__t_channel_config_idx_i_max)
    {
        sLinkedList = discovery_reqs_to_send[service_mgr_bs__channel_config_idx];
        if (NULL != sLinkedList)
        {
            listIt = SOPC_SLinkedList_GetIterator(sLinkedList);
            if (NULL != listIt)
            {
                while (NULL != listIt)
                {
                    msgToSend = SOPC_SLinkedList_Next(&listIt);
                    if (msgToSend != NULL)
                    {
                        SOPC_Services_EnqueueEvent(APP_TO_SE_SEND_DISCOVERY_REQUEST, service_mgr_bs__channel_config_idx,
                                                   msgToSend, 0);
                    }
                }
                SOPC_SLinkedList_Clear(sLinkedList);
            }
        }
    }
}

void SOPC_ServiceMgrBs_DeallocateMsgs(uint32_t id, void* val)
{
    (void) id;
    message_out_bs__dealloc_msg_out((const constants__t_msg_i) val);
}

void service_mgr_bs__UNINITIALISATION(void)
{
    SOPC_SLinkedList* sLinkedList = NULL;
    for (constants_bs__t_channel_config_idx_i idx = 0; idx <= constants_bs__t_channel_config_idx_i_max; idx++)
    {
        sLinkedList = discovery_reqs_to_send[idx];
        if (NULL != sLinkedList)
        {
            SOPC_SLinkedList_Apply(sLinkedList, SOPC_ServiceMgrBs_DeallocateMsgs);
            SOPC_SLinkedList_Delete(sLinkedList);
            discovery_reqs_to_send[idx] = NULL;
        }
    }
}