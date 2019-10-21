#include <iostream>
#include <iomanip>

int power(int a, int b) {
    int power = 1;
    for (b; b > 0; b--) {
        power *= a;
    }
    return power;
}

int num_length(int n) {
    int length = 0;
    while (n > 0) {
        length += 1;
        n /= 10;
    }
    return length;
}

bool determine_armstrong(int n) {
    int total = 0;
    int this_digit;
    int num_len = num_length(n);
    int n_placeholder = n;
    bool armstrong = false;
    while (n_placeholder > 0) {
        this_digit = n_placeholder % 10;
        total += power(this_digit, num_len);
        n_placeholder /= 10;
    }
    if (total == n) {
        armstrong = true;
    }
    return armstrong;
}

int main() {
    int n;
    std::string output;
    std::cin >> n;

    bool armstrong = determine_armstrong(n);
    if (armstrong) {
        output = "True";
    }
    else {
        output = "False";
    }

    std::cout << output << std::endl;

    return 0;
}