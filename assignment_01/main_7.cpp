#include <iostream>
#include <iomanip>

int main () {
    int number;
    std::string satisfaction;

    std::cout << "Larger than 100 and Multiple of 8~~" << std::endl;
    std::cout << "Input number: " << std::ends;

    std::cin >> number;

    if (number > 100) {
        if (number % 8 == 0) {
            satisfaction = " satisfies the criteria";
        }
        else {
            satisfaction = " does not satisfy the criteria";
        }
    }
    else {
        satisfaction = " does not satisfy the criteria";
    }

    std::cout << number << satisfaction << std::endl;

    return 0;
}