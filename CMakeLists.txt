cmake_minimum_required(VERSION 2.8)
project("Apache Arrow Table")

set(CMAKE_MODULE_PATH {CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeModules)

#include(test)

include_directories(src)

add_subdirectory(src/xml2arrowtable)
#add_subdirectory(test/unit)
