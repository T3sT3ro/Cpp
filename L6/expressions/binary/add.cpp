//
// Created by Tooster on 10.04.2018.
//

#include "add.h"

Add::Add(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Add::eval() const {
    return e1->eval() + e2->eval();
}

std::string Add::toString() const {
    return e1->toString() + "+" + e2->toString();
}

int Add::getPriority() const {
    return Expression::PRIORITY_ADD;
}
