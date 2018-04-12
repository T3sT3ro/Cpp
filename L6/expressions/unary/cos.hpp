//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_COS_H
#define CPP_COS_H


#include "unary.hpp"

/**
 * @class Cosinus operand class
 */
class Cos : public Unary {
public:
    Cos(const Expression *e);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_COS_H
