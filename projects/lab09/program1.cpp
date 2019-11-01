#include <iostream>
#include <iomanip>

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::cout << fib(n) << std::endl;

    return 0;
}