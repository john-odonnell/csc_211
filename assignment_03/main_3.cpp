#include <iostream>
#include <iomanip>

unsigned int string_len(char str[]) {
    int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}

void reverse(char inputString[]) {
    int length = string_len(inputString);

    for (int i = length - 1; i >= 0; i--) {
        std::cout << inputString[i];
    }
    std::cout << std::endl;
}

int main() {
    char inputString[100];
    std::cin.getline(inputString, 100);

    reverse(inputString);

    return 0;
}

// WORKS