#include <iostream>
#include <iomanip>

int main () {
    // takes an int input from the user
    // prints all numbers [0, input]

    int number;

    std::cout << "Enter integer input: " << std::ends;
    std::cin >> number;

    for (int i = 0; i <= number; ++i) {
        std::cout << i << std::endl;
    }

    return 0;
}