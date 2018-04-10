//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_VARIABLE_H
#define CPP_VARIABLE_H


#include <string>
#include <vector>
#include "../expression.h"

class Var : public Expression {
    std::string symbol;
    static std::vector<std::pair<std::string, double>> variables;
public:
    Var(const std::string &symbol);

    double eval() const override;

    std::string toString() const override;

    static double getVar(const std::string symbol);

    static void setVar(const std::string symbol, const double val);

    static void remVar(const std::string symbol);

    static const std::vector<std::pair<std::string, double>> &getVars();
};


#endif //CPP_VARIABLE_H
