#include <iostream>
#include <iomanip>

unsigned int str_length(char str[]) {
    int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}

void filter_dups(char inputString[], char outputString[], unsigned int stringLength) {
    outputString[0] = inputString[0];
    int nextIndex = 1;
    for (int i = 1; i < stringLength; i++) {
        if (inputString[i] != inputString[i - 1]) {
            outputString[nextIndex] = inputString[i];
            nextIndex++;
        }
    }
}

int main() {
    char inputString[100];
    std::cin.getline(inputString, 100);

    int stringLength = str_length(inputString);

    char outputString[stringLength];

    filter_dups(inputString, outputString, stringLength);

    std::cout << outputString << std::endl;
}