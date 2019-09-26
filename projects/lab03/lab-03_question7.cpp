#include <iostream>
#include <math.h>
#include <array>
#include <string>

int main () {
    char input_char;
    char upper;
    char lower;

    std::cout << "~~Program to determine if a given letter is capitalized or not~~" << std::endl;
    std::cout << "Input letter: " << std::ends;

    std::cin >> input_char;

    upper = toupper(input_char);
    lower = tolower(input_char);

    if (input_char == upper) {
        std::cout << "Upper Case" << std::endl;
    }
    else if (input_char == lower) {
        std::cout << "Lower Case" << std::endl;
    }

}