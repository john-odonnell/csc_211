#include <iostream>
#include <iomanip>

unsigned int string_len(char str[]) {
    int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}

char* reverse(char inputString[]) {
    int length = string_len(inputString);
    char reversed[length];

    for (int i = length - 1; i >= 0; i--) {
        int newIndex = length - 1 - i;
        reversed[newIndex] = inputString[i];
    }

    return reversed;
}

int main() {
    char inputString[100], reversed[100];
    std::cin.getline(inputString, 100);

    reversed = reverse(inputString);

    std::cout << reversed << std::endl;

    return 0;
}