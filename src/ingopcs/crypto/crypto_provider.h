/*
 * Defines the cryptographic providers: structure r/w data alongside a read-only cryptoprofile.
 *
 *  Created on: Sep 28, 2016
 *      Author: PAB
 */


#ifndef INGOPCS_CRYPTO_PROVIDER_H_
#define INGOPCS_CRYPTO_PROVIDER_H_


#include "ua_base_types.h"
#include "secret_buffer.h"
#include "crypto_types.h"
#include "key_sets.h"
#include "key_manager.h"


// Creation
CryptoProvider *CryptoProvider_Create(const char *uri);
void CryptoProvider_Delete(CryptoProvider *pCryptoProvider);
StatusCode CryptoProvider_Init(CryptoProvider *pCryptoProvider);
StatusCode CryptoProvider_Deinit(CryptoProvider *pCryptoProvider);

// Lengths
StatusCode CryptoProvider_SymmetricGetLength_Key(const CryptoProvider *pProvider,
                                                     uint32_t *length);
StatusCode CryptoProvider_SymmetricGetLength_Encryption(const CryptoProvider *pProvider,
                                                        uint32_t lengthIn,
                                                        uint32_t *pLengthOut);
StatusCode CryptoProvider_SymmetricGetLength_Decryption(const CryptoProvider *pProvider,
                                                        uint32_t lengthIn,
                                                        uint32_t *pLengthOut);
StatusCode CryptoProvider_SymmetricGetLength_Signature(const CryptoProvider *pProvider,
                                                       uint32_t *pLength);
StatusCode CryptoProvider_SymmetricGetLength_Blocks(const CryptoProvider *pProvider,
                                                    uint32_t *cipherTextBlockSize,
                                                    uint32_t *plainTextBlockSize);
StatusCode CryptoProvider_DeriveGetLengths(const CryptoProvider *pProvider,
                                           uint32_t *pSymmCryptoKeyLength,
                                           uint32_t *pSymmSignKeyLength,
                                           uint32_t *pSymmInitVectorLength);
StatusCode CryptoProvider_AsymmetricGetLength_KeyBits(const CryptoProvider *pProvider,
                                                      const AsymmetricKey *pKey,
                                                      uint32_t *lenKeyBits);
StatusCode CryptoProvider_AsymmetricGetLength_KeyBytes(const CryptoProvider *pProvider,
                                                       const AsymmetricKey *pKey,
                                                       uint32_t *lenKeyBytes);
StatusCode CryptoProvider_AsymmetricGetLength_OAEPHashLength(const CryptoProvider *pProvider,
                                                             uint32_t *length);
StatusCode CryptoProvider_AsymmetricGetLength_PSSHashLength(const CryptoProvider *pProvider,
                                                            uint32_t *length);
StatusCode CryptoProvider_AsymmetricGetLength_Msgs(const CryptoProvider *pProvider,
                                                   const AsymmetricKey *pKey,
                                                   uint32_t *cipherTextBlockSize,
                                                   uint32_t *plainTextBlockSize);
StatusCode CryptoProvider_AsymmetricGetLength_MsgPlainText(const CryptoProvider *pProvider,
                                                           const AsymmetricKey *pKey,
                                                           uint32_t *lenMsg);
StatusCode CryptoProvider_AsymmetricGetLength_MsgCipherText(const CryptoProvider *pProvider,
                                                            const AsymmetricKey *pKey,
                                                            uint32_t *lenMsg);
StatusCode CryptoProvider_AsymmetricGetLength_Encryption(const CryptoProvider *pProvider,
                                                         const AsymmetricKey *pKey,
                                                         uint32_t lengthIn,
                                                         uint32_t *pLengthOut);
StatusCode CryptoProvider_AsymmetricGetLength_Decryption(const CryptoProvider *pProvider,
                                                         const AsymmetricKey *pKey,
                                                         uint32_t lengthIn,
                                                         uint32_t *pLengthOut);
StatusCode CryptoProvider_AsymmetricGetLength_Signature(const CryptoProvider *pProvider,
                                                        const AsymmetricKey *pKey,
                                                        uint32_t *pLength);

