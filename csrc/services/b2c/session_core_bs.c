/*
 *  Copyright (C) 2017 Systerel and others.
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
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "sopc_builtintypes.h"
#include "sopc_encodeable.h"
#include "sopc_types.h"
#include "sopc_user_app_itf.h"
#include "sopc_secret_buffer.h"
#include "sopc_toolkit_config_internal.h"
#include "sopc_services_api.h"

#include "session_core_bs.h"

#include "sopc_crypto_profiles.h"
#include "sopc_crypto_provider.h"
#include "sopc_key_manager.h"
#include "channel_mgr_bs.h"

#include "session_core_1.h"

#define LENGTH_NONCE 32

typedef struct SessionData {
    SOPC_NodeId         sessionToken; /* IMPORTANT NOTE: on server side token (numeric value) <=> session index */
    SOPC_ByteString     nonceServer;
    SOPC_ByteString     nonceClient; /* TODO: remove ? => no need to be store if returned directly */
    OpcUa_SignatureData signatureData; /* TODO: remove ? => no need to be stored */
    constants__t_user_i user; /* TODO: remove user management */
} SessionData;

static SessionData sessionDataArray[constants__t_session_i_max + 1]; // index 0 is indet session

/*------------------------
   INITIALISATION Clause
  ------------------------*/
void session_core_bs__INITIALISATION(void) {
    SessionData* sData = NULL;
    for(int32_t idx = 0; idx <= constants__t_session_i_max; idx++){
        sData = &(sessionDataArray[idx]);
        SOPC_NodeId_Initialize(&sData->sessionToken);
        SOPC_ByteString_Initialize(&sData->nonceClient);
        SOPC_ByteString_Initialize(&sData->nonceServer);
        OpcUa_SignatureData_Initialize(&sData->signatureData);
        sData->user = constants__c_user_indet;
    }
}

/*--------------------
   OPERATIONS Clause
  --------------------*/

void session_core_bs__notify_set_session_state(
   const constants__t_session_i session_core_bs__session,
   const constants__t_sessionState session_core_bs__prec_state,
   const constants__t_sessionState session_core_bs__state){
    constants__t_channel_i channel = constants__c_channel_indet;
    bool is_client_channel = false;
    uint32_t scConfigIdx = 0;

    session_core_1__get_session_channel(session_core_bs__session, &channel);


    if(constants__c_channel_indet != channel){
        channel_mgr_1__is_client_channel(channel, &is_client_channel);
        channel_mgr_1__get_channel_info(channel, (int32_t*) &scConfigIdx);
        if(is_client_channel != false){
            if(session_core_bs__state == constants__e_session_userActivated){
                SOPC_ServicesToApp_EnqueueEvent(SOPC_AppEvent_ComEvent_Create(SE_ACTIVATED_SESSION),
                                                session_core_bs__session,
                                                NULL,
                                                scConfigIdx);
            }else if(session_core_bs__state == constants__e_session_scOrphaned ||
                     session_core_bs__state == constants__e_session_userActivating ||
                     (session_core_bs__state == constants__e_session_scActivating
                       && session_core_bs__prec_state != constants__e_session_scOrphaned)){
                // if orphaned will be reactivated or closed => notify as reactivating to avoid use of session by application
                SOPC_ServicesToApp_EnqueueEvent(SOPC_AppEvent_ComEvent_Create(SE_SESSION_REACTIVATING),
                                                session_core_bs__session,
                                                NULL,
                                                0); // unused
            }
        }
    }
}

void session_core_bs__server_get_session_from_token(
   const constants__t_session_token_i session_core_bs__session_token,
   constants__t_session_i * const session_core_bs__session) {
    constants__t_session_i result = constants__c_session_indet;
    SOPC_NodeId* requestedToken = (SOPC_NodeId*) session_core_bs__session_token;

    if(requestedToken->IdentifierType == IdentifierType_Numeric &&
       requestedToken->Data.Numeric > 0)
    {
        // Note: on server side, token <=> session index
        assert(requestedToken->Data.Numeric <= INT32_MAX);
        result = (int32_t) requestedToken->Data.Numeric;
    }

    *session_core_bs__session = result;
}

