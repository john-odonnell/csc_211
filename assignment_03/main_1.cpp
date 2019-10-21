#include <iostream>
#include <iomanip>

int main() {
    int firstInt;
    int inputCounter = 0;

    std::cin >> firstInt;
    int occurances = 1;

    int nextInt;
    while ((std::cin >> nextInt) && (inputCounter < 100)) {
        if (nextInt == firstInt) {
            occurances++;
        }
        inputCounter++;
    }

    std::cout << occurances << std::endl;

    return 0;
}