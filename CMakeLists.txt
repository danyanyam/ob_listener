cmake_minimum_required(VERSION 3.5)
project(cpp_http)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/build;${CMAKE_MODULE_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/artefacts")

# Conan settins
include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()
find_package(boost)

include_directories(src)

add_subdirectory(src/ftx/rest)
add_subdirectory(src/ftx/ws)
add_subdirectory(src/ftx/util)
add_subdirectory(src/scripts)
