//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_INTEGER_H
#define CPP_INTEGER_H


#include "../expression.h"

/**
 * @class Class representing a number expression
 */
class Num : public Expression {
    double val;
public:
    Num(const double val);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_INTEGER_H
