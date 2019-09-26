#include <iostream>
#include <iomanip>

int main () {
    int a, b, c;    // instantiate a b and c

    // push the input stream to a and b
    std::cin >> a >> b;

    c = a + b;  // addition

    // push addition results to output stream
    std::cout << a << " + " << b << " = " << c << std::endl;

    return 0;
}