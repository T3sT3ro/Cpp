//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_ADD_H
#define CPP_ADD_H


#include "binary.h"

/**
 * @class Addition operand class
 */
class Add : public Binary {
public:
    Add(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_ADD_H