// Symmetric functions
StatusCode CryptoProvider_SymmetricEncrypt(const CryptoProvider *pProvider,
                                           const uint8_t *pInput,
                                           uint32_t lenPlainText,
                                           const SecretBuffer *pKey,
                                           const SecretBuffer *pIV,
                                           uint8_t *pOutput,
                                           uint32_t lenOutput);
StatusCode CryptoProvider_SymmetricDecrypt(const CryptoProvider *pProvider,
                                           const uint8_t *pInput,
                                           uint32_t lenCipherText,
                                           const SecretBuffer *pKey,
                                           const SecretBuffer *pIV,
                                           uint8_t *pOutput,
                                           uint32_t lenOutput);
StatusCode CryptoProvider_SymmetricSign(const CryptoProvider *pProvider,
                                        const uint8_t *pInput,
                                        uint32_t lenInput,
                                        const SecretBuffer *pKey,
                                        uint8_t *pOutput,
                                        uint32_t lenOutput);
StatusCode CryptoProvider_SymmetricVerify(const CryptoProvider *pProvider,
                                          const uint8_t *pInput,
                                          uint32_t lenInput,
                                          const SecretBuffer *pKey,
                                          const uint8_t *pSignature,
                                          uint32_t lenOutput);
StatusCode CryptoProvider_SymmetricGenerateKey(const CryptoProvider *pProvider,
                                               SecretBuffer **ppKeyGenerated);


// Key derivation
StatusCode CryptoProvider_DerivePseudoRandomData(const CryptoProvider *pProvider,
                                                 const ExposedBuffer *pSecret,
                                                 uint32_t lenSecret,
                                                 const ExposedBuffer *pSeed,
                                                 uint32_t lenSeed,
                                                 ExposedBuffer *pOutput,
                                                 uint32_t lenOutput);
StatusCode CryptoProvider_DeriveKeySets(const CryptoProvider *pProvider,
                                        const ExposedBuffer *pClientNonce,
                                        uint32_t lenClientNonce,
                                        const ExposedBuffer *pServerNonce,
                                        uint32_t lenServerNonce,
                                        SC_SecurityKeySet *pClientKeySet,
                                        SC_SecurityKeySet *pServerKeySet);
StatusCode CryptoProvider_DeriveKeySetsClient(const CryptoProvider *pProvider, // DeriveKeySets
                                              const SecretBuffer *pClientNonce,
                                              const ExposedBuffer *pServerNonce,
                                              uint32_t lenServerNonce,
                                              SC_SecurityKeySet *pClientKeySet,
                                              SC_SecurityKeySet *pServerKeySet);
StatusCode CryptoProvider_DeriveKeySetsServer(const CryptoProvider *pProvider,
                                              const ExposedBuffer *pClientNonce,
                                              uint32_t lenClientNonce,
                                              const SecretBuffer *pServerNonce,
                                              SC_SecurityKeySet *pClientKeySet,
                                              SC_SecurityKeySet *pServerKeySet);


// Asymmetric functions
StatusCode CryptoProvider_AsymmetricEncrypt(const CryptoProvider *pProvider,
                                            const uint8_t *pInput,
                                            uint32_t lenInput,
                                            const AsymmetricKey *pKey,
                                            uint8_t *pOutput,
                                            uint32_t lenOutput);
StatusCode CryptoProvider_AsymmetricDecrypt(const CryptoProvider *pProvider,
                                            const uint8_t *pInput,
                                            uint32_t lenInput,
                                            const AsymmetricKey *pKey,
                                            uint8_t *pOutput,
                                            uint32_t lenOutput,
                                            uint32_t *lenWritten);
StatusCode CryptoProvider_AsymmetricSign(const CryptoProvider *pProvider,
                                         const uint8_t *pInput,
                                         uint32_t lenInput,
                                         const AsymmetricKey *pKeyPrivateLocal,
                                         uint8_t *pSignature,
                                         uint32_t lenSignature);
StatusCode CryptoProvider_AsymmetricVerify(const CryptoProvider *pProvider,
                                           const uint8_t *pInput,
                                           uint32_t lenInput,
                                           const AsymmetricKey *pKeyRemotePublic,
                                           const uint8_t *pSignature,
                                           uint32_t lenSignature);


#endif  // INGOPCS_CRYPTO_PROVIDER_H_
