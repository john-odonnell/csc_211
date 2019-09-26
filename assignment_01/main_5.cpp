#include <iostream>
#include <iomanip>

int main () {
    int number;
    std::string even_odd;

    std::cout << "~~Odd or Even~~" << std::endl;
    std::cout << "Enter number to determine its parity: " << std::ends;

    std::cin >> number;

    if (number % 2 == 0) {
        even_odd = " is even";
    }
    else {
        even_odd = " is odd";
    }

    std::cout << number << even_odd << std::endl;

    return 0;
}