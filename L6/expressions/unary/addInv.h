//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_ADDINV_H
#define CPP_ADDINV_H

#include "unary.h"

/**
 * @class Additive inverse operand class
 */
class AddInv : public Unary {
public:
    AddInv(const Expression *e);

    double eval() const override;

    std::string toString() const override;

};


#endif //CPP_ADDINV_H
