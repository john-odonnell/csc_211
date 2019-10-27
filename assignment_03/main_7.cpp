#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

float diameter(int x1, int y1, int x2, int y2) {
    int dist_x = abs(x1 - x2);
    int dist_y = abs(y1 - y2);

    float dia = sqrt(pow(dist_x, 2) + pow(dist_y, 2));

    return dia;
}

int main() {
    int counter = 0;
    int x, y;
    int x_arr[100], y_arr[100];

    while ((std::cin >> x >> y) and (counter < 100)) {
        x_arr[counter] = x;
        y_arr[counter] = y;
        counter++;
    }

    float largest_dia = 0;
    for (int i = 0; i < counter - 1; i++) {
        for (int j = i + 1; j < counter; j++) {
            float this_dia = diameter(x_arr[i], y_arr[i], x_arr[j], y_arr[j]);
            if (this_dia > largest_dia) {
                largest_dia = this_dia;
            }
        }
    }

    std::cout << int(largest_dia) << std::endl;

    return 0;
}

// WORKS