cmake_minimum_required (VERSION 3.5)
project (libpassfault VERSION 0.1 LANGUAGES CXX)

# Enable C++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(lib/utf8)

add_library(libpassfault SHARED "")

# Include headers into the project
target_include_directories(libpassfault PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_subdirectory(src)

target_link_libraries(libpassfault utf8)
 
# Add the executable
#add_executable(libpassfault ${SOURCES} include/pattern/keyboard/Layout.hpp include/pattern/dictionary/DiskDictionary.hpp include/pattern/dictionary/MemoryDictionary.hpp include/pattern/dictionary/Substitution.hpp include/pattern/dictionary/Insertion.hpp include/pattern/dictionary/Misspelled.hpp include/pattern/keyboard/Horizontal.hpp include/pattern/keyboard/Diagonal.hpp include/pattern/keyboard/Hop.hpp include/pattern/keyboard/ZigZag.hpp include/finder/Finder.hpp src/test.cpp)

# Use GNUInstallDirs to point 'make install' to the correct locations
install(TARGETS libpassfault EXPORT MyLibraryConfig
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# TODO: Determine if exports should be added

add_subdirectory(test)
