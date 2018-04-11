//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_MUL_H
#define CPP_MUL_H


#include "binary.h"

/**
 * @class Multiplication operand class
 */
class Mul : public Binary {
public:
    Mul(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;

    int getPriority() const override;
};


#endif //CPP_MUL_H
