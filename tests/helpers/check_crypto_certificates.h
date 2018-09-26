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

#ifndef SOPC_CHECK_CRYPTO_CERTIFICATES_H_
#define SOPC_CHECK_CRYPTO_CERTIFICATES_H_

#include <stddef.h>

#include "sopc_key_manager.h"

// server_2k_cert.der
const char* SRV_CRT;
const char* SRV_CRT_THUMB;

// cacert.der
const char* CA_CRT;
const size_t CA_CRT_LEN;

SOPC_Certificate* SOPC_UnhexlifyCertificate(const char* hex_data);

#endif /* SOPC_CHECK_CRYPTO_CERTIFICATES_H_ */