void session_core_bs__client_get_token_from_session(
   const constants__t_session_i session_core_bs__session,
   constants__t_session_token_i * const session_core_bs__session_token) {
  if(constants__c_session_indet != session_core_bs__session){
    *session_core_bs__session_token = &(sessionDataArray[session_core_bs__session].sessionToken);
  }else{
    *session_core_bs__session_token = constants__c_session_token_indet;
  }
}

void session_core_bs__server_get_fresh_session_token(
   const constants__t_session_i session_core_bs__session,
   constants__t_session_token_i * const session_core_bs__token) {
    // Important note: on server side, token is session index
    if(constants__c_session_indet != session_core_bs__session){
        // Note: Namespace = 0 for session token ?
        sessionDataArray[session_core_bs__session].sessionToken.IdentifierType = IdentifierType_Numeric;
        sessionDataArray[session_core_bs__session].sessionToken.Data.Numeric = session_core_bs__session;
        *session_core_bs__token = &(sessionDataArray[session_core_bs__session].sessionToken);
    }else{
        *session_core_bs__token = constants__c_session_token_indet;
    }
}

void session_core_bs__server_is_valid_session_token(
   const constants__t_session_token_i session_core_bs__token,
   t_bool * const session_core_bs__ret) {
    *session_core_bs__ret =  session_core_bs__token != constants__c_session_token_indet;
}

void session_core_bs__client_set_session_token(
   const constants__t_session_i session_core_bs__session,
   const constants__t_session_token_i session_core_bs__token) {
    SOPC_NodeId* sessionToken = NULL;
    if(constants__c_session_indet != session_core_bs__session &&
       constants__c_session_token_indet != session_core_bs__token){
        sessionToken = &(sessionDataArray[session_core_bs__session].sessionToken);
        if(STATUS_OK != SOPC_NodeId_Copy(sessionToken, (SOPC_NodeId*) session_core_bs__token)){
            // In case of failure, ensure session token is cleared
            SOPC_NodeId_Clear(sessionToken);
        }
    }
}

void session_core_bs__prepare_close_session(
   const constants__t_session_i session_core_bs__session,
   const constants__t_sessionState session_core_bs__state,
   const t_bool session_core_bs__is_client){

    // TODO: remove token and nonce ? Or keep token to avoid providing the same to another session until overwritten ?
    // If tokens not removed, change B model of this operation


    if(session_core_bs__is_client != false){
        if(session_core_bs__state != constants__e_session_closing &&
           session_core_bs__state != constants__e_session_userActivated){
            // If session not in closing state or already activated, it is in activation state regarding user app
            // => notify activation failed
            SOPC_ServicesToApp_EnqueueEvent(SOPC_AppEvent_ComEvent_Create(SE_SESSION_ACTIVATION_FAILURE),
                                            session_core_bs__session, // session id
                                            NULL, // user ?
                                            0); // TBD: status
        }else{
          // Activated session closing
            SOPC_ServicesToApp_EnqueueEvent(SOPC_AppEvent_ComEvent_Create(SE_CLOSED_SESSION),
                                            session_core_bs__session, // session id
                                            NULL,
                                            0); // TBD: status
        }
    }
}

void session_core_bs__delete_session_token(
   const constants__t_session_i session_core_bs__p_session){
    // TODO: clear session token
    (void) session_core_bs__p_session;
}

void session_core_bs__is_valid_user(
   const constants__t_user_i session_core_bs__user,
   t_bool * const session_core_bs__ret) {
  assert(session_core_bs__user == 1);
  *session_core_bs__ret = true;
}

