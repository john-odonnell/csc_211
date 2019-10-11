#include <iostream>
#include <iomanip>

unsigned int string_len(char str[]) {
    unsigned int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

void reverse(char str[]) {
    int length = string_len(str);
    char revStr[100];

    int i = 0;
    while (i <= length - 1) {
        revStr[i] = str[length - 1 - i];
        i++;
    }

    i = 0;
    while (i <= length - 1) {
        str[i] = revStr[i];
        i++;
    }
}

int main() {
    char myString[100];
    std::cin.getline(myString, 100);

    reverse(myString);

    std::cout << myString << std::endl;

    return 0;
}