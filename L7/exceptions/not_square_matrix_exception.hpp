//
// Created by Tooster on 18.04.2018.
//

#ifndef CPP_NOT_SQUARE_MATRIX_EXCEPTION_HPP
#define CPP_NOT_SQUARE_MATRIX_EXCEPTION_HPP

#include "matrix_exception.hpp"

namespace Calculations {
    class not_square_matrix_exception : public matrix_exception {
    public:
        not_square_matrix_exception() : matrix_exception("Square matrix required, given rectangular") {}
    };
}
#endif //CPP_NOT_SQUARE_MATRIX_EXCEPTION_HPP
