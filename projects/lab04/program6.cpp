#include <iostream>
#include <iomanip>

int main () {

    std::string character = "*";
    std::string output;
    int number_rows = 4;

    for (int i = 0; i < number_rows; ++i) {
        std::string output_1, output_2 = "";
        for (int j = 0; j < i; ++j) {
            output_1 += "*";
        }
        for (int j = 0; j < i + 1; ++j) {
            output_2 += "*";
        }
        output = output_1 + output_2;
        std::cout << output << std::endl;
    }

    return 0;
}