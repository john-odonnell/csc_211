#include <iostream>
#include <math.h>
#include <string>
#include <array>
using namespace std;

int main () {
    int a, b, c;

    std::string title_message = "Finds the average of 3 integers.";

    std::cout << title_message << std::endl;
    std::cout << "Enter int A: " << std::ends;
    std::cin >> a;

    std::cout << "Enter int B: " << std::ends;
    std::cin >> b;

    std::cout << "Enter int C: " << std::ends;
    std::cin >> c;

    float average = (a + b + c) / 3;

    std::cout << "The average of the 3 integers is " << average << "." << std::endl;
}