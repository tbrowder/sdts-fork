add_executable(prsdts
  prsdts.cpp
)

target_link_libraries(prsdts
  boost_system
  boost_filesystem
  sdts++
  fl
)

#=== INSTALL ==================
install(TARGETS prsdts
        DESTINATION bin
)
