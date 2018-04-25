//
// Created by Tooster on 21.04.2018.
//


#include <climits>
#include <iostream>
#include "rational.hpp"
#include "exception/zero_denominator_exception.hpp"
#include "exception/out_of_range_exception.hpp"

using namespace Calculations;

int main() {
    Rational r(INT_MIN, INT_MIN);
    Rational x = r + Rational(1, 4);
    x = !x;
    std::cout << x << std::endl;
    std::cout << Rational(122177813, 99900000).asDecimal() << std::endl;
    std::cout << Rational(1, 3).asDecimal() << std::endl;
    std::cout << Rational(1, 2).asDecimal() << std::endl;
    std::cout << Rational(1, 64).asDecimal() << std::endl;
    std::cout << Rational(1, 81).asDecimal() << std::endl;
    try {
        Rational t(3, 0);
        t *= Rational(3);
    }
    catch (zero_denominator_exception &e) { std::cout << "CAUGHT: " << e.what() << std::endl; };
    try {
        Rational t(0, 3);
        t = !t;
    }
    catch (zero_denominator_exception &e) { std::cout << "CAUGHT: " << e.what() << std::endl; };
    try { Rational(INT_MAX) + Rational(INT_MAX); }
    catch (out_of_range_exception &e) { std::cout << "CAUGHT: " << e.what() << std::endl; };

    try {
        Rational f, g;
        std::cout << "Input fractions f, g in format 'a b' :" << std::endl;
        std::cin >> f >> g;
        std::cout << "f: " << f << " as int: " << int(f) << " as double: " << double(f) << std::endl;
        std::cout << "g: " << g << " as int: " << int(g) << " as double: " << double(g) << std::endl;
        std::cout << "-f: " << -f << std::endl;
        std::cout << "!f: " << !f << std::endl;
        std::cout << "f*!f: " << f * !f << std::endl;
        std::cout << "f+(-f): " << f + -f << std::endl;

        std::cout << "f+g: " << f + g << std::endl;
        std::cout << "f-g: " << f - g << std::endl;
        std::cout << "f*g: " << f * g << std::endl;
        std::cout << "f/g: " << f / g << std::endl;
    } catch (rational_exception &e) {
        std::cout << "CAUGHT: " << e.what() << std::endl;
    }

    return 0;
}