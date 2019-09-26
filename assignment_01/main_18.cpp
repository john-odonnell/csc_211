#include <iostream>
#include <iomanip>

int main () {
    int day, month, year, century, yearpart, weekday;
    int a, b, c, d, e, f;
    std::string output;

    std::cout << "~~Day of the Week~~" << std::endl;
    std::cout << "Input Date in Day, Month, Year order: " << std::endl;

    std::cin >> day >> month >> year;

    if (month < 3) {
        month = month + 12;
        year = year - 1;
    }

    century = year / 100;
    yearpart = year % 100;

    a = day;
    b = (((month + 1) * 26) / 10);
    c = yearpart;
    d = yearpart / 4;
    e = century / 4;
    f = 5 * century;

    std::cout << a << b << c << d << e << f << std::endl;

    weekday = (a + b + c + d + e + f) % 7;

    switch(weekday) {
        case 0: output = "Saturday"; break;
        case 1: output = "Sunday"; break;
        case 2: output = "Monday"; break;
        case 3: output = "Tuesday"; break;
        case 4: output = "Wednesday"; break;
        case 5: output = "Thursday"; break;
        case 6: output = "Friday"; break;
    }

    std::cout << output << std::endl;

    return 0;
}