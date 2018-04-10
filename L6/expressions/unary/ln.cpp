//
// Created by Tooster on 10.04.2018.
//

#include "ln.h"
#include <cmath>

Ln::Ln(const Expression *e) : Unary(e) {}

double Ln::eval() const {
    return std::log(e1->eval());
}

std::string Ln::toString() const {
    return std::string("ln(" + e1->toString() + ")");
}
