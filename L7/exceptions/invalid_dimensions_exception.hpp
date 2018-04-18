//
// Created by Tooster on 18.04.2018.
//

#ifndef CPP_INVALID_DIMENSIONS_EXCEPTION_HPP
#define CPP_INVALID_DIMENSIONS_EXCEPTION_HPP

#include "matrix_exception.hpp"

namespace Calculations {
    class invalid_dimensions_exception : public matrix_exception {
    public:
        invalid_dimensions_exception() : matrix_exception("Invalid matrix dimensions.") {}

        invalid_dimensions_exception(const std::string &description) : matrix_exception(description) {}
    };
}
#endif //CPP_INVALID_DIMENSIONS_EXCEPTION_HPP
