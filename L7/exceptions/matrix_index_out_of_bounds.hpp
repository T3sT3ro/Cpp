//
// Created by Tooster on 18.04.2018.
//

#ifndef CPP_INVALID_MATRIX_ROW_COLUMN_INDEX_HPP
#define CPP_INVALID_MATRIX_ROW_COLUMN_INDEX_HPP

#include "matrix_exception.hpp"

namespace Calculations {
    class matrix_index_out_of_bounds : public matrix_exception {
    public:
        matrix_index_out_of_bounds() : matrix_exception("Invalid matrix index") {}
    };
}
#endif //CPP_INVALID_MATRIX_ROW_COLUMN_INDEX_HPP
