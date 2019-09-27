#include <iostream>
#include <iomanip>

int main () {
    int number_rows = 4;

    for (int i = 0; i < number_rows; i++) {
        std::string spaces;

        for (int j = 0; j < 3 - i; ++j) {
            spaces += " ";
        }
        std::cout << spaces << std::ends;

        for (int j = i + 1; j <= i + i + 1; j++) {
            std::cout << j << std::ends;
        }

        for (int j = i + i; j > i; j--) {
            std::cout << j << std::ends;
        }

        std::cout << std::endl;
    }

    return 0;
}