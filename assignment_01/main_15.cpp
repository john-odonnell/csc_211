#include <iostream>
#include <iomanip>

int main () {
    double celsius, farenheit;
    double fraction_c_f = (double)9/5;
    std::string output;

    std::cout << "~~Celsius to Farenheit~~" << std::endl;
    std::cout << "Enter temp in C: " << std::ends;

    std::cin >> celsius;

    farenheit = ((celsius * fraction_c_f) + 32);

    if (farenheit <= 32) {
        output = "It is cold out";
    }
    else if (farenheit <= 65) {
        output = "Wear a jacket";
    }
    else {
        output = "It is nice out";
    }

    std::cout << output << std::endl;

    return 0;
}