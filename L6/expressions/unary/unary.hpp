//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_UNARY_H
#define CPP_UNARY_H

#include <memory>
#include "../expression.hpp"

/**
 * @class Class representing unary operand
 */
class Unary : public Expression {
protected:
    const Expression *e1;
public:
    Unary(const Expression *e);

    int getPriority() const override { return Expression::PRIORITY_UNARY; };

    virtual ~Unary();
};


#endif //CPP_UNARY_H
