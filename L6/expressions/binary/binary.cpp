//
// Created by Tooster on 10.04.2018.
//

#include "binary.hpp"

Binary::Binary(const Expression *e1, const Expression *e2) : Unary(e1), e2(e2) {}

Binary::~Binary() {
    delete e2;
}
