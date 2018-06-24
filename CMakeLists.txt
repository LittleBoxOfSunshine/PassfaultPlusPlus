cmake_minimum_required (VERSION 3.5)
project (Passfault++ VERSION 0.1 LANGUAGES CXX)

# Install libraries into correct locations across all platforms
include(GNUInstallDirs)

enable_testing()

# Target doc definition
# add_custom_target(doc)
# ADD_DEPENDENCIES(doc )

add_subdirectory(libpassfault)
#add_subdirectory(cli)