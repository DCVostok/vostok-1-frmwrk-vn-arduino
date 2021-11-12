#!/bin/sh
mkdir build-Debug && cd build-Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cd ..
