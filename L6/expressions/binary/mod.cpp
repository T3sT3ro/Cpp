//
// Created by Tooster on 10.04.2018.
//

#include <cmath>
#include "mod.h"

Mod::Mod(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Mod::eval() const {
    return std::fmod(e1->eval(), e2->eval());
}

std::string Mod::toString() const {
    return std::string("(" + e1->toString() + ")%(" + e2->toString() + ")");
}
