#include <iostream>
#include <iomanip>

int power(int a, int b) {
    int power = 1;
    while (b > 0) {
        power *= a;
        b--;
    }

    return power;
}

int main () {
    int a, b;
    std::cin >> a >> b;

    int output = power(a, b);

    if (output == -1) {
        std::cout << "Can't handle this" << std::endl;
    }
    else {
        std::cout << output << std::endl;
    }

    return 0;
}