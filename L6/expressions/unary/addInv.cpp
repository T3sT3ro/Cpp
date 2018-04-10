//
// Created by Tooster on 10.04.2018.
//

#include "addInv.h"

AddInv::AddInv(const Expression *e) : Unary(e) {}

double AddInv::eval() const {
    return (-1.0) * e1->eval();
}

std::string AddInv::toString() const {
    return std::string("(-1)*(" + e1->toString() + ")");
}
