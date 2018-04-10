//
// Created by Tooster on 10.04.2018.
//

#include <cmath>
#include "sin.h"

Sin::Sin(const Expression *e) : Unary(e) {}

double Sin::eval() const {
    return std::sin(e1->eval());
}

std::string Sin::toString() const {
    return std::string("sin(" + e1->toString() + ")");
}
