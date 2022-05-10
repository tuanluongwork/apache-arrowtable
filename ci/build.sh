#!/bin/bash

BUILD_ROOT=${WORKSPACE}/build/
ARTIFACT_ROOT=${WORKSPACE}/artifact/
SOURCE_ROOT=${WORKSPACE}

# Clean up and create the necessary folders
rm -rf ${BUILD_ROOT} ${ARTIFACT_ROOT}
mkdir -p ${BUILD_ROOT} ${ARTIFACT_ROOT}

# Build
cd ${BUILD_ROOT}
cmake ${SOURCE_ROOT} -DCMAKE_BUILD_TYPE=Release ..
make 