# Project name is not mandatory, but you should use it
project(sdts)

# States that CMake required version must be greater than 2.6
cmake_minimum_required(VERSION 2.6)

# verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable
# which stores the directories of additional CMake modules
# (ie. MacroOutOfSourceBuild.cmake):
set(CMAKE_MODULE_PATH ${sdts_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
# The macro below forces the build directory to be different from source directory:
#include(MacroOutOfSourceBuild)

#macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build.")

# need this because of way files in subdirs call headers, e.g.,:
#include <sdts++/io/sio_8211Converter.h>
include_directories(.)

add_subdirectory(sysutils)
add_subdirectory(sdts++)
add_subdirectory(contrib)

#add_subdirectory(doc)
#add_subdirectory(tests)

# uninstall target (per CMake FAQ)
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
