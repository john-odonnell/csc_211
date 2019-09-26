#include <iostream>
#include <math.h>
#include <string>
#include <array>

int main () {
    int number_grade;
    std::string letter_grade;

    std::cout << "Enter numerical grade: " << std::ends;
    std::cin >> number_grade;

    if (number_grade >= 97) {
        letter_grade = "A+";
    }
    else if (number_grade >= 93) {
        letter_grade = "A";
    }
    else if (number_grade >= 90) {
        letter_grade = "A-";
    }
    else if (number_grade >= 87) {

    }

    std::cout << number_grade << " = " << letter_grade << std::endl;

    return 0;
}