#include <iostream>
#include "is_prime_prog.h"

void is_prime(int n) {
    if (n <= 1) {
        std::cout << n << " is a prime: False" << std::endl;
        return;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            std::cout << n << " is a prime: False" << std::endl;
            return;
        }
    }

    std::cout << n << " is a prime: True" << std::endl;
}