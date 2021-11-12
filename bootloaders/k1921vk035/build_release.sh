#!/bin/sh
mkdir build-Release && cd build-Release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cd ..
