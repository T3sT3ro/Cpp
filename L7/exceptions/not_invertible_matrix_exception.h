//
// Created by i300791 on 18.04.18.
//

#ifndef CPP_INVERSIBLE_MATRIX_EXCEPTION_H
#define CPP_INVERSIBLE_MATRIX_EXCEPTION_H

#include "matrix_exception.hpp"

namespace Calculations {
    class not_invertible_matrix_exception : public matrix_exception {
    public:
        not_invertible_matrix_exception() : matrix_exception("Given matrix cannot be inverted.") {}

        not_invertible_matrix_exception(const std::string &description) : matrix_exception(description) {}
    };
}
#endif //CPP_INVERSIBLE_MATRIX_EXCEPTION_H
