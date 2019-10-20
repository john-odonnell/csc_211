#include <iostream>
#include <iomanip>
#include <math.h>

bool check_prime(int n) {
    bool prime = true;
    if (n == 1) {
        return false;
    }
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            prime = false;
            return prime;
        }
    }

    return prime;
}

int main () {
    int input;
    std::string output;

    std::cin >> input;

    bool prime = check_prime(input);
    if (prime == true) {
        output = "True";
    }
    else {
        output = "False";
    }

    std::cout << output << std::endl;
}