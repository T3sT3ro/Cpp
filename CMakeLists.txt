cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp
        L8/rational.cpp
        L8/rational.hpp
        L8/exception/rational_exception.hpp
        L8/exception/zero_denominator_exception.hpp
        L8/test.cpp
        L8/exception/out_of_range_exception.hpp)