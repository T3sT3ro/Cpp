//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_PHI_H
#define CPP_PHI_H


#include "constant.h"

class Phi : public Constant {
public:
    double eval() const override;

private:
    std::string toString() const override;
};


#endif //CPP_PHI_H
