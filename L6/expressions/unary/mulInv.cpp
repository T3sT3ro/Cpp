//
// Created by Tooster on 10.04.2018.
//

#include "mulInv.h"

MulInv::MulInv(const Expression *e) : Unary(e) {}

double MulInv::eval() const {
    return 1.0 / e1->eval();
}

std::string MulInv::toString() const {
    return std::string("1/(" + e1->toString() + ")");
}
