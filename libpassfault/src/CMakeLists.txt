cmake_minimum_required (VERSION 3.5)

add_subdirectory(common)
add_subdirectory(io)
add_subdirectory(pattern)

target_sources(libpassfault PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/PasswordAnalysis.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Path.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Pattern.cpp")
