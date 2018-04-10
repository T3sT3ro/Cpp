//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_ABS_H
#define CPP_ABS_H


#include "unary.h"

/**
 * @class Absolute value operand class
 */
class Abs : public Unary {
public:
    Abs(const Expression *e);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_ABS_H
