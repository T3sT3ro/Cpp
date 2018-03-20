//
// Created by Tooster on 17.03.2018.
//

#include "tabbit.hpp"


tab_bit::tab_bit(int size) : _size(size), _wordCount((size + (wordSize - 1)) / wordSize) {
    if (size < 1) throw std::runtime_error("Invalid tab_bit size.");
    _tab = new word[wordSize];
    for (int i = 0; i < _wordCount; ++i) _tab[i] = 0;
}

tab_bit::tab_bit(tab_bit::word s) : tab_bit(wordSize) { _tab[0] = s; }

tab_bit::tab_bit(const tab_bit &other) : _size(other._size), _wordCount(other._wordCount) {
    if (&other == this) return;
    _tab = new word[_wordCount];
    for (int i = 0; i < _wordCount; ++i) _tab[i] = 0;
    for (int i = 0; i < _wordCount; ++i)
        _tab[i] = other._tab[i];
}

tab_bit::tab_bit(tab_bit &&other) noexcept: _size(other._size), _wordCount(other._wordCount), _tab(other._tab) {
    other._wordCount = other._size = 0;
    other._tab = nullptr;
}

tab_bit::tab_bit(std::initializer_list<bool> l) : _size(static_cast<int>(l.size())),
                                                  _wordCount((_size + (wordSize - 1)) / wordSize) {
    _tab = new word[_wordCount];
    for (int i = 0; i < _wordCount; ++i) _tab[i] = 0;
    int i = 0;
    for (auto b : l)
        this->write(i++, static_cast<bool>(b));
}

tab_bit &tab_bit::operator=(const tab_bit &other) {
    if (&other == this) return *this;
    tab_bit _tmp(other);
    *this = std::move(_tmp);
    return *this;
}

tab_bit &tab_bit::operator=(tab_bit &&other) noexcept {
    this->~tab_bit();
    _size = other._size;
    _wordCount = other._wordCount;
    _tab = other._tab;
    other._wordCount = other._size = 0;
    other._tab = nullptr;
    return *this;
}

tab_bit::~tab_bit() {
    delete[] _tab;
}

bool tab_bit::read(int i) const {
    if (i < 0 || i > _size) throw std::runtime_error("Cannot access tab_bit: index out of bounds.");
    return static_cast<bool>(_tab[i / wordSize] & (1ull << (i % wordSize)));
}

bool tab_bit::write(int i, bool b) {
    if (i < 0 || i > _size) throw std::runtime_error("Cannot access tab_bit: index out of bounds.");
    _tab[i / wordSize] =
            (_tab[i / wordSize] & ~(1ull << (i % wordSize))) | ((unsigned long long) (b) << (i % wordSize));
    return b;
}

bool tab_bit::operator[](int i) const {
    return (_tab[i / wordSize] & (1ull << (i % wordSize))) != 0;
}

tab_bit::ref tab_bit::operator[](int i) {
    return tab_bit::ref(this, i);
}

int tab_bit::size() const {
    return _size;
}

std::istream &operator>>(std::istream &we, tab_bit &_tab_bit) {
    std::string bitstream;
    we >> bitstream;
    for (int i = 0; i < bitstream.length(); ++i)
        _tab_bit[i] = bitstream[i] - '0';
    return we;
}

std::ostream &operator<<(std::ostream &wy, const tab_bit &_tab_bit) {
    for (int i = 0; i < _tab_bit._size; ++i)
        wy << (_tab_bit[i] ? '1' : '0');
    return wy;
}

tab_bit tab_bit::operator~() {
    tab_bit result(*this);
    for (int i = 0; i < _wordCount; ++i) result._tab[i] = ~_tab[i];
    return result;
}

tab_bit &tab_bit::operator|=(const tab_bit &other) {
    for (int i = 0; i < _wordCount; ++i)
        if (i < other._wordCount) _tab[i] |= other._tab[i];
    return *this;
}

tab_bit &tab_bit::operator&=(const tab_bit &other) {
    for (int i = 0; i < _wordCount; ++i)
        if (i < other._wordCount) _tab[i] &= other._tab[i];
        else _tab[i] = 0;
    return *this;
}

tab_bit &tab_bit::operator^=(const tab_bit &other) {
    for (int i = 0; i < _wordCount; ++i)
        if (i < other._wordCount) _tab[i] ^= other._tab[i];
    return *this;
}

tab_bit operator|(tab_bit lhs, const tab_bit &rhs) {
    lhs |= rhs;
    return lhs;
}

tab_bit operator&(tab_bit lhs, const tab_bit &rhs) {
    lhs &= rhs;
    return lhs;
}

tab_bit operator^(tab_bit lhs, const tab_bit &rhs) {
    lhs ^= rhs;
    return lhs;
}


tab_bit::ref::ref(tab_bit *t, int i) : _tab_bit_ptr(t), _index(i) {}

tab_bit::ref &tab_bit::ref::operator=(bool val) {
    _tab_bit_ptr->write(_index, val);
    return *this;
}

tab_bit::ref &tab_bit::ref::operator=(const tab_bit::ref &val) {
    _tab_bit_ptr->write(_index, val);
    return *this;
}

tab_bit::ref::operator bool() const {
    return _tab_bit_ptr->read(_index);
}
