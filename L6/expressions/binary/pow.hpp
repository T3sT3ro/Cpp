//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_POW_H
#define CPP_POW_H

#include "binary.hpp"

/**
 * @class Power operator class
 */
class Pow : public Binary {
public:
    /**
     * @param e1 base
     * @param e2 exponent
     */
    Pow(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;

    int getPriority() const override;

};


#endif //CPP_POW_H
