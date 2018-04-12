//
// Created by Tooster on 10.04.2018.
//

#include <cmath>
#include "cos.hpp"

Cos::Cos(const Expression *e) : Unary(e) {}

double Cos::eval() const {
    return std::cos(e1->eval());
}

std::string Cos::toString() const {
    return "cos(" + e1->toString() + ")";
}
