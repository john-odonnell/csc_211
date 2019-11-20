#include "Point.h"
#include <string>
#include <math.h>

// Contructor
Point::Point(int a, int b, int c) {
    x = a;
    y = b;
    z = c;
}

// Setters
void Point::setX(int a) {
    x = a;
}
void Point::setY(int b) {
    y = b;
}
void Point::setZ(int c) {
    z = c;
}

// Getters
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
int Point::getZ() {
    return z;
}

// Methods
std::string Point::toCord() {
    std::string returnString = "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
    return returnString;
}
double Point::euDistance(Point p2) {
    int diffX = x - p2.getX();
    int diffY = y - p2.getY();
    int diffZ = z - p2.getZ();
    double dist = sqrt(pow(diffX, 2) + pow(diffY, 2) + pow(diffZ, 2));

    return dist;
}