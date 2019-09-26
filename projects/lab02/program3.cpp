#include <iostream>
#include <math.h>
#include <string>
#include <array>
using namespace std;

int main () {
    int four_digit_input;
    int array[4];
    int first, second, third, fourth;

    std::cout << "Enter four digit number: " << std::ends;
    std::cin >> four_digit_input;

    for (int i = 0; i < 4; i++) {
        array[i] = four_digit_input % 10;
        four_digit_input /= 10;
    }


    std::cout << array[0] << ", " << array[1] << ", " << array[2];
    std::cout << ", " << array[3] << std::endl;

    return 0;
}