//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_MOD_H
#define CPP_MOD_H

#include "binary.h"

/**
 * @class Modulo operator class
 */
class Mod : public Binary {
public:
    /// @brief Return value: remainder of e1/e2 division
    Mod(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;

    int getPriority() const override;
};


#endif //CPP_MOD_H
