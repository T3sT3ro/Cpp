//
// Created by Tooster on 18.04.2018.
//

#ifndef CPP_MATRIXEXCEPTION_HPP
#define CPP_MATRIXEXCEPTION_HPP


#include <exception>
#include <string>

namespace Calculations {
    class matrix_exception : public std::exception {
        std::string details;
    public:
        matrix_exception() { details = "Matrix exception"; }

        matrix_exception(const std::string &description) : details(description) {}

        const char *what() const noexcept override {
            return details.c_str();
        }
    };
} // namespace Calculations


#endif //CPP_MATRIXEXCEPTION_HPP
