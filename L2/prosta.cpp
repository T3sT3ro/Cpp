//
// Created by Tooster on 04.03.2018.
//

#include <stdexcept>
#include <cmath>
#include "prosta.h"

double Prosta::getA() const {
    return a;
}

double Prosta::getB() const {
    return b;
}

double Prosta::getC() const {
    return c;
}

Prosta::Prosta(const Punkt &a, const Punkt &b) : a(a.y - b.y),
                                                 b(b.x - a.x),
                                                 c(a.y * (a.x - b.x) - a.x * (a.y - b.y)) {
    if (a == b)
        throw std::invalid_argument("Prosta: Line must go through two separate points");
    normalize();
}

Prosta::Prosta(const Wektor &v) : Prosta(Punkt({0, 0}, v), Punkt({-1 * v.dy, v.dx}, v)) {
    if (v == Wektor(0, 0))
        throw std::invalid_argument("Prosta: cannot create line perpendicular to vector {0,0}");
    normalize();
}

Prosta::Prosta(double a, double b, double c) : a(a), b(b), c(c) {
    if (a == 0 && b == 0)
        throw std::invalid_argument("Prosta: a and b cannot be 0 simultaneously");
    normalize();
}

Prosta::Prosta(const Prosta &p, const Wektor &v) : Prosta(p.a, p.b, p.c - (v.dx * p.a + v.dy * p.b)) { normalize(); }

inline void Prosta::normalize() {
    double k = std::sqrt(a * a + b * b);
    a /= k;
    b /= k;
    c /= k;
}

bool Prosta::operator==(const Prosta &rhs) const {
    return (a == rhs.a &&
            b == rhs.b &&
            c == rhs.c) || (a * (-1) == rhs.a &&
                            b * (-1) == rhs.b &&
                            c * (-1) == rhs.c);
}

bool Prosta::operator!=(const Prosta &rhs) const {
    return !(rhs == *this);
}

bool Prosta::contains(const Punkt &a) const {
    return std::abs(this->a * a.x + this->b * a.y + this->c) < epsilon;
}

bool Prosta::perpendicular(const Prosta &p1, const Prosta &p2) {
    return std::abs(p1.getA() * p2.getA() + p1.getB() * p2.getB()) < epsilon;
}

bool Prosta::perpendicular(const Wektor &v) const {
    return Prosta::perpendicular(*this, Prosta({0, 0}, Punkt({0, 0}, v)));
}

bool Prosta::parallel(const Prosta &p1, const Prosta &p2) {
    return std::abs(p1.getA() * p2.getB() - p2.getA() * p1.getB()) < epsilon;
}

bool Prosta::parallel(const Wektor &v) const {
    return Prosta::parallel(*this, Prosta({0, 0}, Punkt({0, 0}, v)));
}

Punkt Prosta::intersection(const Prosta &p1, const Prosta &p2) {
    if (parallel(p1, p2)) return Punkt(std::nan("inf"), std::nan("inf"));
    double W = p1.getA() * p2.getB() - p2.getA() * p1.getB();
    double Wx = p2.getC() * p1.getB() - p2.getB() * p1.getC();
    double Wy = p2.getA() * p1.getC() - p1.getA() * p2.getC();
    return Punkt(Wx / W, Wy / W);
}
