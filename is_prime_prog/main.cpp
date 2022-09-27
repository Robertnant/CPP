#include <iostream>
#include "is_prime_prog.h"

int main()
{
    int number;
    while (std::cin >> number)
    {
        is_prime(number);
    }

    return 0;
}
