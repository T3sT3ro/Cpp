//
// Created by Tooster on 30.05.2018.
//

#ifndef CPP_MANIPULATORS_HPP
#define CPP_MANIPULATORS_HPP

#include <iostream>
#include <iomanip>
#include <ios>
#include <fstream>

using namespace std;

namespace streams {
/// clears stream until \n (inclusive) or EOF
    inline istream &clearline(istream &is) {

        while (is && is.get() != '\n');
        return is;
    }

/// ignores n characters
    class ignore {
        int cnt;
    public:
        ignore(int cnt) : cnt(cnt) {} // + 1 to read las character

        friend istream &operator>>(istream &is, ignore ig) {
            while (is && ig.cnt-- && is.get() != '\n'); // cycle through chars
            return is;
        }
    };

    inline ostream &comma(ostream &os) {
        if (os)
            os << ", ";
        return os;
    }

    inline ostream &colon(ostream &os) {
        if (os)
            os << ": ";
        return os;
    }

    class index {
        int x, w;
    public:
        index(int x, int w) : x(x), w(w) {}

        friend ostream &operator<<(ostream &os, index ig) {
            if (!os)
                return os;
            os << '[';
            os.fill('0');
            os.width(ig.w);
            os << right << ig.x << ']';
            return os;
        }
    };


    class ibfstream {
    public:
        ifstream ifs;

        ibfstream(char *filename) {
            ifs.exceptions(ios_base::failbit | ios_base::badbit);
            ifs.open(filename, ios_base::in | ios_base::binary);
        }

        virtual ~ibfstream() {
            ifs.close();
        }

        bool operator!() { return !ifs; }

        friend ibfstream &operator>>(ibfstream &ibfs, int &x) {
            ibfs.ifs.read((char *) &x, 1);
            return ibfs;
        }
    };

    class obfstream {
    public:
        ofstream ofs;

        obfstream(char *filename) {
            ofs.exceptions(ios_base::failbit | ios_base::badbit);
            ofs.open(filename, ios_base::out | ios_base::binary);
        }

        virtual ~obfstream() {
            ofs.close();
        }

        bool operator!() { return !ofs; }

        friend obfstream &operator<<(obfstream &obfs, const int x) {
            obfs.ofs.write((char *) &x, 1);
            return obfs;
        }
    };
} // namespace streams

#endif //CPP_MANIPULATORS_HPP
