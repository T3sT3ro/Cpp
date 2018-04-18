cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp
        L7/matrix.cpp
        L7/matrix.hpp
        L7/exceptions/matrix_exception.hpp
        L7/exceptions/invalid_dimensions_exception.hpp
        L7/test.cpp
        L7/exceptions/matrix_index_out_of_bounds.hpp
        L7/exceptions/invalid_scalar_exception.hpp
        L7/exceptions/not_square_matrix_exception.hpp L7/exceptions/not_invertible_matrix_exception.h)