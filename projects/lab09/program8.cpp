#include <iostream>
#include <iomanip>

unsigned int str_length(std::string str) {
    int counter = 0;
    while (str[counter]) {
        counter++;
    }
    return counter;
}


bool pali(std::string str) {
    int length = str_length(str);

    if (length < 2) {
        return true;
    }
    else if (str[0] != str[length - 1]) {
        return false;
    }
    else {
        return pali(str.substr(1, length - 2));
    }
}

int main() {
    std::string input = "tacogato";

    std::cout << pali(input) << std::endl;

    return 0;
}