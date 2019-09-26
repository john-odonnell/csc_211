#include <iostream>
#include <iomanip>

int main () {
    double a, b, c, average;

    std::cout << "~~Average~~" << std::endl;
    std::cout << "Enter three numbers to average: " << std::endl;

    std::cin >> a >> b >> c;

    average = ((a + b + c) / 3);

    std::cout << "The average of " << a << ", " << b << ", and ";
    std::cout << c << " is " << average << std::endl;

    return 0;
}