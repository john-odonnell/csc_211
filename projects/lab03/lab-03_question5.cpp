#include <iostream>
#include <math.h>
#include <string>
#include <array>

int main () {
    const int speed_limit = 50;
    int car_speed;

    std::cout << "~~Program to detect if a car is speeding~~" << std::endl;
    std::cout << "Enter car speed: " << std::ends;

    std::cin >> car_speed;

    if (car_speed > (speed_limit + 5)) {
        std::cout << "Speeding" << std::endl;
    }
    else if (car_speed >= speed_limit) {
        std::cout << "Pushing your luck" << std::endl;
    }
    else {
        std::cout << "Safe" << std::endl;
    }
}