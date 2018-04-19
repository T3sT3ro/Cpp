//
// Created by Tooster on 18.04.2018.
//

#include <iostream>
#include "matrix.hpp"
#include "exceptions/invalid_scalar_exception.hpp"
#include "exceptions/not_square_matrix_exception.hpp"
#include "exceptions/not_invertible_matrix_exception.h"

using namespace Calculations;

int main() {
    Matrix m(7, 0.0);
    Matrix m2(3, 3.0);
    Matrix m3(3, 5);
    auto x = m * 8.0;
    auto y = 7.0 * m;
    auto j = m + m;
    auto k = m * m;
    auto l = m - m;
    std::cout << m;
    std::cout << m2;
    try { auto e = m * m2; } catch (invalid_dimensions_exception &e) { std::cout << "COUGHT: " << e.what() << "\n"; }
    try { Matrix e(-3, 6); } catch (invalid_dimensions_exception &e) { std::cout << "COUGHT: " << e.what() << "\n"; }
    try { m.colMult(1, 0); } catch (invalid_scalar_exception &e) { std::cout << "COUGHT: " << e.what() << "\n"; }
    try { m3.det(); } catch (not_square_matrix_exception &e) { std::cout << "COUGHT: " << e.what() << "\n"; }
    m2.set(1, 1, 5).set(1, 2, 6).set(1, 3, 7);
    m2.set(2, 1, 9).set(2, 2, 3).set(2, 3, 2);
    m2.set(3, 1, 2).set(3, 2, 0).set(3, 3, 0);
    std::cout << m2;
    std::cout << m2.det() << "\n";
    std::cout << m2.complement(3, 2).det() << "\n";
    std::cout << m2.complement(3, 2) << "\n";
    m2.colSwap(1, 3);
    Matrix f(3, 3);
    std::cout << "Input 3x3 matrix:\n";
    std::cin >> f;
    std::cout << "Matrix: \n" << f << "\n";
    std::cout << "f determinant: \n" << f.det() << "\n";
    try { std::cout << "f inverse: \n" << f.inverse() << "\n"; } catch (not_invertible_matrix_exception &e) {
        std::cout << "COUGHT: " << e.what() << "\n";
    }
    std::cout << "Transpose: \n" << f.transposition() << "\n";
    std::cout << "Scalar 5 multiply 1st row: \n" << f.rowMult(1, 5) << "\n";
    std::cout << "Swap 1<->3 : \n" << f.rowSwap(1, 3) << "\n";
    std::cout << "add 2* second to 1st row: \n" << f.rowAdd(1, 2, 2) << "\n";

}
