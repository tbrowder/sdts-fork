add_executable(pr8211
  pr8211.cpp
)

target_link_libraries(pr8211
  boost_system
  boost_filesystem
  sdts++
)

#=== INSTALL ==================
install(TARGETS pr8211
        DESTINATION bin
)
