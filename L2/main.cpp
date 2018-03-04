//
// Created by Tooster on 04.03.2018.
//
#include <cassert>
#include <iostream>
#include <cmath>
#include "prosta.h"

constexpr double epsilon = 0.000001;

int main() {
    Punkt *_x = new Punkt();
    Wektor *_v = new Wektor();
    Prosta *_p = new Prosta();

    Wektor *v0 = new Wektor(0, 0);
    Wektor *v = new Wektor(-1, 7);
    Wektor *v2 = new Wektor(*v);

    Punkt *a = new Punkt(0, 0);
    Punkt *a2 = new Punkt(*a, *v0);
    Punkt *b = new Punkt(3, 1);
    Punkt *c = new Punkt(*b, *v);
    Punkt *c2 = new Punkt(*c);

    Prosta *p1 = new Prosta(*a, *b);
    Prosta *p2 = new Prosta(*b, *c);
    Prosta *p3 = new Prosta(*c, *b);

    // assert objects moved by (0,0) and copy constructors
    assert(*v == *v2);
    assert(*a == *a2);
    assert(*c == *c2);
    assert(*p2 == *p3);

    // line contains points
    assert(p1->contains(*b));
    assert(p1->contains(*a));
    assert(!p2->contains(*a));
    assert(p2->contains(*b));
    assert(p2->contains(*c));

    // Punkt m, n=m; n = m; // copy constructor working, deleted copy assign operator
    // Wektor f, g(f); g = f; // copy constructor working, deleted copy assign operator
    // Prosta x, y(x), z=x, u; u=x // deleted copy assign operator

    for (int i = 0; i < 10000000; ++i) { // 1000 randomised tests
        double r[6];
        try {
            for (auto &it : r)
                it = std::rand() % 1000;

            delete (a);
            delete (b);
            delete (c);

            a = new Punkt(r[0], r[1]);
            b = new Punkt(r[2], r[3]);
            c = new Punkt(r[4], r[5]);

            // adding vectors
            assert(Wektor::add({r[0], r[1]}, {r[2], r[3]}) == Wektor(r[0] + r[2], r[1] + r[3]));

            delete (p1);

            p1 = new Prosta(*a, *b);

            // check if points on which line was created really belong to the line
            assert(p1->contains(*a) && p1->contains(*b));

            // tests creation of line based on vector
            delete (p1);
            p1 = new Prosta(Wektor(a->x, a->y));
            assert(p1->contains(Punkt(Punkt({0, 0}, Wektor(a->y, a->x * (-1))) * r[3], Wektor(a->x, a->y))));

            // check if line is in normalised form
            assert(std::abs(p1->getA() * p1->getA() + p1->getB() * p1->getB() - 1.00000000) < epsilon);

            // check for parallel and perpendicular lines
            assert(Prosta::parallel(Prosta(*a, *b),
                                    Prosta(Punkt(*a, Wektor(c->x, c->y)), Punkt(*b, Wektor(c->x, c->y)))));
            assert(Prosta::perpendicular(Prosta({0, 0}, *a), Prosta(Wektor(a->x, a->y))));

            // check intersection
            Punkt inter = Prosta::intersection(Prosta({0, 0}, *a), Prosta(Wektor(a->x, a->y)));
            assert(std::isnan(inter.x) || std::abs(inter.x - a->x) < epsilon && std::abs(inter.y - a->y) < epsilon);
        } catch (std::invalid_argument &e) {
            std::cerr << "Captured exception for randoms: ";
            for (auto const &_r : r)
                std::cerr << _r << "   ";
            std::cerr << " >> " << e.what();
        }
    }


    std::cout << "Tests passed" << std::endl;

}