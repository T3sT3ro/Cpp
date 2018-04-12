//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_EXP_H
#define CPP_EXP_H


#include "unary.hpp"

/**
 * @class Exponential function operand class
 */
class Exp : public Unary {
public:
    Exp(const Expression *e);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_EXP_H
