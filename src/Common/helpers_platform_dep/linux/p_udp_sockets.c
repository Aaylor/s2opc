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

#include "sopc_udp_sockets.h"

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

static SOPC_ReturnStatus SOPC_UDP_Socket_AddrInfo_Get(bool IPv6,
                                                      const char* node,
                                                      const char* port,
                                                      SOPC_Socket_AddressInfo** addrs)
{
    SOPC_ReturnStatus status = SOPC_STATUS_INVALID_PARAMETERS;
    SOPC_Socket_AddressInfo hints;
    memset(&hints, 0, sizeof(SOPC_Socket_AddressInfo));
    hints.ai_family = (IPv6 ? AF_INET6 : AF_INET);
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = IPPROTO_UDP;

    if ((node != NULL || port != NULL) && addrs != NULL)
    {
        if (getaddrinfo(node, port, &hints, addrs) != 0)
        {
            status = SOPC_STATUS_NOK;
        }
        else
        {
            status = SOPC_STATUS_OK;
        }
    }
    return status;
}

SOPC_Socket_AddressInfo* SOPC_UDP_SocketAddress_Create(bool IPv6, const char* node, const char* service)
{
    SOPC_Socket_AddressInfo* addr = NULL;
    SOPC_ReturnStatus status = SOPC_UDP_Socket_AddrInfo_Get(IPv6, node, service, &addr);
    if (SOPC_STATUS_OK != status)
    {
        addr = NULL;
    }
    return addr;
}

void SOPC_UDP_SocketAddress_Delete(SOPC_Socket_AddressInfo** addr)
{
    SOPC_Socket_AddrInfoDelete(addr);
}

SOPC_ReturnStatus SOPC_UDP_Socket_Set_MulticastTTL(Socket sock, uint8_t TTL_scope)
{
    int setOptStatus = -1;

    if (sock != SOPC_INVALID_SOCKET)
    {
        setOptStatus = setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &TTL_scope, sizeof(TTL_scope));

        if (setOptStatus < 0)
        {
            return SOPC_STATUS_NOK;
        }
        else
        {
            return SOPC_STATUS_OK;
        }
    }
    return SOPC_STATUS_INVALID_PARAMETERS;
}

static void* get_ai_addr(const SOPC_Socket_AddressInfo* addr)
{
    return addr->ai_addr;
}

static struct ip_mreqn SOPC_Internal_Fill_IP_mreq(const SOPC_Socket_AddressInfo* multiCastAddr,
                                                  const SOPC_Socket_AddressInfo* localAddr,
                                                  unsigned int if_index)
{
    assert(multiCastAddr != NULL);
    struct ip_mreqn membership;

    membership.imr_multiaddr.s_addr = ((struct sockaddr_in*) get_ai_addr(multiCastAddr))->sin_addr.s_addr;
    assert(if_index > 0);
    membership.imr_ifindex = (int) if_index;
    if (localAddr == NULL)
    {
        membership.imr_address.s_addr = htonl(INADDR_ANY);
    }
    else
    {
        membership.imr_address.s_addr = ((struct sockaddr_in*) get_ai_addr(localAddr))->sin_addr.s_addr;
    }
    return membership;
}

static struct ipv6_mreq SOPC_Internal_Fill_IP6_mreq(const SOPC_Socket_AddressInfo* multiCastAddr,
                                                    const SOPC_Socket_AddressInfo* localAddr,
                                                    unsigned int if_index)
{
    (void) localAddr;
    assert(if_index > 0);
    assert(multiCastAddr != NULL);
    struct ipv6_mreq membership;

    membership.ipv6mr_multiaddr = ((struct sockaddr_in6*) get_ai_addr(multiCastAddr))->sin6_addr;
    membership.ipv6mr_interface = if_index;

    return membership;
}

