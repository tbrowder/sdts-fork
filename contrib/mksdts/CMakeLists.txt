set(mksdts_SOURCES
 parser.tab.cc
 lex.yy.cc
)
add_custom_command(
  OUTPUT parser.tab.hh parser.tab.cc
  COMMAND bison -d parser.yy
)
add_custom_command(
  OUTPUT lex.yy.cc
  COMMAND flex++ lexer.ll
)

add_executable(mksdts ${mksdts_SOURCES})

#=== INSTALL ==================
install(TARGETS mksdts
        DESTINATION bin
)

install(
  FILES
    "${PROJECT_SOURCE_DIR}/contrib/mksdts/mksdts.1"
  DESTINATION "share/man/man1"
)
