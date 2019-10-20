#include <iostream>
#include <iomanip>

unsigned int string_len(char str[]) {
    unsigned int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

bool palindrome(char str[]) {
    unsigned int length = string_len(str);

    int L = 0;
    int R = length - 1;

    bool palindrome = true;
    while (L < R) {
        if (toupper(str[L]) != toupper(str[R])) {
            return false;
        }
        L++;
        R--;
    }

    return palindrome;
}

int main() {
    char myString[100];
    std::cin.getline(myString, 100);

    bool pal = palindrome(myString);
    if (pal) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
