//
// Created by Tooster on 04.03.2018.
//

#ifndef CPP_WEKTOR_H
#define CPP_WEKTOR_H


class Wektor {
public:
    const double dx = 0, dy = 0;

    Wektor() = default; // default
    Wektor(const double &dx, const double &dy); // coords
    Wektor(const Wektor &) = default; // copy constructor

    Wektor &operator=(const Wektor &) = delete; // delete copy assign

    static Wektor add(const Wektor &a, const Wektor &b);

    bool operator==(const Wektor &rhs) const;

    bool operator!=(const Wektor &rhs) const;
};


#endif //CPP_WEKTOR_H
