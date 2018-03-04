//
// Created by Tooster on 04.03.2018.
//

#ifndef CPP_PUNKT_H
#define CPP_PUNKT_H


#include "wektor.h"

class Punkt {
public:
    const double x = 0, y = 0;

    Punkt() = default; // default
    Punkt(const double &x, const double &y); // coords
    Punkt(const Punkt &p, const Wektor &v); // point + vector
    Punkt(const Punkt &other) = default; // copy

    Punkt &operator=(const Punkt &) = delete; // copy assignment deleted

    bool operator==(const Punkt &rhs) const;

    bool operator!=(const Punkt &rhs) const;

    Punkt operator*(const double &scalar) const;

};


#endif //CPP_PUNKT_H
