cmake_minimum_required (VERSION 3.5)

add_executable(libpassfault_tests UnitTests.cpp)

add_subdirectory(common)
add_subdirectory(io)
add_subdirectory(pattern)

target_link_libraries(libpassfault_tests libpassfault)

add_test(libpassfault_tests libpassfault_tests)
