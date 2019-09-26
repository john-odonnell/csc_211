#include <iostream>
#include <iomanip>

int main () {
    int a, b, c;    // instantiate a b and c

    // push strings to the output stream
    std::cout << "~~Division Calculator~~" << std::endl;
    std::cout << "Enter two numbers to divide: " << std::ends;

    // push input stream to a and b
    std::cin >> a >> b;

    c = a / b;  // division

    // push division results to output stream
    std::cout << a << " / " << b << " = " << c << std::endl;

    return 0;
}