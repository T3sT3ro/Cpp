cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp L5/main.cpp L5/date.cpp L5/date.hpp L5/dateHour.cpp L5/dateHour.hpp L5/event.cpp L5/event.hpp)