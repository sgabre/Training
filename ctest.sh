#!/bin/bash

# Create build directory and run cmake
mkdir -p build
cd build || exit 1
cmake .. 
cmake --build .
#ctest --verbose
ctest --output-on-failure