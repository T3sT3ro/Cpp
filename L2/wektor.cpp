//
// Created by Tooster on 04.03.2018.
//

#include "wektor.hpp"

Wektor::Wektor(const double &dx, const double &dy) : dx(dx), dy(dy) {}

Wektor Wektor::add(const Wektor &a, const Wektor &b) {
    return Wektor(a.dx + b.dx, a.dy + b.dy);
}

bool Wektor::operator==(const Wektor &rhs) const {
    return dx == rhs.dx &&
           dy == rhs.dy;
}

bool Wektor::operator!=(const Wektor &rhs) const {
    return !(rhs == *this);
}
