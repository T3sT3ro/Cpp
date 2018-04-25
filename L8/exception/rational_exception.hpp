//
// Created by Tooster on 21.04.2018.
//

#ifndef CPP_RATIONAL_EXCEPTION_HPP
#define CPP_RATIONAL_EXCEPTION_HPP

#include <exception>
#include <string>

class rational_exception : public std::exception {
    std::string details;
public:
    explicit rational_exception(const char *details) : std::exception() {
        rational_exception::details = "Rational number exception: ";
        rational_exception::details.append(details);
    }

    rational_exception() : details("") {}

    const char *what() const noexcept override { return details.c_str(); }
};

#endif //CPP_RATIONAL_EXCEPTION_HPP
