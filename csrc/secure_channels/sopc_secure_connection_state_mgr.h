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

#ifndef SOPC_SECURE_CONNECTION_STATE_MGR_H_
#define SOPC_SECURE_CONNECTION_STATE_MGR_H_

#include <stdint.h>

#include "sopc_secure_channels_api.h"

void SOPC_SecureConnectionStateMgr_Dispatcher(SOPC_SecureChannels_InputEvent event,
                                              uint32_t eltId,
                                              void* params,
                                              uintptr_t auxParam);

#endif /* SOPC_SECURE_CONNECTION_STATE_MGR_H_ */
