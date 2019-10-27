#include <iostream>
#include <iomanip>
#include <math.h>

int get_diameter(int x1, int y1, int x2, int y2) {
    int diffX = abs(x1 - x2);
    int diffY = abs(y1 - y2);

    float distance = sqrt(pow(diffX, 2) + pow(diffY, 2));

    return int(distance);
}

int diameter(int x[], int y[], int length) {
    int largest = -1;

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            int this_diameter = get_diameter(x[i], y[i], x[j], y[j]);
            if (this_diameter > largest) {
                largest = this_diameter;
            }
        }
    }

    return largest;
}

int main() {
    int x[100];
    int y[100];

    int this_x, this_y;

    int counter = 0;

    while (std::cin >> this_x >> this_y) {
        x[counter] = this_x;
        y[counter] = this_y;
        counter++;
    }

    int largest_diameter = diameter(x, y, counter);

    std::cout << largest_diameter << std::endl;

    return 0;
}