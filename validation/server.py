#!/usr/bin/env python3
# -*- coding: utf-8 -*-

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

"""
Simple server handling miscellaneous client tests
"""

import argparse
import os.path
import time

from opcua import ua, Server
from common import sUri, variantInfoList
#from tap_logger import TapLogger
from opcua.crypto import security_policies

if __name__=='__main__':
    parser = argparse.ArgumentParser(description='FreeOpcUa test server')
    parser.add_argument('msTimeout', nargs='?', default=10000., type=float,
                        help='Server timeout (ms)')
    args = parser.parse_args()

    # Open server
    print('Configuring FreeOpcUa test server')
    server = Server()
    server.set_endpoint(sUri)

    cert_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'tests', 'data', 'cert')
    server.load_certificate(os.path.join(cert_dir, 'server_2k_cert.der'))
    server.load_private_key(os.path.join(cert_dir, 'server_2k_key.pem'))

    # Nodes are created under the Objects node
    objects = server.get_objects_node()
    # Use the same nodes as in the Read test
    for i,(sTypName,typ,val,_) in enumerate(variantInfoList):
        nid = 1000 + i + 1
        node = objects.add_variable(ua.NodeId(nid, 0), sTypName, ua.Variant(val, typ))
        node.set_writable()

    # Starts the server
    server.start()
    try:
        print('Server started. Stops in {:.2f} s'.format(args.msTimeout/1000.))
        # The freeopcua toolkit is heavily an asyncio thing, which is run in another thread
        #  but here we have nothing else to do...
        time.sleep(args.msTimeout/1000.)
    finally:
        server.stop()
