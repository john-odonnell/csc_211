#include <iostream>
#include <iomanip>

void triangle(int n) {
    if (n == 0) {
        return;
    }
    else {
        triangle(n - 1);

        for (int i = 0; i < n; i++) {
            std::cout << "*";
        }
        std::cout << std::endl;

        return;
    }
}

int main() {
    int n;
    std::cin >> n;

    triangle(n);

    return 0;
}