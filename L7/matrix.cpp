//
// Created by Tooster on 18.04.2018.
//

#include "utility"
#include "matrix.hpp"
#include "exceptions/matrix_index_out_of_bounds.hpp"
#include "exceptions/invalid_scalar_exception.hpp"
#include "exceptions/not_square_matrix_exception.hpp"

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

    Matrix &Matrix::rowSwap(const int i, int j) noexcept(false) {
        if(i < 0 || i >= rows || j < 0 || j >= rows)
            throw matrix_index_out_of_bounds();
        if(i == j) return *this;
        std::swap(tab[i],tab[j]);
        return *this;
    }

    Matrix &Matrix::rowMult(int i, double scalar) noexcept(false) {
        if(i < 0 || i >= rows)
            throw matrix_index_out_of_bounds();
        if(scalar == 0)
            throw invalid_scalar_exception();
        if(scalar == 1) return *this;
        for (int col = 0; col < columns; ++col)
            tab[i][col] *= scalar;
        return *this;
    }

    Matrix &Matrix::rowAdd(int to, int from, double scalar) noexcept(false) {
        if (to < 0 || to >= rows || from < 0 || from >= rows)
            throw matrix_index_out_of_bounds();
        if (scalar == 0) return *this;
        for (int col = 0; col < columns; ++col)
            tab[to][col] += tab[from][col] * scalar;
    }

    Matrix &Matrix::colSwap(const int i, int j) noexcept(false) {
        if(i < 0 || i >= columns || j < 0 || j >= columns)
            throw matrix_index_out_of_bounds();
        if(i == j) return *this;
        for (int row = 0; row < rows; ++row)
            std::swap(tab[row][i],tab[row][j]);
        return *this;
    }

    Matrix &Matrix::colMult(int i, double scalar) noexcept(false) {
        if(i < 0 || i >= columns)
            throw matrix_index_out_of_bounds();
        if(scalar == 0)
            throw invalid_scalar_exception();
        if(scalar == 1) return *this;
        for (int row = 0; row < rows; ++row)
            tab[row][i] *= scalar;
        return *this;
    }

    Matrix &Matrix::colAdd(int to, int from, double scalar) noexcept(false) {
        if (to < 0 || to >= columns || from < 0 || from >= columns)
            throw matrix_index_out_of_bounds();
        if (scalar == 0) return *this;
        for (int row = 0; row < rows; ++row)
            tab[row][to] += tab[row][from] * scalar;
    }

    Matrix Matrix::complement(int row, int column) noexcept(false) {
        if (row < 0 || row >= rows || column < 0 || column >= columns)
            throw matrix_index_out_of_bounds();
        if (rows == 1 || columns == 1)
            throw matrix_exception("Cannot create complement if one of dimensions is 1.");
        Matrix ret(rows-1, columns-1);
        for (int rowidx = 0, r=0; rowidx < rows; ++rowidx) {
            if (rowidx + 1 != row) {
                for (int colidx = 0, c = 0; colidx < columns; ++colidx) {
                    if(colidx+1 != c){
                        ret.tab[r][c] = tab[rowidx][colidx];
                        c++;
                    }
                }
                r++;
            }
        }
    }

    double Matrix::det() noexcept(false) {
        if(columns != rows)
            throw not_square_matrix_exception();
        if(columns == 2) return tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0];
        if(columns == 3) return tab[0][0]*tab[1][1]*tab[2][2]+tab[0][1]*tab[1][2]*tab[2][0]+tab[0][2]*tab[1][0]*tab[2][1]
                    - tab[2][0]*tab[1][1]*tab[0][2]-tab[2][1]*tab[1][2]*tab[0][0]-tab[2][2]*tab[1][0]*tab[0][1];
        double ret = 0;
        for (int i = 0; i < columns; ++i)
            ret += (-1) * (i%2)*tab[0][i]*this->complement(0,i).det();
        return ret;
     }

//    std::istream &Matrix::operator>>(std::istream &we, Matrix &m) {
//        static int cntr = 0;
//        we >> m.tab[cntr/columns][cntr%columns];
//        return <#initializer#>;
//    }



    // @formatter:on

} // namespace Calculations