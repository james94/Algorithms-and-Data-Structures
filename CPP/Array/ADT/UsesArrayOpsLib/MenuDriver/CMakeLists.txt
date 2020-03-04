# Builds a program that links to a library (shared in our case)
# MenuDriver C++ program utilizes the functionality of shared
# library libArrayOperations.so

cmake_minimum_required(VERSION 3.16.4)
# Set project name to MenuDriver C/C++ enabled default
project(MenuDriver)

# For the shared library
set(PROJECT_LINK_LIBS libArrayOperations.so)
link_directories(../../ArrayOpsLibShared/build)

# Bring the headers, such as ArrayOperations
include_directories(../../ArrayOpsLibShared/include)

# Manually add the sources using the set command
set(SOURCES src/main.cpp)

# Use SOURCES variable to build main executable program
add_executable(main ${SOURCES})

target_link_libraries(main ${PROJECT_LINK_LIBS})