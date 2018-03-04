//
// Created by Tooster on 04.03.2018.
//

#ifndef CPP_PROSTA_H
#define CPP_PROSTA_H


#include "punkt.h"

class Prosta {
private:
    double a, b, c;

public:
    static constexpr double epsilon = 0.000001;

    Prosta() = default;  // no parameter
    Prosta(const Punkt &a, const Punkt &b);

    explicit Prosta(const Wektor &v); // perpendicular to vector
    Prosta(double a, double b, double c); //
    Prosta(const Prosta &p, const Wektor &v);

    // delete copying constructors and copy assignment
    Prosta(Prosta const &) = delete;

    void operator=(Prosta const &) = delete;

    double getA() const;

    double getB() const;

    double getC() const;

    bool operator==(const Prosta &rhs) const;

    bool operator!=(const Prosta &rhs) const;

    /// Checks if given point belongs to the line
    bool contains(const Punkt &a) const;

    /// Checks if given
    static bool perpendicular(const Prosta &p1, const Prosta &p2);

    bool perpendicular(const Wektor &v) const;

    static bool parallel(const Prosta &p1, const Prosta &p2);

    bool parallel(const Wektor &v) const;

    static Punkt intersection(const Prosta &p1, const Prosta &p2);

private:
    inline void normalize();
};


#endif //CPP_PROSTA_H
