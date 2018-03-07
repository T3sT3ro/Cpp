//
// Created by Tooster on 04.03.2018.
//
#include <cassert>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <functional>
#include <random>
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
        for (auto &it : r)
            it = std::rand() % 1000;

        Punkt *_a = new Punkt(r[0], r[1]);
        Punkt *_b = new Punkt(r[2], r[3]);
        Punkt *_c = new Punkt(r[4], r[5]);

        try {

            // adding vectors
            assert(Wektor::add({r[0], r[1]}, {r[2], r[3]}) == Wektor(r[0] + r[2], r[1] + r[3]));


            Prosta *_p = new Prosta(*_a, *_b);

            // check if points on which line was created really belong to the line
            assert(_p->contains(*_a) && _p->contains(*_b));

            // tests creation of line based on vector
            delete (_p);
            _p = new Prosta(Wektor(_a->x, _a->y));
            assert(_p->contains(Punkt(Punkt({0, 0}, Wektor(_a->y, _a->x * (-1))) * r[3], Wektor(_a->x, _a->y))));

            // check if line is in normalised form
            assert(std::abs(_p->getA() * _p->getA() + _p->getB() * _p->getB() - 1.00000000) < epsilon);

            // check for parallel and perpendicular lines
            assert(Prosta::parallel(Prosta(*_a, *_b),
                                    Prosta(Punkt(*_a, Wektor(_c->x, _c->y)), Punkt(*_b, Wektor(_c->x, _c->y)))));
            assert(Prosta::perpendicular(Prosta({0, 0}, *_a), Prosta(Wektor(_a->x, _a->y))));

            auto closeEqual = [](Punkt a, Punkt b) -> bool {
                return std::abs(a.x - b.x) < epsilon &&
                       std::abs(a.y - b.y) < epsilon;
            };
            // check intersection for perpendicular
            Punkt inter = Prosta::intersection(Prosta({0, 0}, *_a), Prosta(Wektor(_a->x, _a->y)));
            assert(std::isnan(inter.x) || closeEqual(inter, *_a));

            // check intersection for askew lines
            Prosta *pi1 = new Prosta(*a, *b);
            Prosta *pi2 = new Prosta(*b, *c);
            assert(closeEqual(Prosta::intersection(*pi1, *pi2), *b));
            delete(pi1, pi2);

            delete (_p);

        } catch (std::invalid_argument &e) {
            std::cerr << "Captured exception for randoms: ";
            for (auto const &_r : r)
                std::cerr << _r << " ";
            std::cerr << " >> " << e.what() << std::endl;
        }
        delete (_a);
        delete (_b);
        delete (_c);
    }


    std::cout << "Tests passed" << std::endl;

}