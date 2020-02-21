#!/bin/bash

# Compile C project
# Use CMake to automate building Makefile for project
# Compile project using Makefile

# Automate building Makefile and other build files with CMake
cmake .

# Compile C project using Makefile that was built by CMake
make
