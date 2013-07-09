add_executable(sdtsdem2xyz
  sdtsdem2xyz.cpp
)

target_link_libraries(sdtsdem2xyz
  boost_system
  boost_filesystem
  sdts++
  sysutils
)

#=== INSTALL ==================
install(TARGETS sdtsdem2xyz
        DESTINATION bin
)

install(
  FILES
    "${PROJECT_SOURCE_DIR}/contrib/sdtsdem2xyz/sdtsdem2xyz.1"
  DESTINATION "share/man/man1"
)
