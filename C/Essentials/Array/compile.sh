#!/bin/bash

# Compile C project
# Use CMake to automate building Makefile for project
# Compile project using Makefile

# Place all of build files (Makefile, etc) in build dir
cd build && cmake ..

# Compile C project using Makefile that was built by CMake
make
