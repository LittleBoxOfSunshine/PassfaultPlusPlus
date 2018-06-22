cmake_minimum_required (VERSION 3.5)
project (Passfault++)

# Versioning
set (PASSFAULT++_VERSION_MAJOR 0)
set (PASSFAULT++_VERSION_MINOR 1)

# Enable C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Include headers into the project
include_directories(include)

# Include library headers into the project
include_directories(lib/utf8)

# Recursively include source files into the project
file(GLOB_RECURSE SOURCES "src/*.cpp")
 
# Add the executable
add_executable(Passfault++ ${SOURCES})

# Installation location
install(TARGETS Passfault++ DESTINATION bin)

# Link the library
target_link_libraries(Passfault++ utf8)
