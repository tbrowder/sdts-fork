add_executable(mkstat
  mkstat.cpp
  emit.cpp
  filename.cpp
)
add_dependencies(mkstat
  "${PROJECT_BINARY_DIR}/sdts++/sdts-config.h"
)

target_link_libraries(mkstat
  boost_system
  boost_filesystem
  sdts++
)

#=== INSTALL ==================
install(TARGETS mkstat
        DESTINATION bin
)

install(
  FILES
    "${PROJECT_SOURCE_DIR}/contrib/mkstat/mkstat.1"
  DESTINATION "share/man/man1"
)

