#include <iostream>
#include <iomanip>

void draw_white_spaces(int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << " ";
    }
}

void draw_asterisk(int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void draw_triangle_2(int n) {
    for (int i = 1; i <= n; i++) {
        draw_white_spaces(n - i);
        draw_asterisk(i);
    }
}

int main () {
    int number;
    std::cin >> number;

    draw_triangle_2(number);
    return 0;
}