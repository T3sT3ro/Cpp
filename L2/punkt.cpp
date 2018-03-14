//
// Created by Tooster on 04.03.2018.
//

#include "punkt.hpp"

Punkt::Punkt(const double &x, const double &y) : x(x), y(y) {}

Punkt::Punkt(const Punkt &p, const Wektor &v) : x(p.x + v.dx), y(p.y + v.dy) {}

bool Punkt::operator==(const Punkt &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Punkt::operator!=(const Punkt &rhs) const {
    return !(rhs == *this);
}

Punkt Punkt::operator*(const double &scalar) const {
    return Punkt(this->x * scalar, this->y * scalar);
}

