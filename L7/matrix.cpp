//
// Created by Tooster on 18.04.2018.
//

#include "matrix.hpp"
#include <utility>
#include <cmath>
#include "exceptions/matrix_index_out_of_bounds.hpp"
#include "exceptions/invalid_scalar_exception.hpp"
#include "exceptions/not_square_matrix_exception.hpp"
#include "exceptions/not_invertible_matrix_exception.h"

namespace Calculations {
    Matrix::Matrix(const int size, double var) : rows(size), columns(size) {
        if (rows < 0 || columns < 0) throw invalid_dimensions_exception("Dimensions cannot be negative");
        tab = new double *[size];
        for (int i = 0; i < size; ++i) {
            tab[i] = new double[size];
            for (int j = 0; j < size; ++j)
                tab[i][j] = i == j ? var : 0;
        }
    }

    Matrix::Matrix(const int rows, const int columns) : rows(rows), columns(columns) {
        if (rows <= 0 || columns <= 0) throw invalid_dimensions_exception("Dimensions must be positive");
        tab = new double *[rows];
        for (int i = 0; i < rows; ++i)
            tab[i] = new double[columns]();
    }

    Matrix::Matrix(Matrix &&other) noexcept : rows(other.rows), columns(other.columns) {
        tab = other.tab;
        other.tab = nullptr;
    }

