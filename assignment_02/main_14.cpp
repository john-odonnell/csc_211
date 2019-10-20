#include <iostream>
#include <iomanip>

bool perfect_check(int n) {
    int total = 0;
    bool perfect = false;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            total += i;
        }
    }
    if (total == n) {
        perfect = true;
    }
    return perfect;
}

int main() {
    int n;
    std::string output;

    std::cin >> n;

    bool perfect = perfect_check(n);

    if (perfect) {
        output = "True";
    }
    else {
        output = "False";
    }

    std::cout << output << std::endl;

    return 0;
}