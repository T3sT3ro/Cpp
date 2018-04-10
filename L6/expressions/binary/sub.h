//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_SUB_H
#define CPP_SUB_H


#include "binary.h"

/**
 * @class Subtraction operand class
 */
class Sub : public Binary {
public:
    /**
     * @param e1 minuend
     * @param e2 subtrahend
     */
    Sub(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_SUB_H
