#include <iostream>
#include <iomanip>

int main () {
    int a, b, c;    // instantiate a b and c

    // push strings to the output stream
    std::cout << "~~Subtraction Calculator~~" << std::endl;
    std::cout << "Enter two numbers to subract: " << std::ends;

    // push the input string to a and b
    std::cin >> a >> b;

    c = a - b;  // subtraction

    // push subtraction results to output stream
    std::cout << a << " - " << b << " = " << c << std::endl;

    return 0;
}