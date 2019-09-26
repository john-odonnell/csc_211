#include <iostream>
#include <iomanip>

int main () {
    int a, b, c;
    std::string output;

    std::cout << "~~Triangles~~" << std::endl;
    std::cout << "Input 3 Interior Angles: " << std::endl;

    std::cin >> a >> b >> c;

    if ((a + b + c) != 180) {
        output = "This triangle is impossible";
    }
    else if (a > 90 || b > 90 || c > 90) {
        output = "Obtuse";
    }
    else if (a == 90 || b == 90 || c == 90) {
        output = "Right";
    }
    else {
        output = "Acute";
    }

    std::cout << output << std::endl;

    return 0;
}