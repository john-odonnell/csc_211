#include <iostream>
#include <iomanip>

int main () {
    char grade;
    std::string output;

    std::cout << "~~Grades~~" << std::endl;
    std::cout << "Input Letter Grade: " << std::ends;

    std::cin >> grade;
    grade = toupper(grade);

    switch(grade) {
        case 'A': output = "Excellent"; break;
        case 'B': output = "Good"; break;
        case 'C': output = "Average"; break;
        case 'D': output = "Poor"; break;
        case 'F': output = "Failing"; break;
    }

    std::cout << output << std::endl;

    return 0;
}