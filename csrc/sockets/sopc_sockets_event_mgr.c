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
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "opcua_statuscodes.h"

#include "sopc_sockets_event_mgr.h"

#include "sopc_sockets_api.h"
#include "sopc_sockets_internal_ctx.h"
#include "sopc_secure_channels_api.h"
#include "sopc_buffer.h"
#include "sopc_helper_uri.h"

#include "p_sockets.h"



static bool ParseURI (const char* uri, char** hostname, char** port){
    bool result = false;
    size_t hostnameLength = 0;
    size_t portIdx = 0;
    size_t portLength = 0;
    char *lHostname = NULL;
    char *lPort = NULL;

    if(uri != NULL && hostname != NULL && port != NULL){
        result = SOPC_Helper_URI_ParseTcpUaUri(uri, &hostnameLength, &portIdx, &portLength);
    }

    if(result != false){
        if(portIdx != 0 && hostnameLength != 0 && portLength != 0){
            lHostname = malloc(sizeof(char) * (hostnameLength+1));
            if(lHostname == NULL)
                return false;
            if(lHostname != memcpy(lHostname, &(uri[10]), hostnameLength)){
                free(lHostname);
                return false;
            }
            lHostname[hostnameLength] = '\0';

            lPort = malloc(sizeof(char) * (portLength+1));
            if(lPort == NULL){
                free(lHostname);
                return false;
            }
            if(lPort != memcpy(lPort, &(uri[portIdx]), portLength)){
                free(lHostname);
                free(lPort);
                return false;
            }
            lPort[portLength] = '\0';
            *hostname = lHostname;
            *port = lPort;
        }else{
            result = false;
        }
    }

    return result;
}

static bool SOPC_SocketsEventMgr_ConnectClient(SOPC_Socket*        connectSocket,
                                               Socket_AddressInfo* addr){
    bool result = false;
    if(connectSocket != NULL && addr != NULL && connectSocket->state == SOCKET_STATE_CLOSED){
        if(STATUS_OK == Socket_CreateNew(addr,
                                         false, // Do not reuse
                                         true,  // Non blocking socket
                                         &connectSocket->sock)){
            result = true;
        }
        if(result != false){
            if(STATUS_OK != Socket_Connect(connectSocket->sock, addr)){
                result = false;
            }
        }
        if(result != false){
            connectSocket->state = SOCKET_STATE_CONNECTING;
        }

        if(result == false){
            SOPC_SocketsInternalContext_CloseSocket(connectSocket->socketIdx);
        }
    }
    return result;
}

static bool SOPC_SocketsEventMgr_NextConnectClientAttempt(SOPC_Socket* connectSocket){
    bool result = false;
    if(connectSocket != false && connectSocket->state == SOCKET_STATE_CONNECTING){
        // Close precedently created socket
        Socket_Close(&connectSocket->sock);

        // Check if next connection attempt available
        Socket_AddressInfo* nextAddr = (Socket_AddressInfo*) connectSocket->nextConnectAttemptAddr;
        if(nextAddr != NULL){
            result = SOPC_SocketsEventMgr_ConnectClient(connectSocket,
                                                            nextAddr);
            if(result != false){
                connectSocket->nextConnectAttemptAddr = NULL;
            }else{
                connectSocket->nextConnectAttemptAddr = Socket_AddrInfo_IterNext(nextAddr);
            }

            // No more attempts possible: free the attempts addresses
            if(connectSocket->nextConnectAttemptAddr == NULL){
                Socket_AddrInfoDelete((Socket_AddressInfo**) &connectSocket->connectAddrs);
                connectSocket->connectAddrs = NULL;
            }
        }
    }
    return result;
}

