#include <iostream>
#include "is_prime_prog.h"

/**
 * Test if a given number is prime using trial division.
 *
 * @param number Number to be tested for primality.
 */
void is_prime(int number)
{
    if (number <= 1)
    {
        std::cout << number << " is a prime: False" << std::endl;
        return;
    }

    for (int tested_int = 2; tested_int * tested_int <= number; tested_int++)
    {
        if (number % tested_int == 0)
        {
            std::cout << number << " is a prime: False" << std::endl;
            return;
        }
    }

    std::cout << number << " is a prime: True" << std::endl;
}
