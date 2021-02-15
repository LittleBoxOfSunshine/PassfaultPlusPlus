cmake_minimum_required (VERSION 3.5)
project(utf8 LANGUAGES CXX)

# Enable C++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_library(utf8 STATIC utf8.hpp)

set_target_properties(utf8 PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(utf8 PUBLIC utf8)
