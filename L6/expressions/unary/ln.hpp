//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_LN_H
#define CPP_LN_H


#include "unary.hpp"

/**
 * @class Natural logarithm operand class
 */
class Ln : public Unary {
public:
    Ln(const Expression *e);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_LN_H
