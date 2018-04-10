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
    return std::string("(" + e1->toString() + ")^(" + e2->toString() + ")");
}
