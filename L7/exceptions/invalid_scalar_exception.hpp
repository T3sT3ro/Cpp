//
// Created by Tooster on 18.04.2018.
//

#ifndef CPP_INVALID_SCALAR_EXCEPTION_HPP
#define CPP_INVALID_SCALAR_EXCEPTION_HPP

#include "matrix_exception.hpp"

namespace Calculations {
    class invalid_scalar_exception : public matrix_exception {
    public:
        invalid_scalar_exception() : matrix_exception("Invalid scalar in operation.") {}

        invalid_scalar_exception(const std::string &description) : matrix_exception(description) {}
    };
}
#endif //CPP_INVALID_SCALAR_EXCEPTION_HPP
