//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_DIV_H
#define CPP_DIV_H


#include "binary.hpp"

/**
 * @class Division operand class
 */
class Div : public Binary {
public:
    /**
     * @param e1 numerator
     * @param e2 denominator
     */
    Div(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;

    int getPriority() const override;
};


#endif //CPP_DIV_H
