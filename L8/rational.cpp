//
// Created by Tooster on 21.04.2018.
//

#include "rational.hpp"
#include "exception/zero_denominator_exception.hpp"
#include "exception/out_of_range_exception.hpp"

#if __cplusplus >= 201703L

#include <numeric>
#include <set>

#elif __cplusplus >= 201103L
#include <experimental/numeric>
#endif

namespace Calculations {
    Rational::Rational(int num, int den) {
        if (den == 0) throw zero_denominator_exception();
        int sign = (num == 0 ? 1 : (num / std::abs(num)) * (den / std::abs(den)));
        auto _gcd = static_cast<int>(gcd(num, den));
        Rational::num = std::abs(num) * sign / _gcd;
        Rational::den = std::abs(den) / _gcd;
    }

    long long Rational::gcd(long long int a, long long int b) const {
        a = std::abs(a);
        b = std::abs(b);
#if __cplusplus >= 201703L
        return std::gcd(a, b);
#elif __cplusplus >= 201103L
        return std::experimental::gcd(a,b);
#endif
    }

    int Rational::getNum() const { return num; }

    void Rational::setNum(int num) { Rational::num = num; }

    int Rational::getDen() const { return den; }

    void Rational::setDen(int den) {
        if (den == 0) throw zero_denominator_exception();
        Rational::den = den;
    }

    Rational Rational::operator-() const { return Rational(-num, den); }

    Rational Rational::operator!() const noexcept(false) { return Rational(den, num); }

    Rational::operator int() const { return Rational::num / Rational::den; }

    Rational::operator double() const {
        return static_cast<double>(Rational::num) / static_cast<double>(Rational::den);
    }

    Rational &Rational::operator+=(const Rational &other) noexcept(false) {
        long long _gcd = gcd(den, other.den);
        long long newNum = (long long) num * (other.den / _gcd) +
                           (long long) other.num * (den / _gcd);
        long long newDen = (long long) den * (other.den / _gcd);
        _gcd = gcd(newNum, newDen);
        newNum /= _gcd;
        newDen /= _gcd;
        if (newNum > INT_MAX || newNum < INT_MIN ||
            newDen > INT_MAX || newDen < INT_MIN)
            throw out_of_range_exception();
        Rational::num = static_cast<int>(newNum);
        Rational::den = static_cast<int>(newDen);
        return *this;
    }

    Rational &Rational::operator-=(const Rational &other) noexcept(false) { return *this += -other; }

    Rational &Rational::operator*=(const Rational &other) noexcept(false) {
        long long newNum = (long long) num * (long long) (other.num);
        long long newDen = (long long) den * (long long) (other.den);
        long long _gcd = gcd(newNum, newDen);
        newNum /= _gcd;
        newDen /= _gcd;
        if (newNum > INT_MAX || newNum < INT_MIN ||
            newDen > INT_MAX || newDen < INT_MIN)
            throw out_of_range_exception();
        Rational::num = static_cast<int>(newNum);
        Rational::den = static_cast<int>(newDen);
        return *this;
    }

    Rational &Rational::operator/=(const Rational &other) noexcept(false) {
        return *this *= !other;
    }

    Rational operator+(const Rational &a, const Rational &b) noexcept(false) {
        Rational r(0);
        r += a;
        r += b;
        return r;
    }

    Rational operator-(const Rational &a, const Rational &b) noexcept(false) { return a + -b; }

    Rational operator*(const Rational &a, const Rational &b) noexcept(false) {
        Rational r(1);
        r *= a;
        r *= b;
        return r;
    }

    Rational operator/(const Rational &a, const Rational &b) noexcept(false) { return a * !b; }

    std::istream &operator>>(std::istream &in, Rational &r) {
        int a, b;
        in >> a >> b;
        r.setNum(a);
        r.setDen(b);
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Rational &r) {
        out << r.num << "/" << r.den;
        return out;
    }
} // namespace Calculations