    Matrix::Matrix(const Matrix &other) : Matrix(other.rows, other.columns) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                tab[i][j] = other.tab[i][j];
    }

    Matrix::~Matrix() {
        if (tab != nullptr) {
            for (int i = 0; i < rows; ++i)
                delete tab[i];
            delete[] tab;
            tab = nullptr;
        }
    }

    Matrix &Matrix::operator=(const Matrix &other) {
        if (&other == this) return *this;
        Matrix _tmp(other);
        *this = std::move(_tmp);
        return *this;
    }

    Matrix &Matrix::operator=(Matrix &&other) noexcept {
        this->~Matrix();
        rows = other.rows;
        columns = other.columns;
        tab = other.tab;
        other.tab = nullptr;
        return *this;
    }


    Matrix Matrix::operator*(const double scalar) const noexcept {
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < columns; ++col)
                tab[row][col] *= scalar;
        return *this;
    }

    Matrix &Matrix::operator+=(const Matrix &other) noexcept(false) {
        if (rows != other.rows || columns != other.columns)
            throw invalid_dimensions_exception("Cannot add matrices of different dimensions.");
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < columns; ++col)
                tab[row][col] += other.tab[row][col];
        return *this;
    }

    Matrix &Matrix::operator*=(const Matrix &other) noexcept(false) {
        if (columns != other.rows || rows != other.columns)
            throw invalid_dimensions_exception("Cannot multiply matrices of different dimensions.");
        Matrix ret(rows, other.columns);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                for (int k = 0; k < other.columns; ++k)
                    ret.tab[i][k] += tab[i][j] * tab[j][k];
        *this = std::move(ret);
        return *this;
    }

    Matrix &Matrix::operator-=(const Matrix &other) noexcept(false) {
        return *this += (-1.0) * other;
    }

    // @formatter:off
    Matrix operator+(const Matrix &m1, const Matrix &m2) noexcept(false) { return Matrix(m1) += m2; }

    Matrix operator-(const Matrix &m1, const Matrix &m2) noexcept(false) { return m1 + (-1.0) * m2; }

    Matrix operator*(const Matrix &m1, const Matrix &m2) noexcept(false) { return Matrix(m1) *= m2; }

    Matrix operator*(double scalar, const Matrix &m1) noexcept { return m1.operator*(scalar); }

    Matrix Matrix::transposition() noexcept {
        Matrix r(columns, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                r.tab[j][i] = tab[i][j];
        return r;
    }

    Matrix &Matrix::rowSwap(int i, int j) noexcept(false) {
        --i;
        --j;
        if (i < 0 || i >= rows || j < 0 || j >= rows)
            throw matrix_index_out_of_bounds();
        if (i == j) return *this;
        std::swap(tab[i], tab[j]);
        return *this;
    }

    Matrix &Matrix::rowMult(int i, double scalar) noexcept(false) {
        --i;
        if (i < 0 || i >= rows)
            throw matrix_index_out_of_bounds();
        if (scalar == 0)
            throw invalid_scalar_exception();
        if (scalar == 1) return *this;
        for (int col = 0; col < columns; ++col)
            tab[i][col] *= scalar;
        return *this;
    }

    Matrix &Matrix::rowAdd(int to, int from, double scalar) noexcept(false) {
        --to;
        --from;
        if (to < 0 || to >= rows || from < 0 || from >= rows)
            throw matrix_index_out_of_bounds();
        if (scalar == 0) return *this;
        for (int col = 0; col < columns; ++col)
            tab[to][col] += tab[from][col] * scalar;
        return *this;
    }

    Matrix &Matrix::colSwap(int i, int j) noexcept(false) {
        --i;
        --j;
        if (i < 0 || i >= columns || j < 0 || j >= columns)
            throw matrix_index_out_of_bounds();
        if (i == j) return *this;
        for (int row = 0; row < rows; ++row)
            std::swap(tab[row][i], tab[row][j]);
        return *this;
    }

    Matrix &Matrix::colMult(int i, double scalar) noexcept(false) {
        --i;
        if (i < 0 || i >= columns)
            throw matrix_index_out_of_bounds();
        if (scalar == 0)
            throw invalid_scalar_exception();
        if (scalar == 1) return *this;
        for (int row = 0; row < rows; ++row)
            tab[row][i] *= scalar;
        return *this;
    }

    Matrix &Matrix::colAdd(int to, int from, double scalar) noexcept(false) {
        --to;
        --from;
        if (to < 0 || to >= columns || from < 0 || from >= columns)
            throw matrix_index_out_of_bounds();
        if (scalar == 0) return *this;
        for (int row = 0; row < rows; ++row)
            tab[row][to] += tab[row][from] * scalar;
        return *this;
    }

    Matrix Matrix::complement(int row, int col) const noexcept(false) {
        --row;
        --col;
        if (row < 0 || row >= rows || col < 0 || col >= columns)
            throw matrix_index_out_of_bounds();
        if (rows == 1 || columns == 1)
            throw matrix_exception("Cannot create complement if one of dimensions is 1.");
        Matrix ret(rows - 1, columns - 1);
        for (int rowidx = 0, r = 0; rowidx < rows; ++rowidx) {
            if (rowidx != row) {
                for (int colidx = 0, c = 0; colidx < columns; ++colidx) {
                    if (colidx != col) {
                        ret.tab[r][c] = tab[rowidx][colidx];
                        c++;
                    }
                }
                r++;
            }
        }
        return ret;
    }

    double Matrix::det() const noexcept(false) {
        if (columns != rows)
            throw not_square_matrix_exception();
        if (columns == 2) return tab[0][0] * tab[1][1] - tab[0][1] * tab[1][0];
        if (columns == 3)
            return tab[0][0] * tab[1][1] * tab[2][2] + tab[0][1] * tab[1][2] * tab[2][0] +
                   tab[0][2] * tab[1][0] * tab[2][1]
                   - tab[2][0] * tab[1][1] * tab[0][2] - tab[2][1] * tab[1][2] * tab[0][0] -
                   tab[2][2] * tab[1][0] * tab[0][1];
        double ret = 0;
        for (int i = 0; i < columns; ++i)
            ret += (i % 2 == 0 ? 1 : -1) * tab[0][i] * this->complement(0, i).det();
        return ret;
    }

    std::istream &operator>>(std::istream &in, Matrix &m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.columns; ++j) {
                std::string s;
                in >> s;
                m.tab[i][j] = std::stod(s);
            }
        }
        return in;
    }

    std::ostream &operator<<(std::ostream &stream, const Matrix &m) {
        stream << std::string("{");
        for (int i = 0; i < m.rows; ++i) {
            stream << std::string("{");
            for (int j = 0; j < m.columns; ++j) {
                stream << std::to_string(m.tab[i][j]);
                if (j != m.columns - 1) stream << std::string(", ");
            }
            stream << std::string("}");
            if (i != m.rows - 1) stream << std::string(",\n");
        }
        stream << std::string("}\n");

        return stream;
    }

    int Matrix::getRows() const { return rows; }

    int Matrix::getColumns() const { return columns; }

    double Matrix::get(int row, int col) const {
        --col;
        --row;
        if (row < 0 || row >= rows || col < 0 || col >= columns)
            throw matrix_index_out_of_bounds();
        return tab[row][col];

    }

    Matrix &Matrix::set(int row, int col, double val) {
        --col;
        --row;
        if (row < 0 || row >= rows || col < 0 || col >= columns)
            throw matrix_index_out_of_bounds();
        tab[row][col] = val;
        return *this;
    }

    Matrix Matrix::inverse() const noexcept(false) {
        if (rows != columns)
            throw not_square_matrix_exception("Cannot calculate inverse of rectangular matrix");
        double _det = this->det();
        if (std::fabs(_det - 0.0) < 1e-32)
            throw not_invertible_matrix_exception();
        Matrix ret(*this);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
                ret.set(j + 1, i + 1, ((i + j) % 2 == 0 ? 1 : -1) * this->complement(i + 1, j + 1).det());
        return ret * (1 / _det);
    }





    // @formatter:on

} // namespace Calculations