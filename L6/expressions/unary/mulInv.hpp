//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_MULINV_H
#define CPP_MULINV_H


#include "unary.hpp"

class MulInv : public Unary {
public:
    MulInv(const Expression *e);

    double eval() const override;

    std::string toString() const override;

    int getPriority() const override;
};


#endif //CPP_MULINV_H
