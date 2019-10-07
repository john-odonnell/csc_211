#include <iostream>
#include <iomanip>

void draw_triangle_1(int n) {
    for (int i = n - 1; i >= 0; i--) {
        int counter = i;
        while (counter < n) {
            std::cout << "*";
            counter++;
        }
        std::cout << std::endl;
    }
}

int main () {
    int number;
    std::cin >> number;

    draw_triangle_1(number);
    return 0;
}