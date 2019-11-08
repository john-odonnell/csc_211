#include <iostream>
#include <iomanip>

int str_length(char *str) {
    int counter = 0;
    while(str[counter]) {
        counter++;
    }
    return counter;
}

bool palindrome(char *str, int length) {
    if (length < 2) {
        return true;
    }
    if (str[0] != str[length - 1]) {
        return false;
    }
    else {
        return palindrome(str + 1, length - 2);
    }
}

int main() {
    char input[100];
    std::cin.getline(input, 100);

    int length = str_length(input);

    std::cout << palindrome(input, length) << std::endl;

    return 0;
}