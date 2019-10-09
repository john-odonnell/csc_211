#include <iostream>
#include <iomanip>

bool check_prime(int n) {
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