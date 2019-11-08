#include <iostream>
#include <iomanip>

void draw_line(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    return;
}

void full_pyramid(int i, int n) {
    if (i == n + 1) {
        return;
    }
    else {
        draw_line(i);
        full_pyramid(i + 1, n);
        draw_line(i);
        return;
    }
}

int main() {
    int n;
    std::cin >> n;

    full_pyramid(1, n);

    return 0;
}