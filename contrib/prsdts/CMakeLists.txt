add_executable(prsdts
  prsdts.cpp
)

target_link_libraries(prsdts
  boost_system
  sdts++
  fl
  sysutils
)
