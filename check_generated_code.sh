#!/bin/bash

# Licensed to Systerel under one or more contributor license
# agreements. See the NOTICE file distributed with this work
# for additional information regarding copyright ownership.
# Systerel licenses this file to you under the Apache
# License, Version 2.0 (the "License"); you may not use this
# file except in compliance with the License. You may obtain
# a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.


# script to test freshness of C generated code from B.
CURDIR=`pwd`
LOGPATH=$CURDIR/pre-build.log
CSRCDIR=csrc/services/bgenc
LOGPATH=$CURDIR/pre-build.log
ifs_save=$IFS
IFS=$'\n'
GENERATED_FILES=`find $CSRCDIR -maxdepth 1 -name "*.[hc]"`

EXITCODE=0

# look for changes except date
echo  "Checking for uncommited changes." | tee -a $LOGPATH
for f in ${GENERATED_FILES[*]}
do
    git diff -G'^[^ Date]' --exit-code $f &> /dev/null

    if [[ $? != 0 ]]; then
        echo "file $f is not up to date in configuration management." | tee -a $LOGPATH
        EXITCODE=1
    fi

done

# list untracked files
echo  "Looking for untracked files." | tee -a $LOGPATH
UNTRACKED_FILES=`git ls-files --others --exclude-standard $CSRCDIR`
for f in ${UNTRACKED_FILES[*]}
do
    echo "file $f is untracked in configuration management." | tee -a $LOGPATH
    EXITCODE=1
done

# list untracked files
echo  "Looking for locally deleted files." | tee -a $LOGPATH
DELETED_FILES=`git ls-files --deleted --exclude-standard $CSRCDIR`
for f in ${DELETED_FILES[*]}
do
    echo "file $f deletion is not commited in configuration management." | tee -a $LOGPATH
    EXITCODE=1
done

IFS=$ifs_save

exit $EXITCODE


