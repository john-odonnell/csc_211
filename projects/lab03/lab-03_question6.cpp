#include <iostream>
#include <math.h>
#include <array>
#include <string>

int main () {
    int number;

    std::cout << "~~Program to determine if a number is prime~~" << std::endl;
    std::cout << "Input number: " << std::ends;

    std::cin >> number;

    bool prime = true;
    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            prime = false;
        }
    }

    if (prime == true) {
        std::cout << number << " is a prime number." << std::endl;
    }
    else {
        std::cout << number << " is not a prime number." << std::endl;
    }

    return 0;
}