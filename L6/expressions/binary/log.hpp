//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_LOG_H
#define CPP_LOG_H


#include "binary.hpp"

/**
 * @class Logarithm operator class
 */
class Log : public Binary {
public:
    /**
     * @param e1 logarithm's base
     * @param e2 value
     */
    Log(const Expression *e1, const Expression *e2);

    double eval() const override;

    std::string toString() const override;

};


#endif //CPP_LOG_H