void session_core_bs__set_session_user(
   const constants__t_session_i session_core_bs__session,
   const constants__t_user_i session_core_bs__user) {
    if(constants__c_session_indet != session_core_bs__session){
        sessionDataArray[session_core_bs__session].user = session_core_bs__user;
    }
}

void session_core_bs__get_session_user(
   const constants__t_session_i session_core_bs__session,
   constants__t_user_i * const session_core_bs__user) {
    if(constants__c_session_indet != session_core_bs__session){
        *session_core_bs__user = sessionDataArray[session_core_bs__session].user;
    }else{
        *session_core_bs__user = constants__c_user_indet;
    }
}


void session_core_bs__server_create_session_req_do_crypto(
   const constants__t_session_i session_core_bs__p_session,
   const constants__t_msg_i session_core_bs__p_req_msg,
   const constants__t_endpoint_config_idx_i session_core_bs__p_endpoint_config_idx,
   const constants__t_channel_config_idx_i session_core_bs__p_channel_config_idx,
   t_bool * const session_core_bs__valid,
   constants__t_SignatureData_i * const session_core_bs__signature)
{
    SOPC_CryptoProvider *pProvider = NULL;
    SOPC_Endpoint_Config *pECfg = NULL;
    SOPC_SecureChannel_Config *pSCCfg = NULL;
    SessionData *pSession = NULL;
    SOPC_ByteString *pNonce = NULL;
    OpcUa_SignatureData *pSign = NULL;
    uint8_t *pToSign = NULL;
    uint32_t lenToSign = 0;
    OpcUa_CreateSessionRequest *pReq = (OpcUa_CreateSessionRequest *)session_core_bs__p_req_msg;

    *session_core_bs__valid = false;
    *session_core_bs__signature = constants__c_SignatureData_indet;

    if(constants__c_session_indet != session_core_bs__p_session){
        pSession = &sessionDataArray[session_core_bs__p_session];

        /* Retrieve the security policy and mode */
        /* TODO: this function is denoted CLIENT */
        pSCCfg = SOPC_Toolkit_GetSecureChannelConfig((uint32_t) session_core_bs__p_channel_config_idx);
        if(NULL == pSCCfg)
            return;

        /* Retrieve the server certificate */
        pECfg = SOPC_ToolkitServer_GetEndpointConfig((uint32_t) session_core_bs__p_endpoint_config_idx);
        if(NULL == pECfg)
            return;

        /* If security policy is not None, generate the nonce and a signature */
        if(strncmp(pSCCfg->reqSecuPolicyUri, SOPC_SecurityPolicy_None_URI, strlen(SOPC_SecurityPolicy_None_URI)+1) != 0) /* Including the terminating \0 */
        {
            pNonce = &pSession->nonceServer;
            pSign = &pSession->signatureData;

            /* Create the CryptoProvider */
            /* TODO: don't create it each time, maybe add it to the session */
            pProvider = SOPC_CryptoProvider_Create(pSCCfg->reqSecuPolicyUri);

            /* Ask the CryptoProvider for LENGTH_NONCE random bytes */
            SOPC_ByteString_Clear(pNonce);
            pNonce->Length = LENGTH_NONCE;

            if(STATUS_OK != SOPC_CryptoProvider_GenerateRandomBytes(pProvider, pNonce->Length, &pNonce->Data))
                /* TODO: Should we clean half allocated things? */
                return;

            /* Use the server private key to sign the client certificate + client nonce */
            /* TODO: check client certificate is the one provided for the Secure Channel */
            /* a) Prepare the buffer to sign */
            if(pReq->ClientNonce.Length <= 0)
                // client Nonce is not present
                return;
            lenToSign = pReq->ClientCertificate.Length + pReq->ClientNonce.Length;
            pToSign = malloc(sizeof(uint8_t)*lenToSign);
            if(NULL == pToSign)
                return;
            memcpy(pToSign, pReq->ClientCertificate.Data, pReq->ClientCertificate.Length);
            memcpy(pToSign+pReq->ClientCertificate.Length, pReq->ClientNonce.Data, pReq->ClientNonce.Length);
            /* b) Sign and store the signature in pSign */
            SOPC_ByteString_Clear(&pSign->Signature);
            if(STATUS_OK != SOPC_CryptoProvider_AsymmetricGetLength_Signature(pProvider, pECfg->serverKey, (uint32_t *)&pSign->Signature.Length))
                return;
            pSign->Signature.Data = malloc(sizeof(SOPC_Byte)*pSign->Signature.Length); /* TODO: This should be freed with session */
            if(NULL == pSign->Signature.Data)
                return;
            if(STATUS_OK != SOPC_CryptoProvider_AsymmetricSign(pProvider,
                    pToSign, lenToSign,
                    pECfg->serverKey,
                    pSign->Signature.Data, pSign->Signature.Length)){
                free(pToSign);
                return;
            }
            free(pToSign);
            /* c) Prepare the OpcUa_SignatureData */
        SOPC_String_Clear(&pSign->Algorithm);
        if(STATUS_OK != SOPC_String_CopyFromCString(&pSign->Algorithm, SOPC_CryptoProvider_AsymmetricGetUri_SignAlgorithm(pProvider)))
            return;
        *session_core_bs__signature = pSign;

        /* Clean */
        /* TODO: with the many previous returns, you do not always free it */
        SOPC_CryptoProvider_Free(pProvider);
        pProvider = NULL;
        }

        *session_core_bs__valid = true;
    }
}


