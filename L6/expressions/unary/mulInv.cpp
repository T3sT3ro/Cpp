//
// Created by Tooster on 10.04.2018.
//

#include "mulInv.hpp"

MulInv::MulInv(const Expression *e) : Unary(e) {}

double MulInv::eval() const {
    return 1.0 / e1->eval();
}

std::string MulInv::toString() const {
    auto s = e1->toString();
    if (e1->getPriority() >= this->getPriority()) s = "(" + s + ")";
    return "1/" + s;
}

int MulInv::getPriority() const {
    return Expression::PRIORITY_MUL_INV;
}
