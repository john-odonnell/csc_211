#include <iostream>
#include <iomanip>

int main () {
    int number;             // instantiate number
    std::string even_odd;   // and output string

    // push input stream to number
    std::cin >> number;

    if (number % 2 == 0) {      // if number mod 2 is 0
        even_odd = " is even";  // even output string
    }
    else {                      // otherwise
        even_odd = " is odd";   // odd output string
    }

    // push results to the output string
    std::cout << number << even_odd << std::endl;

    return 0;
}