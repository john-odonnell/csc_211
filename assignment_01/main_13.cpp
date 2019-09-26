#include <iostream>
#include <iomanip>

int main () {
    int a, b, c, smallest;

    std::cin >> a >> b >> c;

    if (a < b) {
        smallest = a;
    }
    else {
        smallest = b;
    }

    if (c < smallest) {
        smallest = c;
    }

    std::cout << "The smallest number entered was " << smallest << std::endl;

    return 0;
}