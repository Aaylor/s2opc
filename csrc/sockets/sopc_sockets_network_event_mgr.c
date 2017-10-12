/*
 *  Copyright (C) 2016 Systerel and others.
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

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "sopc_sockets_network_event_mgr.h"

#include "sopc_sockets_internal_ctx.h"
#include "sopc_sockets_api.h"

#include "sopc_threads.h"
#include "sopc_mutexes.h"
#include "sopc_time.h"

static struct
{
    bool     initDone;
    bool     stopFlag;
    Mutex    tMutex;
    Thread   thread;
} receptionThread = {
    .initDone = false,
    .stopFlag = false,
};

// Treat sockets events if some are present or wait for events (until timeout)
static bool SOPC_SocketsNetworkEventMgr_TreatSocketsEvents(uint32_t msecTimeout){
    bool result = true;
    uint32_t idx = 0;
    bool socketsUsed = false;
    int32_t nbReady = 0;
    SOPC_Socket* uaSock = NULL;
    SOPC_Socket* acceptSock = NULL;
    SocketSet readSet, writeSet, exceptSet;

    SocketSet_Clear(&readSet);
    SocketSet_Clear(&writeSet);
    SocketSet_Clear(&exceptSet);

    Mutex_Lock(&socketsMutex);

    // Add used sockets in the correct socket sets
    for(idx = 0; idx < SOPC_MAX_SOCKETS; idx++){
        uaSock = &(socketsArray[idx]);
        if(uaSock->isUsed != false &&
           uaSock->state != SOCKET_STATE_CLOSED &&
           uaSock->state != SOCKET_STATE_ACCEPTED){ // Note: accepted state is a state in which we do not know what to do
                                                    //       in case of data received (no high-level connection set).
                                                    //       Wait CONNECTED state for those sockets to treat events again.
            socketsUsed = true;
            if(uaSock->state == SOCKET_STATE_CONNECTING){
                SocketSet_Add(uaSock->sock, &writeSet);
            }else{
                SocketSet_Add(uaSock->sock, &readSet);
            }
            SocketSet_Add(uaSock->sock, &exceptSet);
        }
    }

    Mutex_Unlock(&socketsMutex);

    if(socketsUsed == false){
        // In case no socket is in use, do not call select (*WaitSocketEvents)
        // since it returns an error with WinSockets
        SOPC_Sleep(msecTimeout);
        nbReady = 0;
    }else{
        // Returns number of ready descriptor or -1 in case of error
        nbReady = Socket_WaitSocketEvents(&readSet, &writeSet, &exceptSet, msecTimeout);
    }

    Mutex_Lock(&socketsMutex);

    if(nbReady < 0){
        // Call to wait events failed
        result = false;
    }else if(nbReady > 0){
        for(idx = 0; idx < SOPC_MAX_SOCKETS; idx++){
            uaSock = &(socketsArray[idx]);
            if(uaSock->isUsed != false){

                if(uaSock->state == SOCKET_STATE_CONNECTING){
                    /* Socket is currently in connecting attempt: check WRITE events */

                    if(SocketSet_IsPresent(uaSock->sock, &writeSet) != false){
                        // Check connection erros: mandatory when non blocking connection
                        if(STATUS_OK != Socket_CheckAckConnect(uaSock->sock)){

                            SOPC_Sockets_EnqueueEvent(INT_SOCKET_CONNECTION_ATTEMPT_FAILED,
                                                      idx,
                                                      NULL,
                                                      0);

                        }else{
                            uaSock->state = SOCKET_STATE_CONNECTED;

                            SOPC_Sockets_EnqueueEvent(INT_SOCKET_CONNECTED,
                                                      idx,
                                                      NULL,
                                                      0);
                        }
                    }
                }else{
                    /* Socket is not in connecting state: check READ and WRITE events */

                    if(SocketSet_IsPresent(uaSock->sock, &readSet) != false){
                        if(uaSock->state == SOCKET_STATE_CONNECTED){

                            SOPC_Sockets_EnqueueEvent(INT_SOCKET_READY_TO_READ,
                                                      idx,
                                                      NULL,
                                                      0);

                        }else if(uaSock->state == SOCKET_STATE_LISTENING){
                            if(uaSock->listenerConnections < SOPC_MAX_SOCKETS_CONNECTIONS){
                                acceptSock = SOPC_SocketsInternalContext_GetFreeSocketNoLock(false);
                            }
                            if(acceptSock == NULL){
                                // TODO: log refusing new sockets due to limit
                            }else{
                                if(STATUS_OK == Socket_Accept(uaSock->sock,
                                                              1, // Non blocking socket
                                                              &acceptSock->sock)){
                                    acceptSock->isUsed = true;
                                    acceptSock->isServerConnection = true;
                                    acceptSock->listenerSocketIdx = uaSock->socketIdx;
                                    acceptSock->state = SOCKET_STATE_ACCEPTED;
                                    // Temporarly copy endpoint description config index (waiting for SC connection index)
                                    acceptSock->connectionId = uaSock->connectionId;

                                    SOPC_Sockets_EnqueueEvent(INT_SOCKET_ACCEPTED,
                                                              acceptSock->socketIdx,
                                                              NULL,
                                                              uaSock->socketIdx);
                                }
                            }
                        }else{
                            // TODO: log an error
                            SOPC_Sockets_EnqueueEvent(INT_SOCKET_CLOSE,
                                                      idx,
                                                      NULL,
                                                      0);
                        }
                    }else if(SocketSet_IsPresent(uaSock->sock, &writeSet) != false){
                        if(uaSock->state == SOCKET_STATE_CONNECTED){
                            // Indicates that socket is writable again
                            SOPC_Sockets_EnqueueEvent(INT_SOCKET_READY_TO_WRITE,
                                                      idx,
                                                      NULL,
                                                      0);
                        }else{
                            // TODO: log an error
                            SOPC_Sockets_EnqueueEvent(INT_SOCKET_CLOSE,
                                                      idx,
                                                      NULL,
                                                      0);
                        }
                    }

                }

                // In any state check EXCEPT events
                if(SocketSet_IsPresent(uaSock->sock, &exceptSet) != false){
                    // TODO: retrieve exception and log an error
                    SOPC_Sockets_EnqueueEvent(INT_SOCKET_CLOSE,
                            idx,
                            NULL,
                            0);
                }
            }
        }
    }

    Mutex_Unlock(&socketsMutex);

    return result;
}


