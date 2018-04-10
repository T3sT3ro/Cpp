//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_PI_H
#define CPP_PI_H


#include "constant.h"

/**
 * @class Constant PI = 3.1415.....
 */
class Pi : public Constant {
public:
    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_PI_H
