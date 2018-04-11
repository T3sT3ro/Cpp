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
    int getPriority() const override { return Expression::PRIORITY_BINARY; };

    Binary(const Expression *e1, const Expression *e2);

    virtual ~Binary();
};


#endif //CPP_BINARY_H
