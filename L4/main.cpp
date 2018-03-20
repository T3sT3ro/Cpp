//
// Created by Tooster on 20.03.2018.
//

#include <iostream>
#include "tabbit.hpp"

int main() {
    tab_bit t(46); // tablica 46-bitowa (zainicjalizowana zerami)
    tab_bit u(45ull); // tablica 64-bitowa (sizeof(uint64_t)*8)
    tab_bit v(t); // tablica 46-bitowa (skopiowana z t)
    tab_bit w({1, 0, 1, 1, 0, 0, 0, 1}); // tablica 8-bitowa (przeniesiona)
    v[0] = 1; // ustawienie bitu 0-go bitu na 1
    t[45] = true; // ustawienie bitu 45-go bitu na 1
    bool b = v[1]; // odczytanie bitu 1-go
    u[45] = u[46] = u[63] = 1; // przepisanie bitu 63-go do bitow 45-go i 46-go
    std::cout << "bit addressing:\n" "t:" << t << "\nu:" << u << "\nv:" << v << "\nw:" << w << "\n";
    u = std::move(v);
    std::cout << "after move:\n" "u:" << u << "\nv:" << v << "\n";

    tab_bit x(90);
    x[0] = x[1] = x[2] = x[4] = x[8] = x[16] = x[32] = x[64] = 1;
    std::cout << "x:  " << x << "\n";
    x = tab_bit(0x0000FFFF0000FFFFull);
    tab_bit m(0x00000000FFFFFFFFull);
    std::cout << "m:  " << m << "\n";
    std::cout << "x:  " << x << "\n";
    std::cout << "~x: " << (~x) << "\n";
    std::cout << "x&m:" << (x & m) << "\n";
    std::cout << "x|m:" << (x | m) << "\n";
    std::cout << "x^m:" << (x ^ m) << "\n";
    std::cout.flush();
    return 0;
}
