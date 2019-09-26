#include <iostream>
#include <math.h>
#include <string>
#include <array>

int main () {
    int low, high, test;

    std::cout << "~~Program to determine if a given number is within a given range~~" << std::endl;
    std::cout << "Enter Low bound, high bound, and test number: " << std::ends;

    std::cin >> low >> high >> test;

    if ((test >= low) && (test <= high)) {
        std::cout << test << " is within the given range." << std::endl;
    }
    else {
        std::cout << test << " is not within the given range." << std::endl;
    }
}