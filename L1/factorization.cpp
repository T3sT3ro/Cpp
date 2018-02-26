//
// Created by Tooster on 26.02.2018.
//

#include <iostream>
#include <vector>
#include <cmath>

constexpr long long LIMIT = 1 << 21;
int SITO[LIMIT];

/**
 * @brief Initializes primes sieve
 */
void _init() {
    SITO[1] = 1;
    for (int i = 2; i < LIMIT; i++)
        for (int j = i; j < LIMIT; j += i)
            if (SITO[j] == 0)
                SITO[j] = i;
}

/**
 * Checks primality of a number
 * @param x number to check
 * @return true iff number is a prime
 */
bool isPrime(int64_t x) {
    if (x < 2)
        return false;
    if (x < LIMIT)
        return SITO[(int) x] == x;
    else {
        if (x % 2 == 0) return false;
        for (int64_t i = 3; i <= (int64_t) std::sqrt(x) + 1; i += 2)
            if (x % i == 0)
                return false;
    }
    return true;
}

/**
 * Factorizes number
 * @param x number to factorize
 * @return array of prime factors
 */
std::vector<int64_t> factorize(int64_t x) {
    std::vector<int64_t> factors;
    // two special cases:
    if (x == -1 || x == 0 || x == 1) { // -1,0,1
        factors.push_back(x);
        return factors;
    } else if (x == LLONG_MIN) { // ll_min handled separately: long.min*(-1) cannot be converted to positive
        factors.push_back(-1);
        while (x < -1) {
            factors.push_back(2);
            x /= 2;
        }
        return factors;
    }

    if (x < 0) { // convert negatives to positives
        factors.push_back(-1);
        x *= -1;
    }

    if (isPrime(x)) { // if prime return it
        factors.push_back(x);
        return factors;
    }

    // factorization
    if (x < LIMIT) { // case: x < LIMIT
        while (x > 1) {
            factors.push_back(SITO[(int) x]);
            x /= SITO[(int) x];
        }
    } else {
        while (x % 2 == 0) { // speeds up whole thing 2 times
            factors.push_back(2);
            x /= 2;
        }
        for (long i = 3; x > 1 && i <= (int64_t) sqrt(x) + 1; i += 2) {
            while (
                    (i < LIMIT && SITO[(int) i] == i && x % i == 0) ||
                    (i > LIMIT && x % i == 0)
                    ) {
                factors.push_back(i);
                x /= i;
            }
        }
    }
    if (x > 1)
        factors.push_back(x);
    return factors;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Pass whole numbers in range [LL_MIN, LL_MAX] as program arguments."
                  << std::endl;
    } else {
        _init();
        for (int i = 1; i < argc; ++i) {

            std::cout << argv[i] << "=";
            try {
                // std::string s(argv[i]);
                int64_t number = std::stoll(argv[i]);
                auto factors = factorize(number);

                bool isFirst = true;
                for (auto factor : factors) {
                    if (!isFirst)
                        std::cout << "*";
                    isFirst = false;
                    std::cout << factor;
                }
            } catch (std::invalid_argument &e) {
                std::cout << "Illegal argument exception.";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}