void session_core_bs__client_activate_session_req_do_crypto(
   const constants__t_session_i session_core_bs__session,
   const constants__t_channel_config_idx_i session_core_bs__channel_config_idx,
   const constants__t_Nonce_i session_core_bs__server_nonce,
   t_bool * const session_core_bs__valid,
   constants__t_SignatureData_i * const session_core_bs__signature){
    SOPC_CryptoProvider *pProvider = NULL;
    SOPC_SecureChannel_Config *pSCCfg = NULL;
    SessionData *pSession = NULL;
    SOPC_ByteString *serverNonce = NULL;
    SOPC_ByteString serverCert;
    SOPC_ByteString_Initialize(&serverCert);
    OpcUa_SignatureData *pSign = NULL;
    uint8_t *pToSign = NULL;
    uint32_t lenToSign = 0;

    *session_core_bs__valid = false;
    *session_core_bs__signature = constants__c_SignatureData_indet;

    if(constants__c_session_indet != session_core_bs__session){
        pSession = &sessionDataArray[session_core_bs__session];
        /* Retrieve the security policy and mode */
        pSCCfg = SOPC_Toolkit_GetSecureChannelConfig((uint32_t) session_core_bs__channel_config_idx);
        if(NULL == pSCCfg)
            return;

        /* If security policy is not None, generate the signature */
        if(strncmp(pSCCfg->reqSecuPolicyUri, SOPC_SecurityPolicy_None_URI, strlen(SOPC_SecurityPolicy_None_URI)+1) != 0) /* Including the terminating \0 */
        {
            /* Retrieve ptr Signature */
            pSign = &pSession->signatureData;

            /* Create the CryptoProvider */
            /* TODO: don't create it each time, maybe add it to the session */
            pProvider = SOPC_CryptoProvider_Create(pSCCfg->reqSecuPolicyUri);

            /* Use the client private key to sign the server certificate + server nonce */
            serverNonce = session_core_bs__server_nonce;
            /* a) Prepare the buffer to sign */
            if(serverNonce->Length <= 0)
                // server Nonce is not present
                return;

            if(pSCCfg->crt_srv != NULL){
                uint32_t tmpLength;
                SOPC_StatusCode status;
                // retrieve expected sender certificate as a ByteString
                status = SOPC_KeyManager_Certificate_CopyDER(pSCCfg->crt_srv,
                        &serverCert.Data,
                        &tmpLength);
                if(tmpLength > 0){
                    serverCert.Length = (int32_t) tmpLength;
                }else{
                    return;
                }
                if(STATUS_OK != status){
                    return;
                }
            }

            lenToSign = serverCert.Length + serverNonce->Length;
            pToSign = malloc(sizeof(uint8_t)*lenToSign);
            if(NULL == pToSign)
                return;
            memcpy(pToSign, serverCert.Data, serverCert.Length);
            memcpy(pToSign+serverCert.Length, serverNonce->Data, serverNonce->Length);
            SOPC_ByteString_Clear(&serverCert);
            /* b) Sign and store the signature in pSign */
            SOPC_ByteString_Clear(&pSign->Signature);
            if(STATUS_OK != SOPC_CryptoProvider_AsymmetricGetLength_Signature(pProvider, pSCCfg->key_priv_cli, (uint32_t *)&pSign->Signature.Length))
                return;
            pSign->Signature.Data = malloc(sizeof(SOPC_Byte)*pSign->Signature.Length); /* TODO: This should not be stored in unique session ? */
            if(NULL == pSign->Signature.Data)
                return;
            if(STATUS_OK != SOPC_CryptoProvider_AsymmetricSign(pProvider,
                    pToSign, lenToSign,
                    pSCCfg->key_priv_cli,
                    pSign->Signature.Data, pSign->Signature.Length)){
                free(pToSign);
                return;
            }
            free(pToSign);
            /* c) Prepare the OpcUa_SignatureData */
        SOPC_String_Clear(&pSign->Algorithm);
        if(STATUS_OK != SOPC_String_CopyFromCString(&pSign->Algorithm, SOPC_CryptoProvider_AsymmetricGetUri_SignAlgorithm(pProvider)))
            return;
        *session_core_bs__signature = pSign;

        /* Clean */
        /* TODO: with the many previous returns, you do not always free it */
        SOPC_CryptoProvider_Free(pProvider);
        pProvider = NULL;
        }

        *session_core_bs__valid = true;
    }
}


