cmake_minimum_required(VERSION 3.16.4)
# Set project name to ArrayOpsLibShared
project(ArrayOpsLibShared C)
set(CMAKE_BUILD_TYPE Release)

# Bring the headers, such as ArrayOperations
include_directories(include)

# Add the source files to the project
file(GLOB SOURCES "src/*.c")

# Generate the shared library from the sources
add_library(ArrayOperations SHARED ${SOURCES})

# Set the location for library installation
# /usr/lib in this case. Not really necessary
# for this project. Use 'sudo make install' to apply
install(TARGETS ArrayOperations DESTINATION /usr/lib)