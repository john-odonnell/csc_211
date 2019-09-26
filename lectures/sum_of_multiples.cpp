#include <iostream>
#include <iomanip>

int main () {
    int sum = 0;
    double average;

    for (int i = 1; i < 26; i++) {
        sum += (3 * i);
    }

    average = sum / 25;

    std::cout << average << std::endl;
}