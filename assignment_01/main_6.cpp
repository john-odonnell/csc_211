#include <iostream>
#include <iomanip>

int main () {
    int number;
    std::string pos_neg;

    // push the input stream to number
    std::cin >> number;

    if (number > 0) {               // if number is greater than 0
        pos_neg = " is positive";   // output string to positive
    }
    else if (number < 0) {          // if number is less than 0
        pos_neg = " is negative";   // output string to negative
    }
    else {                          // otherwise, neither
        pos_neg = " is neither positive nor negative";
    }

    // push results to output stream
    std::cout << number << pos_neg << std::endl;

    return 0;
}