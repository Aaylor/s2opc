#!/bin/bash

# Copyright (C) 2018 Systerel and others.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


# Script to generate data necessary to build the INGOPCS project:
#
# Steps (if necessary):
# - generate sources files from B model
# - generate sources files for examples address space for tests
#
# This generation script uses the free AtelierB

BMODEL_DIR=bsrc
ADDSPACE_DIR=address_space_generation
PREBUILD=pre-build
PROJET=ingopcs_genc

LOGPATH=$(pwd)/pre-build.log

# Redirect all output and errors to log file
echo "Pre-build log" > $LOGPATH

EXITCODE=0

echo "Prepare B project and tools configuration" | tee -a $LOGPATH
# Set a pre-build local environment for "m" script

export ATELIERB_VERSION="4.2.1"
export STARTBB=startBB
export BASE=$(pwd)/$PREBUILD
# Create pre-build directory to check B modle and generate C code
mkdir -p $BASE >> $LOGPATH
# Configure "m" script environment
export liste_projet=$BASE/liste_projets.txt
echo $PROJET . > $liste_projet
export TOOLING_DIR=/home/tooling
export TRAD_JAVA="java -jar $TOOLING_DIR/bin/trad/b2c.jar"
export ROOT="toolkit_header"
# Make symbolic link to all files in bsrc/
cd $BASE && find ../$BMODEL_DIR -maxdepth 1 -type f -exec ln -f -s {} . \; && cd - >> $LOGPATH
PATH=$TOOLING_DIR/bin/m:$TOOLING_DIR/bin/trad:$PATH

echo "Generate C sources files from B model" | tee -a $LOGPATH
make VERBOSE=1 -C $BASE >> $LOGPATH

if [[ $? != 0 ]]; then
    echo "ERROR: generating C source files from B model" | tee -a $LOGPATH
    EXITCODE=1
fi
# Remove pre-build directory in any case
\rm -rf ./$PREBUILD


echo "Generate address space C files for tests" | tee -a $LOGPATH
make -C ./address_space_generation >> $LOGPATH
if [[ $? != 0 ]]; then
    echo "ERROR: generating address spaces for tests" | tee -a $LOGPATH
    EXITCODE=1
fi

if [[ $EXITCODE -eq 0 ]]; then
    echo "Completed with SUCCESS" | tee -a $LOGPATH
else
    echo "Completed with ERRORS" | tee -a $LOGPATH
fi

exit $EXITCODE