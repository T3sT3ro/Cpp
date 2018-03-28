//
// Created by Tooster on 17.03.2018.
//

#ifndef CPP_TAB_BIT_H
#define CPP_TAB_BIT_H


#include <cstdint>
#include <ostream>
#include <istream>

class tab_bit {
    typedef unsigned long long word; // komorka w tablicy
    static const int wordSize = sizeof(word) * 8; // rozmiar slowa w bitach
    class ref {
        tab_bit *_tab_bit_ptr; // pointer to original bitset
        int _index; // index of bit in bitset
    public:
        ref(tab_bit *t, int i);

        ref &operator=(bool val);

        ref &operator=(const ref &val);

        operator bool() const;

    }; // klasa pomocnicza do adresowania bitów
protected:
    int _size; // liczba bitów
    int _wordCount; // ilosc slow
    word *_tab; // tablica bitów
public:
    explicit tab_bit(int size); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit(word s); // tablica bitów [0...rozmiarSlowa]
// zainicjalizowana wzorcem
    tab_bit(const tab_bit &other); // konstruktor kopiujący
    tab_bit(tab_bit &&other) noexcept; // konstruktor przenoszący
    tab_bit(std::initializer_list<bool> l);

    tab_bit &operator=(const tab_bit &other); // przypisanie kopiujące
    tab_bit &operator=(tab_bit &&other) noexcept; // przypisanie przenoszące
    ~tab_bit(); // destruktor
private:
    bool read(int i) const; // metoda pomocnicza do odczytu bitu
    bool write(int i, bool b); // metoda pomocnicza do zapisu bitu
public:
    bool operator[](int i) const; // indeksowanie dla stałych tablic bitowych
    ref operator[](int i); // indeksowanie dla zwykłych tablic bitowych
    inline int size() const; // rozmiar tablicy w bitach
public:
// operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
    tab_bit operator~();

    tab_bit &operator|=(const tab_bit &other);

    tab_bit &operator&=(const tab_bit &other);

    tab_bit &operator^=(const tab_bit &other);

    friend tab_bit operator|(tab_bit lhs, const tab_bit &rhs);

    friend tab_bit operator&(tab_bit lhs, const tab_bit &rhs);

    friend tab_bit operator^(tab_bit lhs, const tab_bit &rhs);

public:
// zaprzyjaźnione operatory strumieniowe: << i >>
    friend std::istream &operator>>(std::istream &we, tab_bit &tb);

    friend std::ostream &operator<<(std::ostream &wy, const tab_bit &tb);
};

#endif //CPP_TAB_BIT_H
