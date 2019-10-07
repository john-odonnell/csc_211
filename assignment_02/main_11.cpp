#include <iostream>
#include <iomanip>

std::string char_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void print_leading_spaces(int level, int levels) {
    int i = level;
    for (i; i < levels; i++) {
        std::cout << "  ";
    }
}

void print_chars_up(int level, int levels) {
    for (int i = 0; i <= level; i++) {
        std::cout << char_string[i] << " ";
    }
}

void print_chars_down(int level, int levels) {
    int i = level - 1;
    for (i; i >= 0; i--) {
        std::cout << char_string[i] << " ";
    }
}

void char_pyramid(char desired_char) {
    int levels;
    int i = 0;

    for (i; i < char_string.length(); i++) {
        if (char_string[i] == desired_char) {
            levels = i;
        }
    }

    for (int i = 0; i <= levels; i++) {
        print_leading_spaces(i, levels);
        print_chars_up(i, levels);
        print_chars_down(i, levels);
        std::cout << std::endl;
    }
}

int main () {
    char input;
    std::cin >> input;

    char_pyramid(input);

    return 0;
}