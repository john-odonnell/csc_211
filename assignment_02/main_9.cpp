#include <iostream>
#include <iomanip>

void draw_triangle_top(int base, int max, int increment) {
    while (base <= max) {
        for (int i = 0; i < base; i ++) {
            std::cout << "+";
        }
        std::cout << std::endl;

        base += increment;
    }
}

void draw_triangle_bottom(int base, int max, int increment) {
    int start_here = base;
    for (int i = base; start_here + increment - 1 < max; i++) {
        start_here += increment;
    }
    while (start_here >= base) {
        for (int i = 0; i < start_here; i++) {
            std::cout << "+";
        }
        std::cout << std::endl;

        start_here -= increment;
    }
}

int main () {
    int a, b, c;
    std::cin >> a >> b >> c;

    draw_triangle_top(a, b, c);
    draw_triangle_bottom(a, b, c);

    return 0;
}