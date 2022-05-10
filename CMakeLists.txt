cmake_minimum_required(VERSION 2.8)
project("Apache Arrow Table")

#set(CMAKE_MODULE_PATH {CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeModules)
#include(test)

find_package(Arrow REQUIRED)
find_package(XercesC REQUIRED)

include_directories(src)
include_directories(${XERCESC_INCLUDE_DIR})

add_subdirectory(src/xml2arrowtable)
#add_subdirectory(test/unit)
