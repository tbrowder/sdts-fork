# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

aux_source_directory(./builder BUILDER)
#aux_source_directory(./container CONTAINER)
#aux_source_directory(./io IO)
#aux_source_directory(./logical LOGICAL)

include_directories(
  ./builder
  ./container
  ./io
  ./logical
)

add_library(sdts++ SHARED ${BUILDER} ${CONTAINER} ${IO} ${LOGICAL})

# Create a variable called helloworld_SOURCES containing all .cpp files:
#set(sdts_SOURCES helloworld.cpp main.cpp)

# For a large number of source files you can create it in a simpler way
# using file() function:
# file(GLOB hellworld_SOURCES *.cpp)

# Create an executable file called helloworld from sources:
#add_executable(helloworld ${helloworld_SOURCES})
