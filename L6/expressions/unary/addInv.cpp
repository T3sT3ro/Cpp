//
// Created by Tooster on 10.04.2018.
//

#include "addInv.h"

AddInv::AddInv(const Expression *e) : Unary(e) {}

double AddInv::eval() const {
    return (-1.0) * e1->eval();
}

std::string AddInv::toString() const {
    auto s = e1->toString();
    if (e1->getPriority() > this->getPriority()) s = "(" + s + ")";
    return s;
}

int AddInv::getPriority() const {
    return Expression::PRIORITY_ADD_INV;
}
