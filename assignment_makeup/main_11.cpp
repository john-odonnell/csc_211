#include <iostream>
#include <iomanip>

bool prime(int n) {
    bool prime = true;
    bool found_or_finished = false;
    while (found_or_finished == false) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                prime = false;
                found_or_finished = true;
            }
        }
        found_or_finished = true;
    }
    return prime;
}

int power(int a, int b) {
    int power = 1;
    while (b > 0) {
        power *= a;
        b--;
    }
    return power;
}

bool circular_prime(int n) {
    int n_for_length = n;
    int length_n = 0;
    while (n_for_length > 0) {
        n_for_length /= 10;
        length_n++;
    }

    bool circ_prime = true;
    for (int i = 0; i < length_n; i++) {
        if (prime(n) == false) {
            circ_prime = false;
        }
        n = (n / 10) + ((n % 10) * power(10, length_n - 1));
    }

    return circ_prime;
}

int main() {
    int n;
    std::cin >> n;

    bool circ_prime = circular_prime(n);

    std::string output;
    if (n == 1) {
        output = "False";
    }
    else if (circ_prime) {
        output = "True";
    }
    else {
        output = "False";
    }

    std::cout << output << std::endl;
    return 0;
}