#include <iostream>
#include <iomanip>

unsigned int string_len(char str[]) {
    int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}

void reverse(char inputString[], char outputString[]) {
    int length = string_len(inputString);

    for (int i = length - 1; i >= 0; i--) {
        int newIndex = length - 1 - i;
        outputString[newIndex] = inputString[i];
    }
}

int main() {
    char inputString[100], reversed[100];
    std::cin.getline(inputString, 100);

    reverse(inputString, reversed);

    std::cout << reversed << std::endl;

    return 0;
}