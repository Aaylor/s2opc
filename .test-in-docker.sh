#!/bin/bash

# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.


#  Run the script given parameters in the docker
#
set -e

DOCKER_IMAGE=sha256:6c31e237b78a69a39db844d6943333d9d47bcbf9e67289463bfa485ed03a5831

if [[ -z $SOPC_DOCKER_NEEDS_SUDO ]]; then
    /etc/scripts/run-in-docker $DOCKER_IMAGE "$@"
else
    sudo /etc/scripts/run-in-docker $DOCKER_IMAGE "$@"
fi
