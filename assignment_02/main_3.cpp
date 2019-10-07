#include <iostream>
#include <iomanip>

int factorial(int n) {
    int factorial = 1;

    for (int i = n; i > 1; i--) {
        factorial *= i;
    }

    return factorial;
}

int main () {
    int number;
    std::cin >> number;

    int x = factorial(number);

    if (x == 0) {
        std::cout << "Can't handle this" << std::endl;
    }
    else {
        std::cout << x << std::endl;
    }

    return 0;
}