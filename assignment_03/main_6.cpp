#include <iostream>
#include <iomanip>
#include <string>

unsigned int str_length(std::string str) {
    unsigned int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}

int str_hash(std::string inputString) {
    unsigned int stringLength = str_length(inputString);
    char thisChar;
    int hash = 0;

    for (int i = 0; i < stringLength; i++) {
        thisChar = inputString[i];
        hash += int(thisChar);
    }

    return hash;
}

int main() {
    std::string inputString;
    std::getline(std::cin, inputString);

    int hash = str_hash(inputString);

    std::cout << hash << std::endl;

    return 0;
}

// WORKS