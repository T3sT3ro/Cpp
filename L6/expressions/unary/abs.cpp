//
// Created by Tooster on 10.04.2018.
//

#include "abs.hpp"
#include <cmath>

Abs::Abs(const Expression *e) : Unary(e) {}

double Abs::eval() const {
    return std::abs(e1->eval());
}

std::string Abs::toString() const {
    return "|" + e1->toString() + "|";
}
