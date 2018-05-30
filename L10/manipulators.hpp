//
// Created by Tooster on 30.05.2018.
//

#ifndef CPP_MANIPULATORS_HPP
#define CPP_MANIPULATORS_HPP

#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;

namespace ttr {
/// clears stream until \n (inclusive) or EOF
    inline istream &clearline(istream &is) {

        while (!is.eof() && is.get() != '\n');
        return is;
    }

/// ignores n characters
    class ignore {
        int cnt;
    public:
        ignore(int cnt) : cnt(cnt) {} // + 1 to read las character

        friend istream &operator>>(istream &is, ignore ig) {
            while (!is.eof() && ig.cnt-- && is.get() != '\n'); // cycle through chars
            return is;
        }
    };

    inline ostream &comma(ostream &os) {
        os << ", ";
        return os;
    }

    inline ostream &colon(ostream &os) {
        os << ": ";
        return os;
    }

    class index {
        int x, w;
    public:
        index(int x, int w) : x(x), w(w) {}

        friend ostream &operator<<(ostream &os, index ig) {
            os << '[';
            os.fill('0');
            os.width(ig.w);
            os << right << ig.x << ']';
        }
    };


} // namespace ttr

#endif //CPP_MANIPULATORS_HPP
