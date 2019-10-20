#include <iostream>
#include <iomanip>
#include <cmath>

int sum_or_product(int a, int b, int c) {
    int to_return;

    if (a % 2 == 0) {
        to_return = 0;
        for (int i = b; i <= c; i++) {
            to_return += i;
        }
    }
    else {
        to_return = 1;
        for (int i = b; i <= c; i++) {
            to_return *= i;
        }
    }
    return to_return;
}

std::string dec_to_binary(int a) {
    if (a < 2) {
        return std::to_string(a);
    }
    else {
        int this_digit = a % 2;
        a /= 2;
        return std::to_string(this_digit) + dec_to_binary(a);
    }
}

int num_digits(int a) {
    int num_dig = 0;
    while (a > 0) {
        a /= 10;
        num_dig++;
    }
    return num_dig;
}

int rev_integer(int n) {
    int level_counter = num_digits(n);
    if (n < 10) {
        return n;
    }
    else {
        int n_next = n / 10;
        return ((n % 10) * (pow(10, level_counter - 1))) + rev_integer(n_next);
    }
}

int main() {
    std::cout << sum_or_product(2, 2, 5) << std::endl;

    std::cout << dec_to_binary(5) << std::endl;

    std::cout << num_digits(11111) << std::endl;

    std::cout << rev_integer(12345) << std::endl;
}