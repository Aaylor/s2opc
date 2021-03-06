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
 * \brief A getEnpoints example using the high-level client API
 *
 * Requires the toolkit_test_server to be running.
 * Retrieve GetEndpoints information.
 * Then closes the toolkit.
 *
 */

#include <assert.h>
#include <stdio.h>

#include "libs2opc_client_cmds.h"

static void print_endpoints(SOPC_ClientHelper_GetEndpointsResult* result)
{
    if (NULL == result)
    {
        return;
    }
    printf("Server has %d endpoints.\n", result->nbOfEndpoints);

    for (int32_t i = 0; i < result->nbOfEndpoints; i++)
    {
        printf("Endpoint #%d:\n", i);
        printf(" - url: %s\n", result->endpoints[i].endpointUrl);
        printf(" - security level: %d\n", result->endpoints[i].securityLevel);
        printf(" - security mode: %d\n", result->endpoints[i].security_mode);
        printf(" - security policy Uri: %s\n", result->endpoints[i].security_policyUri);
        printf(" - transport profile Uri: %s\n", result->endpoints[i].transportProfileUri);

        SOPC_ClientHelper_UserIdentityToken* userIds = result->endpoints[i].userIdentityTokens;
        for (int32_t j = 0; j < result->endpoints[i].nbOfUserIdentityTokens; j++)
        {
            printf("  - User Identity #%d\n", j);
            printf("    - policy Id: %s\n", userIds[j].policyId);
            printf("    - token type: %d\n", userIds[j].tokenType);
            printf("    - issued token type: %s\n", userIds[j].issuedTokenType);
            printf("    - issuer endpoint Url: %s\n", userIds[j].issuerEndpointUrl);
            printf("    - security policy Uri: %s\n", userIds[j].securityPolicyUri);
        }
    }
}

static void free_endpoints(SOPC_ClientHelper_GetEndpointsResult* result)
{
    if (NULL != result)
    {
        if (NULL != result->endpoints)
        {
            for (int32_t i = 0; i < result->nbOfEndpoints; i++)
            {
                free(result->endpoints[i].endpointUrl);
                free(result->endpoints[i].security_policyUri);
                free(result->endpoints[i].transportProfileUri);
                if (NULL != result->endpoints[i].userIdentityTokens)
                {
                    for (int32_t j = 0; j < result->endpoints[i].nbOfUserIdentityTokens; j++)
                    {
                        free(result->endpoints[i].userIdentityTokens[j].policyId);
                        free(result->endpoints[i].userIdentityTokens[j].issuedTokenType);
                        free(result->endpoints[i].userIdentityTokens[j].issuerEndpointUrl);
                        free(result->endpoints[i].userIdentityTokens[j].securityPolicyUri);
                    }
                    free(result->endpoints[i].userIdentityTokens);
                }
            }
            free(result->endpoints);
        }
        free(result);
    }
}

int main(int argc, char* const argv[])
{
    (void) (argc);
    (void) (argv);

    int res = 0;

    /* Initialize the toolkit */
    SOPC_ClientHelper_Initialize("./s2opc_wrapper_get_endpoints_logs/", SOPC_TOOLKIT_LOG_LEVEL_DEBUG, NULL);

    const char* endpoint_url = "opc.tcp://localhost:4841";

    /* GetEndpoints */
    SOPC_ClientHelper_GetEndpointsResult* getEndpointResult;
    res = SOPC_ClientHelper_GetEndpoints(endpoint_url, &getEndpointResult);

    if (0 == res)
    {
        print_endpoints(getEndpointResult);
        free_endpoints(getEndpointResult);
    }
    else
    {
        printf("GetEndpoints FAILED, error code: %d\n", res);
    }

    /* Close the toolkit */
    SOPC_ClientHelper_Finalize();

    return res;
}
