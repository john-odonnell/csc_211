#include <iostream>
#include <iomanip>

std::string hex_values = "0123456789ABCDEF";

void rgb_to_hex(int val) {
    std::string hex_val = "";
    std::string hex_digit;
    int digit;

    while (val >= 0) {
        if (val == 0) {
            digit = 0;
            val--;
        }
        else {
            digit = val % 16;
            val /= 16;
        }
        hex_digit = hex_values[digit];
        hex_val += hex_digit;
    }

    std::cout << hex_val << " ";


}

int main () {
    int r, g, b;
    std::cin >> r >> g >> b;

    rgb_to_hex(r);
    rgb_to_hex(g);
    rgb_to_hex(b);

    std::cout << std::endl;

    return 0;
}