void session_core_bs__get_NonceServer(
   const constants__t_session_i session_core_bs__p_session,
   constants__t_Nonce_i * const session_core_bs__nonce)
{
    if(constants__c_session_indet != session_core_bs__p_session){
        *session_core_bs__nonce = (constants__t_Nonce_i *) &(sessionDataArray[session_core_bs__p_session].nonceServer);
    }else{
        *session_core_bs__nonce = constants__c_Nonce_indet;
    }
}


void session_core_bs__client_create_session_req_do_crypto(
   const constants__t_session_i session_core_bs__p_session,
   const constants__t_channel_i session_core_bs__p_channel,
   const constants__t_channel_config_idx_i session_core_bs__p_channel_config_idx,
   t_bool * const session_core_bs__valid,
   t_bool * const session_core_bs__nonce_needed)
{
    (void) session_core_bs__p_channel;
    /* Produce the Nonce when SC:Sec_pol is not "None" */
    SOPC_CryptoProvider *pProvider = NULL;
    SOPC_SecureChannel_Config *pSCCfg = NULL;
    SessionData *pSession = NULL;
    SOPC_ByteString *pNonce = NULL;

    /* Default answer */
    *session_core_bs__valid = false;
    *session_core_bs__nonce_needed = false;

    if(constants__c_session_indet != session_core_bs__p_session){
        pSession = &sessionDataArray[session_core_bs__p_session];

        /* Retrieve the security policy */
        pSCCfg = SOPC_Toolkit_GetSecureChannelConfig((uint32_t) session_core_bs__p_channel_config_idx);
        if(NULL == pSCCfg)
            return;

        /* If security policy is not None, generate the nonce */
        if(strncmp(pSCCfg->reqSecuPolicyUri, SOPC_SecurityPolicy_None_URI, strlen(SOPC_SecurityPolicy_None_URI)+1) != 0) /* Including the terminating \0 */
        {
            *session_core_bs__nonce_needed = true;
            /* Retrieve ptrs to Nonce and Signature */
            pNonce = &pSession->nonceClient;

            /* Create the CryptoProvider */
            /* TODO: don't create it each time, maybe add it to the session */
            pProvider = SOPC_CryptoProvider_Create(pSCCfg->reqSecuPolicyUri);

            /* Ask the CryptoProvider for LENGTH_NONCE random bytes */
            SOPC_ByteString_Clear(pNonce);
            pNonce->Length = LENGTH_NONCE;

            if(STATUS_OK != SOPC_CryptoProvider_GenerateRandomBytes(pProvider, pNonce->Length, &pNonce->Data))
                /* TODO: Should we clean half allocated things? */
                return;

            /* Clean */
            /* TODO: with the many previous returns, you do not always free it */
            SOPC_CryptoProvider_Free(pProvider);
            pProvider = NULL;
        }

        /* Success */
        *session_core_bs__valid = true;
    }
}


