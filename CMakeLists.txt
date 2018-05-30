cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp L10/main.cpp L10/manipulators.hpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/L10/test.txt test.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/L10/from from COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/L10/to to COPYONLY)