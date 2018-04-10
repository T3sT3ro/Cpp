//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_E_H
#define CPP_E_H

#include "constant.h"

/**
 * @class E constant = 2.17...
 */
class E : public Constant {
public:
    double eval() const override;

    std::string toString() const override;
};


#endif //CPP_E_H
