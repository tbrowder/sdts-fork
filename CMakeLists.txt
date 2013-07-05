# Project name is not mandatory, but you should use it
project(sdts)

# States that CMake required version must be greater than 2.6
cmake_minimum_required(VERSION 2.6)

# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable
# which stores the directories of additional CMake modules
# (ie. MacroOutOfSourceBuild.cmake):

set(CMAKE_MODULE_PATH ${sdts_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

# The macro below forces the build directory to be different from source directory:
#include(MacroOutOfSourceBuild)

#macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build.")

add_subdirectory(sysutils)
add_subdirectory(sdts++)

#add_subdirectory(doc)
#add_subdirectory(contrib)
#add_subdirectory(tests)

#aux_source_directory(./sysutils SYSUTILS)
#add_library(sysutils SHARED ${SYSUTILS})
