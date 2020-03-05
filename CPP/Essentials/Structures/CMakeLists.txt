cmake_minimum_required(VERSION 3.16.4)
# Set project name to Structures C/C++ enabled default
project(Structures)

# Manually add the sources using the set command
set(SOURCES src/main.cpp)

# Use SOURCES variable to build main executable program
add_executable(main ${SOURCES})