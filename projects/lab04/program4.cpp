#include <iostream>
#include <iomanip>

int main () {
    // infinitely get input from the user and print it
    // stops when user inputs 0

    std::string input;

    while (true) {
        std::cout << "Input: " << std::ends;
        std::cin >> input;

        if (input == "0") {
            std::cout << "Done." << std::endl;
            break;
        }

        std::cout << input << std::endl;
    }

    return 0;
}