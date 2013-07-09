add_executable(tomksdts
  tomksdts.cpp
  convert.cpp
)

target_link_libraries(tomksdts
  boost_system
  boost_filesystem
  sdts++
)

#=== INSTALL ==================
install(TARGETS tomksdts
        DESTINATION bin
)

install(
  FILES
    "${PROJECT_SOURCE_DIR}/contrib/tomksdts/tomksdts.1"
  DESTINATION "share/man/man1"
)
