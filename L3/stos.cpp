//
// Created by Tooster on 13.03.2018.
//

#include <stdexcept>
#include "stos.h"

Stack::Stack(int capacity) : _capacity(capacity), _size(0) {
    _container = new std::string[capacity];
}

Stack::Stack() : Stack(1) {}

Stack::Stack(std::initializer_list<std::string> l) : _capacity(static_cast<int>(l.size())), _size(0) {
    _container = new std::string[_capacity];
    for (auto &s : l)
        _container[_size++] = s;
}

Stack::Stack(Stack const &s) : _capacity(s._capacity), _size(s._size) {
    _container = new std::string[_capacity];
    for (int i = 0; i < _size; ++i)
        _container[i] = s._container[i]; // assume that the object has copy assignment operator
}

Stack::Stack(Stack &&s) noexcept : _capacity(s._capacity), _size(s._size), _container(s._container) {
    s._container = nullptr;
}

Stack &Stack::operator=(Stack const &s) {
    if (&s == this)
        return *this;

    Stack tmp(s);
    *this = std::move(tmp);
    return *this;
}

Stack &Stack::operator=(Stack &&s) noexcept {
    this->~Stack();
    _capacity = s._capacity;
    _size = s._size;
    _container = s._container;
    s._container = nullptr; // clearing other object cuz it will run destructor in a while
    return *this;
}

void Stack::push(const std::string &s) {
    if (_size == _capacity) throw std::runtime_error("Stack is full, cannot push new value.");
    _container[_size++] = s;
}

std::string Stack::pop() {
    if (_size == 0) throw std::runtime_error("Stack is empty, cannot pop.");
    return _container[--_size];
}

std::string Stack::top() const {
    if (_size == 0) throw std::runtime_error("Stack is empty, cannot return top.");
    return _container[_size - 1];
}

int Stack::size() const {
    return _size;
}

int Stack::capacity() const {
    return _capacity;
}

const std::string *Stack::getContent() const {
    return _container;
}
