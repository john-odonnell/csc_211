#include <iostream>
#include <iomanip>

int main () {
    int number;
    std::string good_nogood;

    std::cout << "~~Last Digit is 9~~" << std::endl;
    std::cout << "Enter number: " << std::ends;

    std::cin >> number;

    if (((number + 1) % 10) == 0) {
        good_nogood = " is good";
    }
    else {
        good_nogood = " is no good";
    }

    std::cout << number << good_nogood << std::endl;

    return 0;
}