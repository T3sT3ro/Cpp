//
// Created by Tooster on 10.04.2018.
//

#include <cmath>
#include "pow.h"

Pow::Pow(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Pow::eval() const {
    return std::pow(e1->eval(), e2->eval());
}

std::string Pow::toString() const {
    auto s1 = e1->toString();
    auto s2 = e2->toString();
    if (e1->getPriority() >= this->getPriority()) s1 = "(" + s1 + ")";
    if (e2->getPriority() > this->getPriority()) s2 = "(" + s2 + ")";
    return e1->toString() + "^" + e2->toString();
}

int Pow::getPriority() const {
    return Expression::PRIORITY_POW;
}
