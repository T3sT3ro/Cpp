//
// Created by Tooster on 10.04.2018.
//

#include "unary.hpp"

Unary::Unary(const Expression *e) : e1(e) {}

Unary::~Unary() {
    delete e1;
}
