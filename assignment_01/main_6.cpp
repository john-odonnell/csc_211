#include <iostream>
#include <iomanip>

int main () {
    int number;
    std::string pos_neg;

    std::cout << "~~Positive or Negative~~" << std::endl;
    std::cout << "Enter number to determine sign: " << std::ends;

    std::cin >> number;

    if (number > 0) {
        pos_neg = " is positive";
    }
    else if (number < 0) {
        pos_neg = " is negative";
    }
    else {
        pos_neg = " is neither positive nor negative";
    }

    std::cout << number << pos_neg << std::endl;

    return 0;
}