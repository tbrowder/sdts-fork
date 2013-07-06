# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(sysutils_SOURCES fileutils.cpp stringutils.cpp)
add_library(sysutils SHARED ${sysutils_SOURCES})

set(t_dirname_SOURCES t_dirname.cpp fileutils.cpp)
add_executable(t_dirname ${t_dirname_SOURCES})

set(t_basename_SOURCES t_basename.cpp fileutils.cpp)
add_executable(t_basename ${t_basename_SOURCES})

set(t_stringutils_SOURCES t_stringutils.cpp stringutils.cpp)
add_executable(t_stringutils ${t_stringutils_SOURCES})

#=== INSTALL ==================
install(TARGETS sysutils
        DESTINATION lib
)

install(
  FILES
    "${PROJECT_SOURCE_DIR}/sysutils/fileutils.h"
    "${PROJECT_SOURCE_DIR}/sysutils/stringutils.h"
  DESTINATION "include/sdts++"
)
