#include <iostream>
#include <iomanip>

void spaces(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }
}

void top(int number, int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = number - 2 - (2 * i);
        spaces(i);
        std::cout << "*";
        spaces(j);
        std::cout << "*" << std::endl;
    }
}

void middle(int n) {
    spaces(n);
    std::cout << "*" << std::endl;
}

void bottom(int number, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int j = number - 2 - (2 * i);
        spaces(i);
        std::cout << "*";
        spaces(j);
        std::cout << "*" << std::endl;
    }
}

int main () {
    int n;
    std::cin >> n;

    int len = n / 2;

    if (n % 2 != 0) {
        top(n, len);
        middle(len);
        bottom(n, len);
    }
    else {
        std::cout << "Sorry, not odd" << std::endl;
    }

    return 0;
}