//
// Created by Tooster on 10.04.2018.
//

#include "mul.hpp"

Mul::Mul(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Mul::eval() const {
    return e1->eval() * e2->eval();
}

std::string Mul::toString() const {
    auto s1 = e1->toString();
    auto s2 = e2->toString();
    if (e1->getPriority() > this->getPriority()) s1 = "(" + s1 + ")";
    if (e2->getPriority() > this->getPriority()) s2 = "(" + s2 + ")";
    return s1 + "*" + s2;
}

int Mul::getPriority() const {
    return Expression::PRIORITY_MUL;
}
