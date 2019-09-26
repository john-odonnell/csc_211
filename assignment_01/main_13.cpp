#include <iostream>
#include <iomanip>

int main () {
    int a, b, c, smallest;

    std::cout << "~~Smallest Number~~" << std::endl;
    std::cout << "Enter three numbers to find the smallest:" << std::endl;

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