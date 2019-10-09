#include <iostream>
#include <iomanip>

std::string hex_values = "0123456789ABCDEF";

void rgb_to_hex(int val) {
    std::string hex_digit;
    int digit;

    std::string first_char, second_char;

    for (int i = 0; i < 2; i++) {
        if (val == 0) {
            digit = 0;
        }
        else {
            digit = val % 16;
            val /= 16;
        }
        hex_digit = hex_values[digit];

        if (i == 0) {
            second_char = hex_digit;
        }
        else if (i == 1) {
            first_char = hex_digit;
        }
    }

    std::cout << first_char << second_char;


}

int main () {
    int r, g, b;
    std::cin >> r >> g >> b;

    std::cout << "#";
    rgb_to_hex(r);
    rgb_to_hex(g);
    rgb_to_hex(b);

    std::cout << std::endl;

    return 0;
}