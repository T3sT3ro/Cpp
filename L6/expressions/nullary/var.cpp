//
// Created by Tooster on 10.04.2018.
//

#include <algorithm>
#include <stdexcept>
#include "var.hpp"

std::vector<std::pair<std::string, double>> Var::variables;


Var::Var(const std::string &symbol) : symbol(symbol) {}

double Var::eval() const {
    return getVar(symbol);
}

std::string Var::toString() const {
    return "'" + symbol;
}

double Var::getVar(const std::string symbol) {
    auto ptr = std::find_if(variables.begin(), variables.end(),
                            [&symbol](std::pair<std::string, double> k) -> bool { return k.first == symbol; });
    if (ptr == variables.end()) throw std::runtime_error("\t Expression: Undefined variable: '" + symbol + "'");
    return ptr->second;
}

void Var::setVar(const std::string symbol, const double val) {
    auto ptr = std::find_if(variables.begin(), variables.end(),
                            [&symbol](std::pair<std::string, double> k) -> bool { return k.first == symbol; });
    if (ptr == variables.end()) {
        variables.emplace_back(std::make_pair(symbol, val));
        std::sort(variables.begin(), variables.end());
    } else
        ptr->second = val;
}

void Var::remVar(const std::string symbol) {
    auto ptr = std::find_if(variables.begin(), variables.end(),
                            [&symbol](std::pair<std::string, double> k) -> bool { return k.first == symbol; });
    if (ptr != variables.end())
        variables.erase(ptr);
}

const std::vector<std::pair<std::string, double>> &Var::getVars() {
    return variables;
}