void session_core_bs__get_NonceClient(
   const constants__t_session_i session_core_bs__p_session,
   constants__t_Nonce_i * const session_core_bs__nonce)
{
    if(constants__c_session_indet != session_core_bs__p_session){
        *session_core_bs__nonce = (constants__t_Nonce_i *) &(sessionDataArray[session_core_bs__p_session].nonceClient);
    }else{
        *session_core_bs__nonce = constants__c_Nonce_indet;
    }
}


void session_core_bs__drop_NonceClient(
   const constants__t_session_i session_core_bs__p_session)
{
    if(constants__c_session_indet != session_core_bs__p_session){
        SOPC_ByteString_Clear(&(sessionDataArray[session_core_bs__p_session].nonceClient));
    }
}


void session_core_bs__client_create_session_check_crypto(
   const constants__t_session_i session_core_bs__p_session,
   const constants__t_channel_config_idx_i session_core_bs__p_channel_config_idx,
   const constants__t_msg_i session_core_bs__p_resp_msg,
   t_bool * const session_core_bs__valid)
{
    SOPC_CryptoProvider *pProvider = NULL;
    const SOPC_SecureChannel_Config *pSCCfg = NULL;
    SessionData *pSession = NULL;
    const SOPC_ByteString *pNonce = NULL;
    const OpcUa_SignatureData *pSignCandid = NULL;
    uint8_t *pDerCli = NULL;
    uint32_t lenDerCli = 0;
    uint8_t *pToVerify = NULL;
    uint32_t lenToVerify = 0;
    const OpcUa_CreateSessionResponse *pResp = (OpcUa_CreateSessionResponse *)session_core_bs__p_resp_msg;
    const SOPC_Certificate *pCrtCli = NULL, *pCrtSrv = NULL;
    const char *szSignUri = NULL;
    SOPC_AsymmetricKey *pKeyCrtSrv = NULL;

    /* Default answer */
    *session_core_bs__valid = false;

    if(constants__c_session_indet != session_core_bs__p_session){
        pSession = &sessionDataArray[session_core_bs__p_session];

        /* Retrieve the security policy and mode */
        pSCCfg = SOPC_Toolkit_GetSecureChannelConfig((uint32_t) session_core_bs__p_channel_config_idx);
        if(NULL == pSCCfg)
            return;

        /* Retrieve the certificates */
        pCrtCli = pSCCfg->crt_cli;
        pCrtSrv = pSCCfg->crt_srv;
        if(NULL == pCrtSrv || NULL == pCrtCli)
            return;

        /* TODO: Verify that the server certificate in the Response is the same as the one stored with the SecureChannel */

        /* Retrieve ptrs to ClientNonce and ServerSignature */
        pNonce = &pSession->nonceClient;
        pSignCandid = &pResp->ServerSignature;

        if(pResp->ServerNonce.Length <= 0)
            return;
        if(STATUS_OK != SOPC_ByteString_Copy(&pSession->nonceServer, &pResp->ServerNonce))
            return;

        /* Build CryptoProvider */
        /* TODO: don't create it each time, maybe add it to the session */
        pProvider = SOPC_CryptoProvider_Create(pSCCfg->reqSecuPolicyUri);

        /* Verify signature algorithm URI */
        szSignUri = SOPC_CryptoProvider_AsymmetricGetUri_SignAlgorithm(pProvider);

        if(strncmp((char *)pSignCandid->Algorithm.Data, szSignUri, strlen(szSignUri)+1) == 0)
        {
            /* Build signed data (client certificate + client nonce) */
            /* a) Get Der of client certificate */
            if(STATUS_OK == SOPC_KeyManager_Certificate_CopyDER(pCrtCli, &pDerCli, &lenDerCli))
            {
                /* b) Concat Nonce */
                lenToVerify = lenDerCli + LENGTH_NONCE;
                pToVerify = (uint8_t *)malloc(sizeof(uint8_t)*lenToVerify);
                if(NULL != pToVerify)
                {
                    /* TODO: The KeyManager API should be changed to avoid these useless copies */
                    memcpy(pToVerify, pDerCli, lenDerCli);
                    memcpy(pToVerify+lenDerCli, pNonce->Data, pNonce->Length);

                    /* Verify given signature */
                    /* a) Retrieve public key from certificate */
                    if(STATUS_OK == SOPC_KeyManager_AsymmetricKey_CreateFromCertificate(pCrtSrv, &pKeyCrtSrv))
                    {
                        /* b) Call AsymVerify */
                        if(STATUS_OK == SOPC_CryptoProvider_AsymmetricVerify(pProvider, pToVerify, lenToVerify,
                                pKeyCrtSrv, pSignCandid->Signature.Data, pSignCandid->Signature.Length))
                            *session_core_bs__valid = true;
                    }
                }
            }
        }

        /* Clear */
        SOPC_KeyManager_AsymmetricKey_Free(pKeyCrtSrv);
        free(pToVerify);
        free(pDerCli);
        SOPC_CryptoProvider_Free(pProvider);
    }
}

