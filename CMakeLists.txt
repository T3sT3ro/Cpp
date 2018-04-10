cmake_minimum_required(VERSION 3.8)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp
        L6/expressions/expression.h
        L6/test.cpp
        L6/expressions/nullary/num.cpp
        L6/expressions/nullary/num.h
        L6/expressions/nullary/constant.h
        L6/expressions/nullary/pi.cpp
        L6/expressions/nullary/pi.h
        L6/expressions/nullary/e.cpp
        L6/expressions/nullary/e.h
        L6/expressions/nullary/Phi.cpp
        L6/expressions/nullary/Phi.h
        L6/expressions/nullary/var.cpp
        L6/expressions/nullary/var.h
        L6/expressions/unary/unary.h
        L6/expressions/unary/sin.cpp
        L6/expressions/unary/sin.h
        L6/expressions/unary/cos.cpp
        L6/expressions/unary/cos.h
        L6/expressions/unary/unary.cpp
        L6/expressions/unary/ln.cpp
        L6/expressions/unary/ln.h
        L6/expressions/unary/exp.cpp
        L6/expressions/unary/exp.h
        L6/expressions/unary/abs.cpp
        L6/expressions/unary/abs.h
        L6/expressions/unary/addInv.cpp
        L6/expressions/unary/addInv.h
        L6/expressions/unary/mulInv.cpp
        L6/expressions/unary/mulInv.h
        L6/expressions/binary/binary.cpp
        L6/expressions/binary/binary.h
        L6/expressions/binary/add.cpp
        L6/expressions/binary/add.h L6/expressions/binary/sub.cpp L6/expressions/binary/sub.h L6/expressions/binary/mul.cpp L6/expressions/binary/mul.h L6/expressions/binary/div.cpp L6/expressions/binary/div.h L6/expressions/binary/log.cpp L6/expressions/binary/log.h L6/expressions/binary/mod.cpp L6/expressions/binary/mod.h L6/expressions/binary/pow.cpp L6/expressions/binary/pow.h)