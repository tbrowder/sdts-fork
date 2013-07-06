add_executable(mkstat
  mkstat.cpp
  emit.cpp
  filename.cpp
)

target_link_libraries(mkstat
  boost_system
  sdts++
  sysutils
)