static SOPC_Socket* SOPC_SocketsEventMgr_CreateClientSocket(const char* uri)
{
    SOPC_Socket* resultSocket = NULL;
    Socket_AddressInfo *res = NULL, *p = NULL;
    SOPC_Socket* freeSocket = NULL;
    bool result = false;
    bool connectResult = false;
    char *hostname = NULL;
    char *port = NULL;

    if(uri != NULL){
        Mutex_Lock(&socketsMutex);
        result = ParseURI(uri, &hostname, &port);
        if(result != false){
            freeSocket = SOPC_SocketsInternalContext_GetFreeSocketNoLock(false);
            if(freeSocket == NULL){
                result = false;
            }
        }

        if(result != false){
            if(STATUS_OK != Socket_AddrInfo_Get(hostname, port, &res)){
                result = false;
            }
        }

        if(result != false){
            // Try to connect on IP addresses provided (IPV4 and IPV6)
            for(p = res;p != NULL && connectResult == false; p = Socket_AddrInfo_IterNext(p)) {
                connectResult = SOPC_SocketsEventMgr_ConnectClient(freeSocket, p);
            }
            result = connectResult;
        }

        if(result != false){
            if(p != NULL){
                // Next attempts addresses for connections remaining: store to use in case of async. connection failure
                freeSocket->nextConnectAttemptAddr = p;
                freeSocket->connectAddrs = res;
            }

            resultSocket = freeSocket;
        }

        if(result == false || // connection already failed => do not keep addresses for next attempts
           (res != NULL && freeSocket->connectAddrs == NULL)) // async connecting but NO next attempts remaining (if current fails)
        {
            Socket_AddrInfoDelete(&res);
        }

        if(result == false){
            // Set as closed to be removed from used socket
            SOPC_SocketsInternalContext_CloseSocketNoLock(freeSocket->socketIdx);
        }

        if(port != NULL){
            free(port);
        }

        if(hostname != NULL){
            free(hostname);
        }

        Mutex_Unlock(&socketsMutex);
    }

    return resultSocket;
}

static SOPC_Socket* SOPC_SocketsEventMgr_CreateServerSocket(const char* uri,
                                                            uint8_t     listenAllItfs)
{
    SOPC_Socket* resultSocket = NULL;
    bool result = false;
    Socket_AddressInfo *res = NULL, *p = NULL;
    bool attemptWithIPV6 = true;
    SOPC_Socket* freeSocket = NULL;
    bool listenResult = false;
    char *hostname = NULL;
    char *port = NULL;

    if(uri != NULL){
        Mutex_Lock(&socketsMutex);
        result = ParseURI(uri, &hostname, &port);
        if(result != false){
            freeSocket = SOPC_SocketsInternalContext_GetFreeSocketNoLock(true);
            if(freeSocket == NULL){
                result = false;
            }
        }

        if(result != false){
            if(listenAllItfs != false){
                free(hostname);
                hostname = NULL;
            }

            if(STATUS_OK != Socket_AddrInfo_Get(hostname, port, &res)){
                result = false;
            }
        }

        if(result != false){

            // Try to connect on IP addresses provided (IPV4 and IPV6)
            p = res;
            attemptWithIPV6 = true; // IPV6 first since it supports IPV4
            while((p != NULL || attemptWithIPV6 != false) && listenResult == false){

                if(p == NULL && attemptWithIPV6 != false){
                    // Failed with IPV6 addresses (or none was present), now try with not IPV6 addresses
                    attemptWithIPV6 = false;
                    p = res;
                }else{
                    if((attemptWithIPV6 != false && Socket_AddrInfo_IsIPV6(p) != false) ||
                       (attemptWithIPV6 == false && Socket_AddrInfo_IsIPV6(p) == false)){
                        if(STATUS_OK != Socket_CreateNew(p,
                                                         true, // Reuse
                                                         true, // Non blocking socket
                                                         &freeSocket->sock)){
                            result = false;
                        }

                        if (result != false){
                            if(STATUS_OK != Socket_Listen(freeSocket->sock, p)){
                                result = false;
                            }
                        }

                        if(result != false){
                            freeSocket->state = SOCKET_STATE_LISTENING;
                            listenResult = true;
                        }

                    }
                    p = Socket_AddrInfo_IterNext(p);
                }
            }
        }

        if(port != NULL){
            free(port);
        }
        if(hostname != NULL){
            free(hostname);
        }


        if(result != false){
            resultSocket = freeSocket;
        }else{
            if(freeSocket != NULL){
                SOPC_SocketsInternalContext_CloseSocketNoLock(freeSocket->socketIdx);
            }
        }

        Mutex_Unlock(&socketsMutex);
    }

    Socket_AddrInfoDelete(&res);

    return resultSocket;
}

