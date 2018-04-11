//
// Created by Tooster on 10.04.2018.
//

#include "sub.h"

Sub::Sub(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Sub::eval() const {
    return e1->eval() - e2->eval();
}

std::string Sub::toString() const {
    auto s = e1->toString();
    if (e1->getPriority() == this->getPriority()) s = "(" + s + ")";
    return e1->toString() + "-" + e2->toString();
}

int Sub::getPriority() const {
    return Expression::PRIORITY_SUB;
}
