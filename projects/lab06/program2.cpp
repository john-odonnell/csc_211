#include <iostream>
#include <iomanip>

void replace(char str[], char a, char b) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == a) {
            str[i] = b;
        }
        i++;
    }
}

int main() {
    char myString[100];
    char toChange;
    char changeTo;

    std::cin.getline(myString, 100);
    std::cin >> toChange >> changeTo;

    replace(myString, toChange, changeTo);
    std::cout << myString << std::endl;
    return 0;
}
