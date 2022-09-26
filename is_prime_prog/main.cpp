#include <iostream>
#include "is_prime_prog.h"

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::string number_str;
    for (char c : input)
    {
        if (c == ' ')
        {
            is_prime(std::stoi(number_str));
            number_str = "";
        }
        else
        {
            number_str += c;
        }
    }

    is_prime(std::stoi(number_str));

    return 0;
}