void session_core_bs__server_activate_session_check_crypto(
   const constants__t_session_i session_core_bs__session,
   const constants__t_channel_i session_core_bs__channel,
   const constants__t_channel_config_idx_i session_core_bs__channel_config_idx,
   const constants__t_msg_i session_core_bs__activate_req_msg,
   t_bool * const session_core_bs__valid)
{
    (void) session_core_bs__channel;
    SOPC_CryptoProvider *pProvider = NULL;
    const SOPC_SecureChannel_Config *pSCCfg = NULL;
    SessionData *pSession = NULL;
    SOPC_ByteString *pNonce = NULL;
    const OpcUa_SignatureData *pSignCandid = NULL;
    uint8_t *pDerSrv = NULL;
    uint32_t lenDerSrv = 0;
    uint8_t *pToVerify = NULL;
    uint32_t lenToVerify = 0;
    const OpcUa_ActivateSessionRequest *pReq = (OpcUa_ActivateSessionRequest *)session_core_bs__activate_req_msg;
    const SOPC_Certificate *pCrtCli = NULL, *pCrtSrv = NULL;
    const char *szSignUri = NULL;
    SOPC_AsymmetricKey *pKeyCrtCli = NULL;

    /* Default answer */
    *session_core_bs__valid = false;

    if(constants__c_session_indet != session_core_bs__session){
        pSession = &sessionDataArray[session_core_bs__session];

        /* Retrieve the security policy and mode */
        pSCCfg = SOPC_Toolkit_GetSecureChannelConfig((uint32_t) session_core_bs__channel_config_idx);
        if(NULL == pSCCfg)
            return;

        /* Retrieve the certificates */
        pCrtCli = pSCCfg->crt_cli;
        pCrtSrv = pSCCfg->crt_srv;
        if(NULL == pCrtSrv || NULL == pCrtCli)
            return;

        /* Retrieve ptrs to ServerNonce and ClientSignature */
        pNonce = &pSession->nonceServer;
        pSignCandid = &pReq->ClientSignature;

        /* Build CryptoProvider */
        /* TODO: don't create it each time, maybe add it to the session */
        pProvider = SOPC_CryptoProvider_Create(pSCCfg->reqSecuPolicyUri);

        /* Verify signature algorithm URI */
        szSignUri = SOPC_CryptoProvider_AsymmetricGetUri_SignAlgorithm(pProvider);

        if(strncmp((char *)pSignCandid->Algorithm.Data, szSignUri, strlen(szSignUri)+1) == 0)
        {
            /* Build signed data (server certificate + server nonce) */
            /* a) Get Der of client certificate */
            if(STATUS_OK == SOPC_KeyManager_Certificate_CopyDER(pCrtSrv, &pDerSrv, &lenDerSrv))
            {
                /* b) Concat Nonce */
                lenToVerify = lenDerSrv + LENGTH_NONCE;
                pToVerify = (uint8_t *)malloc(sizeof(uint8_t)*lenToVerify);
                if(NULL != pToVerify)
                {
                    /* TODO: The KeyManager API should be changed to avoid these useless copies */
                    memcpy(pToVerify, pDerSrv, lenDerSrv);
                    memcpy(pToVerify+lenDerSrv, pNonce->Data, pNonce->Length);

                    /* Verify given signature */
                    /* a) Retrieve public key from certificate */
                    if(STATUS_OK == SOPC_KeyManager_AsymmetricKey_CreateFromCertificate(pCrtCli, &pKeyCrtCli))
                    {
                        /* b) Call AsymVerify */
                        if(STATUS_OK == SOPC_CryptoProvider_AsymmetricVerify(pProvider, pToVerify, lenToVerify,
                                pKeyCrtCli, pSignCandid->Signature.Data, pSignCandid->Signature.Length))
                            *session_core_bs__valid = true;
                    }
                }
            }
        }

        if(*session_core_bs__valid != false){
            // renew the server Nonce
            free(pNonce->Data);
            pNonce->Data = NULL;
            assert(STATUS_OK == SOPC_CryptoProvider_GenerateRandomBytes(pProvider, pNonce->Length, &pNonce->Data));
        }

        /* Clear */
        SOPC_KeyManager_AsymmetricKey_Free(pKeyCrtCli);
        free(pToVerify);
        free(pDerSrv);
        SOPC_CryptoProvider_Free(pProvider);

    }
}

