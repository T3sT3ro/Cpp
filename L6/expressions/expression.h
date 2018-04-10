//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_EXPRESSION_H
#define CPP_EXPRESSION_H


#include <string>

/**
 * @class Class representing mathematical expression
 */
class Expression {
protected:
    enum PRIORITY {
        PRIORITY_NULLARY = 0,
        PRIORITY_UNARY = 1,
        PRIORITY_
    };

    /// @brief Returns operator's priority
    /// @note multiplication has lower priority than addition etc.
    virtual int getPriority() { return INT_MAX; };
public:
    /// @brief evaluates the expression
    virtual double eval() const = 0;

    /// @brief returns the expression in string format
    virtual std::string toString() const = 0;
};


#endif //CPP_EXPRESSION_H
