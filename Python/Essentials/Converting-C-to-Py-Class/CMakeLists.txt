cmake_minimum_required(VERSION 3.16.4)
# Set project name to CToPythonClass
# Skip compiler check by enabling no languages
project(CToPythonClass LANGUAGES NONE)

# Tell CMake to run python from the directory where CMakeLists exists
execute_process(
    COMMAND python src/main.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)