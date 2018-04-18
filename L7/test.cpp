//
// Created by Tooster on 18.04.2018.
//

#include "matrix.hpp"

using namespace Calculations;

int main() {
    Matrix m(7, 0.0);
    auto x = m * 8.0;
    auto y = 7.0 * m;
    auto j = m + m;
    auto k = m * m;
    auto l = m - m;
}
