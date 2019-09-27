#include <iostream>
#include <iomanip>

int main () {
    // program1.cpp but with a while loop

    int number;
    int i = 0;

    std::cout << "Input integer input: " << std::ends;
    std::cin >> number;

    while(i <= number) {
        std::cout << i << std::endl;
        i++;
    }

    return 0;
}