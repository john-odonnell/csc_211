#include <iostream>
#include <iomanip>

int main () {
    int month, day, year;
    std::string month_s;

    std::cout << "~~Date Converter~~" << std::endl;
    std::cout << "Enter month, day, then year in integer form:" << std::endl;

    std::cin >> month >> day >> year;

    switch (month) {
        case 1: month_s = "January"; break;
        case 2: month_s = "February"; break;
        case 3: month_s = "March"; break;
        case 4: month_s = "April"; break;
        case 5: month_s = "May"; break;
        case 6: month_s = "June"; break;
        case 7: month_s = "July"; break;
        case 8: month_s = "August"; break;
        case 9: month_s = "September"; break;
        case 10: month_s = "October"; break;
        case 11: month_s = "November"; break;
        case 12: month_s = "December"; break;
        default: month_s = "Imaginary month"; break;
    }

    std::cout << month_s << " " << day << ", " << year << std::endl;

    return 0;
}