static bool SOPC_SocketsEventMgr_TreatWriteBuffer(SOPC_Socket* socket){
    bool nothingToDequeue = false;
    bool writeQueueResult = true;
    bool writeBlocked = false;
    SOPC_Buffer* buffer = NULL;
    uint8_t* data = NULL;
    uint32_t count = 0;
    uint32_t sentBytes = 0;
    SOPC_StatusCode status = STATUS_NOK;

    if(NULL == socket || NULL == socket->writeQueue ||
       socket->sock == SOPC_INVALID_SOCKET ||
       socket->isNotWritable != false){
        writeQueueResult = false;
    }

    /* Dequeue message to write and sent through socket until nothing no message remain or socket write blocked */
    while(writeQueueResult != false && nothingToDequeue == false && writeBlocked == false){
        status = SOPC_AsyncQueue_NonBlockingDequeue(socket->writeQueue, (void**) &buffer);
        if(OpcUa_BadWouldBlock == status){
            nothingToDequeue = true;
        }else if(STATUS_OK != status || NULL == buffer){
            writeQueueResult = false;
        }
        if(false != writeQueueResult && false == nothingToDequeue){
            sentBytes = 0;
            data = &(buffer->data[buffer->position]);
            count = buffer->length - buffer->position;
            status = Socket_Write(socket->sock, data, count, &sentBytes);
            if(OpcUa_BadWouldBlock == status){
                writeBlocked = true;
            }else if(STATUS_OK != status){
                writeQueueResult = false;
                SOPC_Buffer_Delete(buffer);
            }else{
                SOPC_Buffer_Delete(buffer);
            }
        }
    }

    if(writeBlocked != false){
        // Socket write blocked, wait for a ready to write event
        socket->isNotWritable = true;
        // (Re-enqueue) updated buffer position for next attempt
        buffer->position = buffer->position + sentBytes;
        // Re-enqueue in LIFO mode to be the next buffer to treat
        status = SOPC_AsyncQueue_BlockingEnqueueFirstOut(socket->writeQueue, buffer);
        assert(STATUS_OK == status);
    }else{

    }

    return writeQueueResult;
}

