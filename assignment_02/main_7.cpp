#include <iostream>
#include <iomanip>

int sum_even(int n) {
    int sum = 0;
    int digit;
    while (n > 0) {
        digit = n % 10;
        if (digit % 2 == 0) {
            sum += digit;
        }
        n /= 10;
    }

    return sum;
}

int main () {
    int n;
    std::cin >> n;

    int sum = sum_even(n);
    std::cout << sum << std::endl;

    return 0;
}