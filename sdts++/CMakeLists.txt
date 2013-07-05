# gcc specific def needed for this library
add_definitions(-DVECTOR_ITERATOR_POINTER_NOT_EQUIVALENT)

file(GLOB_RECURSE builder_SOURCES   "builder/*.cpp")
file(GLOB_RECURSE container_SOURCES "container/*.cpp")
file(GLOB_RECURSE io_SOURCES        "io/*.cpp")
file(GLOB_RECURSE logical_SOURCES   "logical/*.cpp")

# from:
#   http://www.cmake.org/pipermail/cmake/2002-September/003028.html

# not in original, but needed:
set(Foo_SOURCE_DIR "${CMAKE_SOURCE_DIR}/sdts++/io")
set(Foo_BINARY_DIR "${CMAKE_BINARY_DIR}/sdts++/")

# Create target for the parser
ADD_CUSTOM_TARGET(FooParser echo "FormatParser.tab.cc")

# Create custom command for flex/lex (note the outputs)
ADD_CUSTOM_COMMAND(
  SOURCE  ${Foo_SOURCE_DIR}/FormatLexer.ll
  COMMAND flex++
  ARGS    -B --outfile=${Foo_BINARY_DIR}/FormatLexer.cc ${Foo_SOURCE_DIR}/FormatLexer.ll
  TARGET  FooParser
  OUTPUTS ${Foo_BINARY_DIR}/FormatLexer.cc
)

# Create custom command for bison/yacc (note the DEPENDS)
ADD_CUSTOM_COMMAND(
  SOURCE  ${Foo_SOURCE_DIR}/FormatParser.yy
  COMMAND bison
  ARGS --defines -p sio_8211_yy  --output=${Foo_BINARY_DIR}/FormatParser.cc ${Foo_SOURCE_DIR}/FormatParser.yy
  TARGET  FooParser
  DEPENDS ${Foo_BINARY_DIR}/FormatLexer.cc
  OUTPUTS ${Foo_BINARY_DIR}/FormatParser.cc
)

# Add FormatParser.cc and FormatLexer.cc to the list of sources
SET(Foo_SRCS ${Foo_SRCS}
  ${Foo_BINARY_DIR}/FormatLexer.cc
  ${Foo_BINARY_DIR}/FormatParser.cc
)

# Since FormatParser.tab.cc does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(${Foo_BINARY_DIR}/FormatParser.cc GENERATED)
# Since lex.yy.cc does not exists yet when cmake is run, mark
# it as generated
SET_SOURCE_FILES_PROPERTIES(${Foo_BINARY_DIR}/FormatLexer.cc GENERATED)

# Include binary directory to include lexer.c in parser.c
#INCLUDE_DIRECTORIES(${Foo_BINARY_DIR})

add_library(sdts++ SHARED
  ${builder_SOURCES}
  ${container_SOURCES}
  ${io_SOURCES}
  ${logical_SOURCES}
  ${Foo_SRCS}
)
