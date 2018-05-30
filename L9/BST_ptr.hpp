//
// Created by i300791 on 23.05.18.
//

#ifndef CPP_BST_PTR_HPP_HPP
#define CPP_BST_PTR_HPP_HPP

#include "BST_base.hpp"
#include <initializer_list>
#include <iostream>
#include <functional>

namespace structs {
    template<typename T, typename Compare>
    class Bst<T *, Compare> : Bst<T, Compare> {
    public:
        friend std::ostream &operator<<(std::ostream &out, const Bst<T *, Compare> &bst) {
            out << bst;
            return out;
        }
    };

    template<typename T>
    class Bst<T *> : public Bst<T *, std::less_equal<T> > {
    public:
        Bst() : Bst<T, std::less_equal<T>>() {}
    };

    template<typename T>
    struct deref {
        bool operator()(const T *t1, const T *t2) { return *t1 <= *t2; }
    };

    template<typename T>
    class Bst<T *> : public Bst<const char *, deref> {
    public:
        Bst() : Bst<const char *, deref>() {};

        Bst(std::initializer_list<const char *> list) : Bst<const char *, deref>(list) {}
    };
} // namespace structs

#endif //CPP_BST_PTR_HPP_HPP
