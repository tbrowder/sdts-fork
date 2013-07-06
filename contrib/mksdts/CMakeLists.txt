# not in original, but needed:
set(Foo2_SOURCE_DIR "${CMAKE_SOURCE_DIR}/contrib/mksdts")
set(Foo2_BINARY_DIR "${CMAKE_BINARY_DIR}/contrib/mksdts")

# Create target for the parser
ADD_CUSTOM_TARGET(Foo2Parser echo "parser...")

# Create custom command for flex/lex (note the outputs)
ADD_CUSTOM_COMMAND(
  SOURCE  ${Foo2_SOURCE_DIR}/lexer.ll
  COMMAND flex
  ARGS    -B
          -nounistd
          --outfile=${Foo2_BINARY_DIR}/lexer.cc
          ${Foo2_SOURCE_DIR}/lexer.ll
  TARGET  Foo2Parser
  OUTPUTS ${Foo2_BINARY_DIR}/lexer.cc
)

# Create custom command for bison/yacc (note the DEPENDS)
ADD_CUSTOM_COMMAND(
  SOURCE  ${Foo2_SOURCE_DIR}/parser.yy
  COMMAND bison
  ARGS    --defines
          --output=${Foo2_BINARY_DIR}/parser.cc
          ${Foo2_SOURCE_DIR}/parser.yy
  TARGET  Foo2Parser
  DEPENDS ${Foo2_BINARY_DIR}/lexer.cc
  OUTPUTS ${Foo2_BINARY_DIR}/parser.cc
)

# Add FormatParser.c and FormatLexer.c to the list of sources
#SET(Foo2_SRCS ${Foo2_SRCS}
SET(Foo2_SRCS
  ${Foo2_BINARY_DIR}/lexer.cc
  ${Foo2_BINARY_DIR}/parser.cc
)

# Since parser.cc does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(${Foo2_BINARY_DIR}/parser.cc GENERATED)
# Since lexer.cc does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(${Foo2_BINARY_DIR}/lexer.cc GENERATED)

# Include binary directory to include lexer.cc in parser.cc
INCLUDE_DIRECTORIES(${Foo2_BINARY_DIR})

add_executable(mksdts ${Foo2_SRCS})

target_link_libraries(mksdts
  boost_system
  sdts++
  fl
  sysutils
)

#=== INSTALL ==================
install(TARGETS mksdts
        DESTINATION bin
)

install(
  FILES
    "${PROJECT_SOURCE_DIR}/contrib/mksdts/mksdts.1"
  DESTINATION "share/man/man1"
)
