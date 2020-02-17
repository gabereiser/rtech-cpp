#!/bin/sh
BUILD_TYPE=Debug # Release | Debug | RelWithDebInfo | MinSizeRel

git submodule update --init --recursive
rm -rf out
mkdir out
cd out
cmake -D CMAKE_INSTALL_PREFIX="./install" \
      -D CMAKE_BUILD_TYPE=$BUILD_TYPE \
       ..
make -j 
make install