SOPC_ReturnStatus SOPC_UDP_Socket_AddMembership(Socket sock,
                                                const SOPC_Socket_AddressInfo* multicast,
                                                const SOPC_Socket_AddressInfo* local)
{
    uint32_t counter = 0;
    bool atLeastOneItfSuccess = false;

    if (multicast == NULL || local == NULL || sock == SOPC_INVALID_SOCKET || multicast->ai_family != local->ai_family)
    {
        return SOPC_STATUS_INVALID_PARAMETERS;
    }

    struct ifaddrs* ifap = NULL;
    int result = getifaddrs(&ifap);

    if (0 != result)
    {
        return SOPC_STATUS_NOT_SUPPORTED;
    }

    for (struct ifaddrs* ifa = ifap; ifa != NULL; ifa = ifa->ifa_next)
    {
        bool optionSet = false;
        int setOptStatus = 0;
        if (ifa->ifa_addr)
        {
            if (AF_INET6 == multicast->ai_family)
            {
                if (AF_INET6 == ifa->ifa_addr->sa_family)
                {
                    struct ipv6_mreq membership =
                        SOPC_Internal_Fill_IP6_mreq(multicast, local, if_nametoindex(ifa->ifa_name));
                    setOptStatus = setsockopt(sock, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, &membership, sizeof(membership));
                    counter++;
                    optionSet = true;
                }
            }
            else
            {
                if (AF_INET == ifa->ifa_addr->sa_family)
                {
                    struct ip_mreqn membership =
                        SOPC_Internal_Fill_IP_mreq(multicast, local, if_nametoindex(ifa->ifa_name));
                    setOptStatus = setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &membership, sizeof(membership));
                    counter++;
                    optionSet = true;
                }
            }
        }

        if (optionSet)
        {
            if (setOptStatus < 0)
            {
                printf("AddMembership failure (error='%s') on interface %s\n", strerror(errno), ifa->ifa_name);
            }
            else
            {
                atLeastOneItfSuccess = true;
                printf("AddMembership success on interface %s\n", ifa->ifa_name);
            }
        }
    }

    freeifaddrs(ifap);

    if (0 == counter)
    {
        return SOPC_STATUS_NOT_SUPPORTED;
    }
    else
    {
        if (atLeastOneItfSuccess)
        {
            return SOPC_STATUS_OK;
        }
        else
        {
            return SOPC_STATUS_NOK;
        }
    }
}

SOPC_ReturnStatus SOPC_UDP_Socket_DropMembership(Socket sock,
                                                 const SOPC_Socket_AddressInfo* multicast,
                                                 const SOPC_Socket_AddressInfo* local)
{
    uint32_t counter = 0;
    bool atLeastOneItfSuccess = false;

    if (multicast == NULL || sock == SOPC_INVALID_SOCKET)
    {
        return SOPC_STATUS_INVALID_PARAMETERS;
    }

    struct ifaddrs* ifap = NULL;
    int result = getifaddrs(&ifap);

    if (0 != result)
    {
        return SOPC_STATUS_NOT_SUPPORTED;
    }

    for (struct ifaddrs* ifa = ifap; ifa != NULL; ifa = ifa->ifa_next)
    {
        int setOptStatus = 0;
        bool optionSet = false;

        if (ifa->ifa_addr)
        {
            if (AF_INET6 == multicast->ai_family)
            {
                if (AF_INET6 == ifa->ifa_addr->sa_family)
                {
                    struct ipv6_mreq membership =
                        SOPC_Internal_Fill_IP6_mreq(multicast, local, if_nametoindex(ifa->ifa_name));
                    setOptStatus =
                        setsockopt(sock, IPPROTO_IPV6, IPV6_DROP_MEMBERSHIP, &membership, sizeof(membership));
                    counter++;
                    optionSet = true;
                }
            }
            else
            {
                if (AF_INET == ifa->ifa_addr->sa_family)
                {
                    struct ip_mreqn membership =
                        SOPC_Internal_Fill_IP_mreq(multicast, local, if_nametoindex(ifa->ifa_name));
                    setOptStatus = setsockopt(sock, IPPROTO_IP, IP_DROP_MEMBERSHIP, &membership, sizeof(membership));
                    counter++;
                    optionSet = true;
                }
            }
        }

        if (optionSet)
        {
            if (setOptStatus < 0)
            {
                // Failure case on the current itf: check errno for details
            }
            else
            {
                atLeastOneItfSuccess = true;
            }
        }
    }

    freeifaddrs(ifap);

    if (0 == counter)
    {
        return SOPC_STATUS_NOT_SUPPORTED;
    }
    else
    {
        if (atLeastOneItfSuccess)
        {
            return SOPC_STATUS_OK;
        }
        else
        {
            return SOPC_STATUS_NOK;
        }
    }
}