void SOPC_SocketsEventMgr_Dispatcher (int32_t  event,
                                      uint32_t eltId,
                                      void*    params,
                                      uint32_t auxParam){
    bool result = false;
    SOPC_Sockets_InputEvent socketEvent = (SOPC_Sockets_InputEvent) event;
    SOPC_Socket* socketElt = NULL;
    SOPC_Buffer* buffer = NULL;
    int32_t readBytes = 0;
    SOPC_StatusCode status = STATUS_NOK;

    switch(socketEvent){
    case SOCKET_CREATE_SERVER:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: SOCKET_CREATE_SERVER\n");
        }
        /*
        id = endpoint description config index,
        params = (const char*) URI,
        auxParms = (bool) listenAllInterfaces
        */
        socketElt = SOPC_SocketsEventMgr_CreateServerSocket((const char*) params,
                                                         (bool) auxParam);
        if(NULL != socketElt){
            socketElt->connectionId = eltId;
            SOPC_SecureChannels_EnqueueEvent(SOCKET_LISTENER_OPENED,
                                             eltId,
                                             NULL,
                                             socketElt->socketIdx);
        }else{
            SOPC_SecureChannels_EnqueueEvent(SOCKET_LISTENER_FAILURE,
                                             eltId,
                                             NULL,
                                             0);
        }
        break;
    case SOCKET_ACCEPTED_CONNECTION:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: SOCKET_ACCEPTED_CONNECTION\n");
        }
        /* id = socket index,
         * auxParam = secure channel connection index associated to accepted connection */
        Mutex_Lock(&socketsMutex);
        socketElt = &socketsArray[eltId];
        if(socketElt->state == SOCKET_STATE_ACCEPTED){
            socketElt->connectionId = auxParam;
            socketElt->state = SOCKET_STATE_CONNECTED;
        }else{
            SOPC_SocketsInternalContext_CloseSocketNoLock(eltId);
        }
        Mutex_Unlock(&socketsMutex);
        break;
    case SOCKET_CREATE_CLIENT:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: SOCKET_CREATE_CLIENT\n");
        }
        /*
        id = secure channel connection index,
        params = (const char*) URI
        */
        socketElt = SOPC_SocketsEventMgr_CreateClientSocket((const char*) params);
        if(NULL != socketElt){
            socketElt->connectionId = eltId;

        }else{
            SOPC_SecureChannels_EnqueueEvent(SOCKET_FAILURE,
                                             eltId,
                                             NULL,
                                             0);
        }
        break;
    case SOCKET_CLOSE:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: SOCKET_CLOSE\n");
        }
        /* id = socket index */
        socketElt = &socketsArray[eltId];

        if(socketElt->isServerConnection != false){
            // Management of number of connection on a listener
            if(socketsArray[socketElt->socketIdx].state == SOCKET_STATE_LISTENING){
                socketsArray[socketElt->socketIdx].listenerConnections--;
            }
        }

        SOPC_SocketsInternalContext_CloseSocket(eltId);
        break;
    case SOCKET_WRITE:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: SOCKET_WRITE\n");
        }
        /*
        id = socket index,
        params = (SOPC_Buffer*) msg buffer
        */
        socketElt = &socketsArray[eltId];
        result = true;
        buffer = (SOPC_Buffer*) params;

        if(socketElt->state == SOCKET_STATE_CONNECTED && NULL != buffer){
            // Note: No need to lock mutex,
            // socket state cannot be changed from CONNECTED state by another thread

            // Prepare buffer to be written (position set to 0 since it has been written precedently)
            assert(STATUS_OK == SOPC_Buffer_SetPosition(buffer, 0));
            // Enqueue message buffer to send
            SOPC_AsyncQueue_BlockingEnqueue(socketElt->writeQueue, params);
            result = true;
            if(socketElt->isNotWritable == false){
                // If socket is in writable state: trigger the socket write treatment
                result = SOPC_SocketsEventMgr_TreatWriteBuffer(socketElt);
            }
        }else{
            if(NULL != buffer){
                // Free the buffer
                SOPC_Buffer_Delete(buffer);
            }
            result = false;
        }

        if(result == false){
            SOPC_SecureChannels_EnqueueEvent(SOCKET_FAILURE,
                                             socketElt->connectionId,
                                             NULL,
                                             eltId);
            // Definitively close the socket
            SOPC_SocketsInternalContext_CloseSocket(eltId);
        }

        break;
    case INT_SOCKET_ACCEPTED:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: INT_SOCKET_ACCEPTED\n");
        }
        socketElt = &socketsArray[eltId];

        // State was set to accepted by network event manager
        assert(socketElt->state == SOCKET_STATE_ACCEPTED);
        assert(socketsArray[auxParam].state == SOCKET_STATE_LISTENING);
        // Increment number of connections on listener
        socketsArray[auxParam].listenerConnections++;

        // Send to the secure channel listener state manager and wait for SOCKET_ACCEPTED_CONNECTION for association with connection index
        SOPC_SecureChannels_EnqueueEvent(SOCKET_LISTENER_CONNECTION,
                                         socketElt->connectionId, // endpoint description config index
                                         NULL,
                                         eltId);
        break;
    case INT_SOCKET_CONNECTION_ATTEMPT_FAILED:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: INT_SOCKET_CONNECTION_ATTEMPT_FAILED\n");
        }
        socketElt = &socketsArray[eltId];
        // State is connecting
        assert(socketElt->state == SOCKET_STATE_CONNECTING);

        // Will do a new attempt with next possible address if possible
        result = SOPC_SocketsEventMgr_NextConnectClientAttempt(socketElt);
        if(result == false){
            // No new attempt possible, indicates socket connection failed and close the socket
            SOPC_SecureChannels_EnqueueEvent(SOCKET_FAILURE,
                                             socketElt->connectionId, // endpoint description config index
                                             NULL,
                                             0);
            // Definitively close the socket
            SOPC_SocketsInternalContext_CloseSocket(eltId);
        }
        break;
    case INT_SOCKET_CONNECTED:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: INT_SOCKET_CONNECTED\n");
        }
        socketElt = &socketsArray[eltId];
        // State was set to connected by network manager
        assert(socketElt->state == SOCKET_STATE_CONNECTED);

        // No more attempts expected: free the attempts addresses
        if(socketElt->connectAddrs != NULL){
            Socket_AddrInfoDelete((Socket_AddressInfo**) &socketElt->connectAddrs);
            socketElt->connectAddrs = NULL;
            socketElt->nextConnectAttemptAddr = NULL;
        }

        // Notify connection
        SOPC_SecureChannels_EnqueueEvent(SOCKET_CONNECTION,
                                         socketElt->connectionId, // secure channel connection index
                                         NULL,
                                         eltId);
        break;
    case INT_SOCKET_CLOSE:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: INT_SOCKET_CLOSE\n");
        }
        socketElt = &socketsArray[eltId];

        if(socketElt->state == SOCKET_STATE_LISTENING){
            SOPC_SecureChannels_EnqueueEvent(SOCKET_LISTENER_FAILURE,
                                             socketElt->connectionId,
                                             NULL,
                                             eltId);
        }else{
            if(socketElt->isServerConnection != false){
                // Management of number of connection on a listener
                if(socketsArray[socketElt->socketIdx].state == SOCKET_STATE_LISTENING){
                    socketsArray[socketElt->socketIdx].listenerConnections--;
                }
            }
            SOPC_SecureChannels_EnqueueEvent(SOCKET_FAILURE,
                                             socketElt->connectionId,
                                             NULL,
                                             eltId);
        }

        SOPC_SocketsInternalContext_CloseSocket(eltId);
        break;
    case INT_SOCKET_READY_TO_READ:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: INT_SOCKET_READY_TO_READ\n");
        }
        socketElt = &socketsArray[eltId];

        buffer = SOPC_Buffer_Create(SOPC_MAX_MESSAGE_LENGTH);
        status = Socket_Read(socketElt->sock, buffer->data, SOPC_MAX_MESSAGE_LENGTH, &readBytes);
        if(status == OpcUa_BadWouldBlock){
            // wait next ready to read event
        }else if(status == STATUS_OK && readBytes >= 0){
            // Update buffer lengtn
            SOPC_Buffer_SetDataLength(buffer, readBytes);
            // Transmit to secure channel connection associated
            SOPC_SecureChannels_EnqueueEvent(SOCKET_RCV_BYTES,
                                             socketElt->connectionId,
                                             (void*) buffer,
                                             eltId);
        }else{
            // Failure during read operation
            SOPC_SecureChannels_EnqueueEvent(SOCKET_FAILURE,
                                             socketElt->connectionId,
                                             NULL,
                                             eltId);
            SOPC_SocketsInternalContext_CloseSocket(eltId);
        }

        break;
    case INT_SOCKET_READY_TO_WRITE:
        if(SOPC_DEBUG_PRINTING != false){
            printf("SocketEvent: INT_SOCKET_READY_TO_WRITE\n");
        }
        socketElt = &socketsArray[eltId];

        // Socket is connected
        assert(socketElt->state == SOCKET_STATE_CONNECTED);

        if(socketElt->isNotWritable == false){
            // Not expected: ignore
        }else{
            // Socket was not writable
            socketElt->isNotWritable = false;
            // Trigger the socket write treatment
            SOPC_SocketsEventMgr_TreatWriteBuffer(socketElt);
        }
        break;
    default:
        assert(false);
    }
}
