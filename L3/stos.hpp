//
// Created by Tooster on 13.03.2018.
//

#ifndef CPP_STOS_H
#define CPP_STOS_H

#include <string>

class Stack {
private:
    int _size;
    int _capacity;
    std::string *_container;
public:

    explicit Stack(int capacity); // size
    Stack(); // empty, delegate
    Stack(std::initializer_list<std::string> l); // {1,2,...}
    Stack(Stack const &s); // copy
    Stack(Stack &&s) noexcept; // move

    Stack &operator=(Stack const &s); // copy ass
    Stack &operator=(Stack &&s) noexcept; // move ass

    ~Stack();

    void push(const std::string &s);

    std::string pop();

    std::string top() const;

    int size() const;

    int capacity() const;

    const std::string *getContent() const;

};


#endif //CPP_STOS_H
