#include <iostream>
#include <iomanip>

int main () {
    int number_rows = 4;

    for (int i = 0; i < number_rows; i++) {

        for (int j = 0; j < 2 * i; j++) {
            std::cout << "\\" << std::ends;
        }

        for (int j = 0; j < 14 - (i * 4); j++) {
            std::cout << "!" << std::ends;
        }

        for (int j = 0; j < 2 * i; j++) {
            std::cout << '/' << std::ends;
        }

        std::cout << std::endl;
    }

    return 0;
}