static SOPC_ReturnStatus SOPC_UDP_Socket_CreateNew(const SOPC_Socket_AddressInfo* addr, bool setReuseAddr, Socket* sock)
{
    SOPC_ReturnStatus status = SOPC_STATUS_INVALID_PARAMETERS;
    const int trueInt = true;
    int setOptStatus = -1;
    if (addr != NULL && sock != NULL)
    {
        *sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);

        if (*sock == SOPC_INVALID_SOCKET)
        {
            status = SOPC_STATUS_NOK;
        }
        else
        {
            status = SOPC_STATUS_OK;
            setOptStatus = 0;
        }

        if (SOPC_STATUS_OK == status && setReuseAddr != false)
        {
            setOptStatus = setsockopt(*sock, SOL_SOCKET, SO_REUSEADDR, (const void*) &trueInt, sizeof(int));
        }

        /*
        // Enforce IPV6 sockets can be used for IPV4 connections (if socket is IPV6)
        if (setOptStatus != -1 && addr->addrin.sin_family == AF_INET6)
        {
            const int falseInt = false;
            setOptStatus = setsockopt(*sock, IPPROTO_IPV6, IPV6_V6ONLY, (const void*) &falseInt, sizeof(int));
        }
        */

        if (setOptStatus < 0)
        {
            status = SOPC_STATUS_NOK;
        }
    }
    return status;
}

SOPC_ReturnStatus SOPC_UDP_Socket_CreateToReceive(SOPC_Socket_AddressInfo* listenAddress,
                                                  bool setReuseAddr,
                                                  Socket* sock)
{
    SOPC_ReturnStatus status = SOPC_UDP_Socket_CreateNew(listenAddress, setReuseAddr, sock);
    if (SOPC_STATUS_OK == status)
    {
        int res = bind(*sock, listenAddress->ai_addr, listenAddress->ai_addrlen);
        if (res == -1)
        {
            SOPC_UDP_Socket_Close(sock);
            status = SOPC_STATUS_NOK;
        }
    }
    return status;
}

SOPC_ReturnStatus SOPC_UDP_Socket_CreateToSend(SOPC_Socket_AddressInfo* destAddress, Socket* sock)
{
    return SOPC_UDP_Socket_CreateNew(destAddress, false, sock);
}

SOPC_ReturnStatus SOPC_UDP_Socket_SendTo(Socket sock, const SOPC_Socket_AddressInfo* destAddr, SOPC_Buffer* buffer)
{
    if (sock == SOPC_INVALID_SOCKET || destAddr == NULL || buffer == NULL || buffer->position != 0)
    {
        return SOPC_STATUS_INVALID_PARAMETERS;
    }

    ssize_t res = sendto(sock, buffer->data, buffer->length, 0, destAddr->ai_addr, destAddr->ai_addrlen);

    if (res == -1 || (uint32_t) res != buffer->length)
    {
        return SOPC_STATUS_NOK;
    }

    return SOPC_STATUS_OK;
}

SOPC_ReturnStatus SOPC_UDP_Socket_ReceiveFrom(Socket sock, SOPC_Buffer* buffer)
{
    if (sock == SOPC_INVALID_SOCKET || buffer == NULL)
    {
        return SOPC_STATUS_INVALID_PARAMETERS;
    }

    struct sockaddr_in si_client;
    socklen_t slen = sizeof(si_client);

    ssize_t recv_len = recvfrom(sock, buffer->data, buffer->current_size, 0, (struct sockaddr*) &si_client, &slen);
    if (recv_len == -1)
    {
        return SOPC_STATUS_NOK;
    }

    buffer->length = (uint32_t) recv_len;
    if (buffer->length == buffer->current_size)
    {
        // The message could be incomplete
        return SOPC_STATUS_OUT_OF_MEMORY;
    }

    return SOPC_STATUS_OK;
}

void SOPC_UDP_Socket_Close(Socket* sock)
{
    SOPC_Socket_Close(sock);
}
