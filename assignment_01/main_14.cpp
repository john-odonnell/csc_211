#include <iostream>
#include <iomanip>

int main () {
    double x, y;
    std::string quadrant;

    std::cout << "~~Which Quadrant~~" << std::endl;
    std::cout << "Enter x and y values:" << std::endl;

    std::cin >> x >> y;

    if ((x > 0) && (y > 0)) {
        quadrant = "Quadrant 1";
    }
    else if ((x < 0) && (y > 0)) {
        quadrant = "Quadrant 2";
    }
    else if ((x < 0) && (y < 0)) {
        quadrant = "Quadrant 3";
    }
    else if ((x > 0) && (y < 0)) {
        quadrant = "Quadrant 4";
    }
    else {
        quadrant = "No quadrant";
    }

    std::cout << quadrant << std::endl;

    return 0;
}