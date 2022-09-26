#include <iostream>

#include "find_motive.h"

int main() {
    std::string input_file_path;
    std::string input_motive;

    std::cout << "Welcome! Please enter a valid file path: ";
    std::cin >> input_file_path;
    std::cout << "Now enter a motive to find please: ";
    std::cin >> input_motive;

    return find_motive(input_file_path,input_motive);
}
