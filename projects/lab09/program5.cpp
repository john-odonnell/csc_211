#include <iostream>
#include <iomanip>

int sum_digits(int n) {
    if (n % 10 == n) return n;
    else {
        int dig = n % 10;
        int rest = n / 10;
        return dig + sum_digits(rest);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::cout << sum_digits(n) << std::endl;

    return 0;
}