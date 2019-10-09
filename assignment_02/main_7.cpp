#include <iostream>
#include <iomanip>

int sum_even(std::string n) {
    int sum = 0;
    int digit;
    std::string this_char;
    for (int i = 0; i < n.length(); i++) {
        this_char = n[i];
        digit = std::stoi(this_char);
        if (digit % 2 == 0) {
            sum += digit;
        }
    }

    return sum;
}

int main () {
    std::string n;
    std::cin >> n;

    int sum = sum_even(n);
    std::cout << sum << std::endl;

    return 0;
}