#!/bin/bash

# Build C shared library using CMake
# Automate building Makefile for library with CMake.
# Compile shared library using Makefile

# Create build/ dir if does not exist
if [ ! -d "build/" ]
then
    mkdir build
else
    echo "Directory build/ exists"
fi

# Place all of build files (Makefile, etc) in build dir
cd build && cmake ..

# Compile C library using Makefile that was built by CMake
make
