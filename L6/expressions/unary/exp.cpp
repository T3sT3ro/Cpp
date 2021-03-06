//
// Created by Tooster on 10.04.2018.
//

#include <cmath>
#include "exp.hpp"

Exp::Exp(const Expression *e) : Unary(e) {}

double Exp::eval() const {
    return std::exp(e1->eval());
}

std::string Exp::toString() const {
    return "exp(" + e1->toString() + ")";
}
