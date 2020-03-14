# Builds a program that links to a library (shared in our case)
# ValidateString C program utilizes the functionality of shared
# library libStringOperations.so

cmake_minimum_required(VERSION 3.16.4)
# Set project name to ValidateString
project(ValidateString C)

# For the shared library
set(PROJECT_LINK_LIBS libStringOperations.so)
link_directories(../../StringOpsLibShared/build)

# Bring the headers, such as StringOperations
include_directories(../../StringOpsLibShared/include)

# Manually add the sources using the set command
set(SOURCES src/main.c)

# Use SOURCES variable to build main executable program
add_executable(main ${SOURCES})

target_link_libraries(main ${PROJECT_LINK_LIBS})