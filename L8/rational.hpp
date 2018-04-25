//
// Created by Tooster on 21.04.2018.
//

#ifndef CPP_RATIONAL_HPP
#define CPP_RATIONAL_HPP

#include <istream>

namespace Calculations {
    class Rational {
        int num, den;

        long long gcd(long long int a, long long int b) const;

    public:
        explicit Rational(int num = 0, int den = 1);

        Rational(const Rational &) = default;

        Rational &operator=(const Rational &) = default;

        int getNum() const;

        void setNum(int num);

        int getDen() const;

        void setDen(int den);

        std::string asDecimal();

        Rational operator-() const;

        Rational operator!() const noexcept(false);

        explicit operator int() const;

        explicit operator double() const;

        Rational &operator+=(const Rational &) noexcept(false);

        Rational &operator-=(const Rational &) noexcept(false);

        Rational &operator*=(const Rational &) noexcept(false);

        Rational &operator/=(const Rational &) noexcept(false);
        friend Rational operator+(const Rational &, const Rational &) noexcept(false);

        friend Rational operator-(const Rational &, const Rational &) noexcept(false);

        friend Rational operator*(const Rational &, const Rational &) noexcept(false);

        friend Rational operator/(const Rational &, const Rational &) noexcept(false);

        friend std::istream &operator>>(std::istream &in, Rational &r);

        friend std::ostream &operator<<(std::ostream &out, const Rational &r);
    };
} // namespace Calculations
#endif //CPP_RATIONAL_HPP
