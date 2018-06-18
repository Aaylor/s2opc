/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
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
 *  \file sopc_sockets_api.h
 *
 *  \brief Event oriented API of the Services layer.
 *
 *         This module is in charge of the event dispatcher thread management.
 */

#ifndef SOPC_SERVICES_API_H_
#define SOPC_SERVICES_API_H_

#include <stdint.h>

#include "sopc_event_dispatcher_manager.h"
#include "sopc_user_app_itf.h"

typedef enum SOPC_Services_Event {
    /* SC to Services events */
    SC_TO_SE_EP_SC_CONNECTED,       /* id = endpoint description config index,
                                       params = endpoint connection config index pointer,
                                       auxParams = (uint32_t) secure channel connection index
                                    */
    SC_TO_SE_EP_CLOSED,             /* id = endpoint description config index,
                                       auxParams = SOPC_ReturnStatus
                                     */
    SC_TO_SE_SC_CONNECTED,          /* id = secure channel connection index,
                                       auxParams = (uint32_t) secure channel configuration index
                                    */
    SC_TO_SE_SC_CONNECTION_TIMEOUT, /* id = endpoint connection config index
                                     */
    SC_TO_SE_SC_DISCONNECTED,       /* id = secure channel connection index
                                     */
    SC_TO_SE_SC_SERVICE_RCV_MSG,    /* id = secure channel connection index,
                                       params = (SOPC_Buffer*) OPC UA message payload buffer,
                                       auxParam = (uint32_t) request Id context (server side only, 0 if client)
                                    */
    SC_TO_SE_SND_FAILURE,           /* id = secure channel connection index,
                                       params = (uint32_t*) requestId,
                                       auxParam = SOPC_StatusCode
                                     */
    SC_TO_SE_REQUEST_TIMEOUT,       /* id = secure channel connection index,
                                       auxParam = (uint32_t) request handle */

    /* Services to services events */
    SE_TO_SE_SC_ALL_DISCONNECTED,       // special event sent by services mgr itself (no parameters)
    SE_TO_SE_ACTIVATE_ORPHANED_SESSION, /* id = session id
                                           auxParam = (uint32_t) endpoint connection config index
                                        */
    SE_TO_SE_CREATE_SESSION,            /* id = session id
                                           auxParam = (uint32_t) endpoint connection config index
                                        */
    SE_TO_SE_ACTIVATE_SESSION,          /* id = session id
                                         * params = (user token structure)
                                         */
    /* Timer to services events */
    TIMER_SE_EVAL_SESSION_TIMEOUT, /* id = session id */
    /* App to Services events : server side */
    APP_TO_SE_OPEN_ENDPOINT,         /* id = endpoint description config index
                                      */
    APP_TO_SE_CLOSE_ENDPOINT,        /* id = endpoint description config index
                                      */
    APP_TO_SE_LOCAL_SERVICE_REQUEST, /* id = endpoint connection config index,
                                        params = (OpcUa_<MessageStruct>*) OPC UA message payload structure (header
                                         ignored)
                                        auxParam = user application session context
                                      */
    /* App to Services events : client side */
    APP_TO_SE_ACTIVATE_SESSION,       /* Connect SC + Create Session + Activate session */
                                      /* id = endpoint connection config index,
                                       * params = (user token structure)
                                         auxParam = user application session context
                                       */
    APP_TO_SE_SEND_SESSION_REQUEST,   /* id = session id,
                                         params = (OpcUa_<MessageStruct>*) OPC UA message payload structure (header
                                         ignored)
                                         auxParam = user application request context
                                      */
    APP_TO_SE_SEND_DISCOVERY_REQUEST, /* id = endpoint connection config index,
                                         params = (OpcUa_<MessageStruct>*) OPC UA message payload structure (header
                                         ignored)
                                         auxParam = user application request context
                                       */
    APP_TO_SE_CLOSE_SESSION,          // id = session id
    APP_TO_SE_CLOSE_ALL_CONNECTIONS,  // Automatically called by toolkit clear (no params)
} SOPC_Services_Event;

/* API to enqueue an event for services */
void SOPC_Services_EnqueueEvent(SOPC_Services_Event seEvent, uint32_t id, void* params, uintptr_t auxParam);

/* API to enqueue an event for application */
// Note: appEvent value shall be created using SOPC_AppEvent_*Event_Create functions
void SOPC_ServicesToApp_EnqueueEvent(int32_t appEvent, uint32_t eventType, void* params, uintptr_t auxParam);

/**
 *  \brief Initializes the services and application event dispatcher threads
 */
void SOPC_Services_Initialize(void);

/**
 *  \brief Notify the toolkit configuration is terminated to could initialize the services B model
 */
void SOPC_Services_ToolkitConfigured(void);

/**
 *  \brief Notify that the clear function will be called to could terminate
 *         operations using secure channels and sockets services.
 */
void SOPC_Services_PreClear(void);

/**
 *  \brief Stop and clear the services and application event dispatcher threads
 */
void SOPC_Services_Clear(void);

// Internal use only (timers)
SOPC_EventDispatcherManager* SOPC_Services_GetEventDispatcher(void);

// Internal use only (timers)
SOPC_EventDispatcherManager* SOPC_ApplicationCallback_GetEventDispatcher(void);

#endif /* SOPC_SERVICES_API_H_ */
