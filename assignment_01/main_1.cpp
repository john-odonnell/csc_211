#include <iostream>
#include <iomanip>

int main () {
    int a, b, c;

    std::cout << "~~Addition Calculator~~" << std::endl;
    std::cout << "Enter two numbers to add: " << std::ends;

    std::cin >> a >> b;

    c = a + b;

    std::cout << a << " + " << b << " = " << c << std::endl;

    return 0;
}