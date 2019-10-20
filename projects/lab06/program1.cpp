#include <iostream>
#include <iomanip>

unsigned int string_len(char str[]) {
    unsigned int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}

int main() {
    char myString[] = "Hello, World!";
    unsigned int x = string_len(myString);
    std::cout << x << std::endl;
}