void session_core_bs__client_activate_session_resp_check(
   const constants__t_session_i session_core_bs__p_session,
   const constants__t_channel_config_idx_i session_core_bs__p_channel_config_idx,
   const constants__t_msg_i session_core_bs__p_resp_msg,
   t_bool * const session_core_bs__valid){
    (void) session_core_bs__p_session;
    (void) session_core_bs__p_channel_config_idx;
    (void) session_core_bs__p_resp_msg;
    /* TODO: check parameter + add other operation to retrieve new server nonce ?*/
    *session_core_bs__valid = true;
}

void session_core_bs__client_close_session_req_msg(
   const constants__t_msg_i session_core_bs__req_msg){
    (void) session_core_bs__req_msg;
}

void session_core_bs__client_close_session_resp_msg(
   const constants__t_msg_i session_core_bs__resp_msg){
    (void) session_core_bs__resp_msg;
}

void session_core_bs__server_close_session_check_req(
   const constants__t_msg_i session_core_bs__req_msg,
   const constants__t_msg_i session_core_bs__resp_msg){
    (void) session_core_bs__req_msg;
    (void) session_core_bs__resp_msg;
}

void session_core_bs__session_do_nothing(
   const constants__t_session_i session_core_bs__session)
{
    (void) session_core_bs__session;
}