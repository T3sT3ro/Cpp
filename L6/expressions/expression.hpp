//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_EXPRESSION_H
#define CPP_EXPRESSION_H

#include <stdint.h>
#include <string>
#include <climits>

/**
 * @class Class representing mathematical expression
 */
class Expression {
protected:
    enum PRIORITY {
        PRIORITY_NULLARY = 0,
        PRIORITY_UNARY = 0,
        PRIORITY_BINARY = 0,
        PRIORITY_ADD_INV = 2,
        PRIORITY_MUL_INV = 2,
        PRIORITY_MOD = 1,
        PRIORITY_POW = 1,
        PRIORITY_DIV = 2,
        PRIORITY_MUL = 2,
        PRIORITY_ADD = 3,
        PRIORITY_SUB = 3
    };

public:
    /// @brief Returns operator's priority
    /// @note multiplication has lower priority than addition etc.
    virtual int getPriority() const { return Expression::PRIORITY_NULLARY; };
    /// @brief evaluates the expression
    virtual double eval() const = 0;

    /// @brief returns the expression in string format
    virtual std::string toString() const = 0;

    virtual ~Expression() = default;
};


#endif //CPP_EXPRESSION_H
