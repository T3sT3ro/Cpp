//
// Created by i300791 on 23.05.18.
//

#ifndef CPP_BST_CSTR_HPP
#define CPP_BST_CSTR_HPP

#include "BST_base.hpp"
#include <string>

namespace structs {
    template<class Compare>
    class Bst<const char *, Compare> : Bst<std::string, Compare> {
        typedef const char *Cstr;
    public:
        Bst() : Bst<std::string, Compare>() {}

        Bst(std::initializer_list<const char *> list) : Bst<std::string, Compare>() {
            for (auto elem : list)
                insert(elem);
        }

        void insert(Cstr elem) {
            Bst<std::string, Compare>::_insert(std::string(elem));
        }

        void remove(Cstr elem) {
            Bst<std::string, Compare>::_remove(std::string(elem));
        }

        bool find(Cstr elem) {
            return Bst<std::string, Compare>::_find(std::string(elem));
        }

        friend std::ostream &operator<<(std::ostream &out, const Bst<Cstr, Compare> &bst) {
            out << dynamic_cast<const Bst<std::string, Compare> &>(bst);
            return out;
        }
    };


    struct lexicographic {
        bool operator()(const std::string &s1, const std::string &s2) { // <=
            return s1 <= s2;
        }
    };

    template<>
    class Bst<const char *> : public Bst<const char *, lexicographic> {
    public:
        Bst() : Bst<const char *, lexicographic>() {};

        Bst(std::initializer_list<const char *> list) : Bst<const char *, lexicographic>(list) {}
    };


} // namespace structs

#endif //CPP_BST_CSTR_HPP
