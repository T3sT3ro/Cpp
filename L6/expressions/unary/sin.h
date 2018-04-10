//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_SIN_H
#define CPP_SIN_H


#include "unary.h"

/**
 * @class Sinus operand class
 */
class Sin : public Unary {
public:
    Sin(const Expression *e);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_SIN_H
