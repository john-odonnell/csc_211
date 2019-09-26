#include <iostream>
#include <iomanip>

int main () {
    int number;
    std::string good_nogood;

    std::cin >> number;

    if ((number % 10) == 9 || (number % 10) == -9) {
        good_nogood = " is good";
    }
    else {
        good_nogood = " is no good";
    }

    std::cout << number << good_nogood << std::endl;

    return 0;
}