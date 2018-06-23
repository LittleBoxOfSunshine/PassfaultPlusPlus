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
add_executable(Passfault++ ${SOURCES} include/pattern/keyboard/Layout.hpp include/pattern/dictionary/DiskDictionary.hpp include/pattern/dictionary/MemoryDictionary.hpp include/pattern/dictionary/Substitution.hpp include/pattern/dictionary/Insertion.hpp include/pattern/dictionary/Misspelled.hpp include/pattern/keyboard/Horizontal.hpp include/pattern/keyboard/Diagonal.hpp include/pattern/keyboard/Hop.hpp include/pattern/keyboard/ZigZag.hpp include/finder/Finder.hpp)

# Installation location
install(TARGETS Passfault++ DESTINATION bin)

# Link the library
target_link_libraries(Passfault++ utf8)
