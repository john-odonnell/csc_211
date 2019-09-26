#include <iostream>
#include <iomanip>

int main () {
    int a, b, c;

    std::cout << "~~Subtraction Calculator~~" << std::endl;
    std::cout << "Enter two numbers to subract: " << std::ends;

    std::cin >> a >> b;

    c = a - b;

    std::cout << a << " - " << b << " = " << c << std::endl;

    return 0;
}