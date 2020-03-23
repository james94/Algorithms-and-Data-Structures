#!/bin/bash

# Run Python project
# Use CMake to automate building Makefile for project

# Create build/ dir if does not exist
if [ ! -d "build/" ]
then
    mkdir build
else
    echo "Directory build/ exists"
fi

# Place all of build files (Makefile, etc) in build dir
# Execute Python script
cd build && cmake ..