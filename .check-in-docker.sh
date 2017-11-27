#!/bin/bash
#
#  Run the script given parameters in the docker
#
set -e

DOCKER_IMAGE=f54c1108a032

if [[ -z $SOPC_DOCKER_NEEDS_SUDO ]]; then
    /etc/scripts/run-in-docker $DOCKER_IMAGE "$@"
else
    sudo /etc/scripts/run-in-docker $DOCKER_IMAGE "$@"
fi