static void* SOPC_SocketsNetworkEventMgr_CyclicThreadLoop(void* nullData){
    (void) nullData;
    while(receptionThread.stopFlag == false){
        SOPC_SocketsNetworkEventMgr_TreatSocketsEvents(CYCLE_TIMEOUT_MS);
        SOPC_Sleep(1);
    }
    return NULL;
}

static bool SOPC_SocketsNetworkEventMgr_CyclicThreadStart(){
    bool result = false;
    if(receptionThread.initDone == false){
        Mutex_Initialization(&receptionThread.tMutex);
        Mutex_Lock(&receptionThread.tMutex);
        receptionThread.initDone = true;
        receptionThread.stopFlag = false;
        SOPC_Thread_Create(&receptionThread.thread, SOPC_SocketsNetworkEventMgr_CyclicThreadLoop, NULL);
        Mutex_Unlock(&receptionThread.tMutex);
        result = true;
    }
    return result;
}

static void SOPC_SocketsNetworkEventMgr_CyclicThreadStop(){
    if(receptionThread.initDone != false){
        Mutex_Lock(&receptionThread.tMutex);
        // stop the reception thread
        receptionThread.stopFlag = true;
        if(receptionThread.stopFlag != false){
            SOPC_Thread_Join(receptionThread.thread);
        }
        Mutex_Unlock(&receptionThread.tMutex);
        Mutex_Clear(&receptionThread.tMutex);
        receptionThread.initDone = false;
    }
}

void SOPC_SocketsNetworkEventMgr_Initialize(){
    SOPC_SocketsNetworkEventMgr_CyclicThreadStart();
}

void SOPC_SocketsNetworkEventMgr_Clear(){
    SOPC_SocketsNetworkEventMgr_CyclicThreadStop();
}