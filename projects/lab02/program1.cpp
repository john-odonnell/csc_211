#include <iostream>
#include <math.h>
#include <string>
#include <array>
using namespace std;

int main () {
    int a;
    int b;
    int c;

    std::cout << "Enter 'a' value: " << std::ends;
    std::cin >> a;

    std::cout << "Enter 'b' value: " << std::ends;
    std::cin >> b;

    std::cout << "Enter 'c' value: " << std::ends;
    std::cin >> c;

    float x_pos;
    float x_neg;

    x_pos = ((-b) + (sqrt((b*b) - (4 * a * c)))) / (2 * a);
    x_neg = ((-b) - (sqrt((b*b) - (4 * a * c)))) / (2 * a);

    std::cout << "The x values are " << x_pos << " and " << x_neg << ".";
    std::cout << std::endl;

    return 0;
}