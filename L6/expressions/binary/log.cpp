//
// Created by Tooster on 10.04.2018.
//

#include <cmath>
#include "log.h"

Log::Log(const Expression *e1, const Expression *e2) : Binary(e1, e2) {}

double Log::eval() const {
    return std::log(e2->eval()) / std::log(e1->eval());
}

std::string Log::toString() const {
    return std::string("log_" + e1->toString() + "_(" + e2->toString() + ")");
}
