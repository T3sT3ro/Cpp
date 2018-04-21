//
// Created by Tooster on 21.04.2018.
//

#ifndef CPP_OUT_OF_RANGE_EXCEPTION_HPP
#define CPP_OUT_OF_RANGE_EXCEPTION_HPP

#include "rational_exception.hpp"

class out_of_range_exception : public rational_exception {
public:
    out_of_range_exception() : rational_exception("numerator or denominator outside of range") {}
};

#endif //CPP_OUT_OF_RANGE_EXCEPTION_HPP
