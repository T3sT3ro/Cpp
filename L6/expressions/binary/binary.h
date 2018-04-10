//
// Created by Tooster on 10.04.2018.
//

#ifndef CPP_BINARY_H
#define CPP_BINARY_H


#include "../unary/unary.h"

class Binary : public Unary {
protected:
    const Expression *e2;
public:
    int getPriority() override { return 10; };

    Binary(const Expression *e1, const Expression *e2);
};


#endif //CPP_BINARY_H
