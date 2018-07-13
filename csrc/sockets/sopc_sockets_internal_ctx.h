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

#ifndef SOPC_SOCKETS_INTERNAL_CTX_H_
#define SOPC_SOCKETS_INTERNAL_CTX_H_

#include <stdbool.h>

#include "sopc_async_queue.h"
#include "sopc_event_handler.h"
#include "sopc_mutexes.h"
#include "sopc_raw_sockets.h"
#include "sopc_toolkit_constants.h"

typedef enum {
    SOCKET_STATE_CLOSED = 0,
    SOCKET_STATE_CONNECTING, // Client connect waiting for write event
                             // && SO_ERROR to be verified on event to confirm connection accepted
    SOCKET_STATE_CONNECTED,  // Client: write event received after connect / Server: connection accepted (socket level +
                             // SC connection level)
    SOCKET_STATE_LISTENING,  // Server: listening socket
    SOCKET_STATE_ACCEPTED    // Server: accepted socket connection at socket level only (missing SC connection level)
} SOPC_Socket_State;

typedef struct SOPC_Socket
{
    uint32_t socketIdx;    /* Index in the socket array */
    uint32_t connectionId; /* High-level associated connection id
                             (secure channel connection index when state = CONNECTING/CONNECTED only
                              OR endpoint description configuration index when state = LISTENING only) */
    Socket sock;
    SOPC_AsyncQueue* writeQueue;
    bool waitTreatNetworkEvent; /* Synchronization flag between socket network thread and event manager thread. Once a
                                   network event is received and triggered an event to be treated by a socket event
                                   manager, the flag is set and no network event searched until triggered event is
                                   treated. */
    bool isNotWritable; // Indicates when a write attempt blocked, the flag is set until a write event occurs on socket
    bool isUsed;        /* Indicates if the socket is free (false) or used (true) */
    // false if it is a client connection, otherwise it is a server connection (linked to a listener)
    bool isServerConnection;
    SOPC_Socket_State state;
    // addresses for connection
    void* connectAddrs;           // Possible connection addresses (to free on connection)
    void* nextConnectAttemptAddr; // Next connection attempt address
    // number of connection for a listener (state = LISTENING)
    uint32_t listenerConnections;
    // define if isServerConnection != false
    uint32_t listenerSocketIdx;
} SOPC_Socket;

/** @brief Array containing all sockets that can be used */
extern SOPC_Socket socketsArray[SOPC_MAX_SOCKETS];
/** @brief Mutex to lock when using array containing all sockets
 *         or changing isUsed attribute of a socket (which determine validity in array).
 *
 *  Note: necessary since the socket network event manager runs on a cyclic thread
 *        in addition to the event dispatcher thread */
extern Mutex socketsMutex;

extern SOPC_EventHandler* socketsInputEventHandler;
extern SOPC_EventHandler* socketsEventHandler;

/** @brief Initialize the array of sockets */
void SOPC_SocketsInternalContext_Initialize(void);

/** @brief Clear the array of sockets */
void SOPC_SocketsInternalContext_Clear(void);

/** @brief Returns an unused socket from the array of sockets or NULL if none available
 *         In case socket is not a listnener, the write buffer queue is initialized.
 *  Note: caller must lock the mutex before calling it
 */
SOPC_Socket* SOPC_SocketsInternalContext_GetFreeSocketNoLock(bool isListener);

/** @brief Close the socket and set it as not used anymore.
 *  Note: caller must lock the mutex before calling it
 *  Note2: defined here since it modifies validity of socket in array
 */
void SOPC_SocketsInternalContext_CloseSocketNoLock(uint32_t socketIdx);

/** @brief Close the socket and set it as not used anymore.
 *  (automatic lock of the mutex during call).
 *  Note: defined here since it modifies validity of socket in array
 */
void SOPC_SocketsInternalContext_CloseSocketLock(uint32_t socketIdx);

void SOPC_Sockets_Emit(int32_t event, uint32_t eltId, void* params, uintptr_t auxParam);

#endif /* SOPC_SOCKETS_INTERNAL_CTX_H_ */
