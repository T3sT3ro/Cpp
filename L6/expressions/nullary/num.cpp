//
// Created by Tooster on 10.04.2018.
//

#include "num.hpp"

Num::Num(const double val) : val(val) {}

double Num::eval() const {
    return val;
}

std::string Num::toString() const {
    return std::to_string(val);
}
