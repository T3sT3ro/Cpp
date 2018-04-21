//
// Created by Tooster on 21.04.2018.
//

#ifndef CPP_ZERO_DENOMINATOR_EXCEPTION_HPP
#define CPP_ZERO_DENOMINATOR_EXCEPTION_HPP

#include "rational_exception.hpp"

class zero_denominator_exception : public rational_exception {
public:
    zero_denominator_exception() : rational_exception("zero in denominator") {}
};

#endif //CPP_ZERO_DENOMINATOR_EXCEPTION_HPP
