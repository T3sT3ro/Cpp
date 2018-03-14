//
// Created by Tooster on 13.03.2018.
//

#include <iostream>
#include <stdexcept>
#include "stos.hpp"

bool doTests() {
    auto equal = [](Stack a, Stack b) -> bool {
        if (a.capacity() != b.capacity() || a.size() != b.size())
            return false;
        auto s1 = a.getContent(), s2 = b.getContent();
        for (int i = 0; i < a.capacity(); ++i) if (s1[i] != s2[i]) return false;
        return true;
    };
    Stack s1, s2(10);
    if (s1.size() != 0 || s1.capacity() != 1) return false;
    if (s2.size() != 0 || s2.capacity() != 10) return false;

    Stack s3 = {"1", "2", "3", "4", "5", "6"};
    if (s3.size() != 6 || s3.capacity() != 6) return false;

    Stack s4 = s3; // copy ass ctor
    if (!equal(s4, s3)) return false;

    s1 = s3; // copy op;
    if (!equal(s1, s3)) return false;

    Stack s5 = std::move(s4); // rvalue ctor
    if (!equal(s5, s3)) return false;

    {
        Stack s_scope = {"a", "b"};
        s5 = std::move(s_scope); // rvalue op
    }
    if (!equal(s5, {"a", "b"})) return false;
    return true;
}


int main() {
    if (!doTests()) {
        std::cerr << "TESTS FAILURE" << std::endl;
        return 1;
    }
    auto *s = new Stack(16);
    std::string op = "?";
    do {
        try {
            std::string arg;
            if (op == "?") {
                std::cout << "Interactive stack sandbox"        "\n"
                        "  ? - this help"                       "\n"
                        "  x - exit"                            "\n"
                        "  push <x> - push x onto stack"        "\n"
                        "  top - return top element"            "\n"
                        "  pop <x> - pop the top and print it"  "\n"
                        "  cap - returns capacity of the stack" "\n"
                        "  size - returns currently used space" "\n"
                        "  pf - prints content of the stack"    "\n";
            } else if (op == "push") {
                std::cin >> arg;
                s->push(arg);
            } else if (op == "top") {
                auto str = s->top();
                std::cout << "top: [" << str << "]  [" << s->size() << "/" << s->capacity() << "]\n";
            } else if (op == "pop") {
                auto str = s->pop();
                std::cout << "popped: [" << str << "]  [" << s->size() << "/" << s->capacity() << "]\n";
            } else if (op == "cap" || op == "size") {
                std::cout << "[" << s->size() << "/" << s->capacity() << "]\n";
            } else if (op == "pf") {
                auto insides = s->getContent();
                std::cout << "[" << s->size() << "/" << s->capacity() << "]\n";
                for (int i = s->size() - 1; i >= 0; --i)
                    std::cout << ((i == s->size() - 1) ? "^ " : "| ") << "[" << insides[i] << "]\n";
                if (s->size() == 0) std::cout << "[EMPTY]\n";
            }
        } catch (std::runtime_error &e) {
            std::cerr << "STACK ERROR: " << e.what() << "\n";
            std::cerr.flush();
        }
        std::cout.flush();
        std::cin >> op;
    } while (op != "x");
    delete (s);
}
