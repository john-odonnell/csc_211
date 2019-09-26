#include <iostream>
#include <math.h>
#include <string>
#include <array>
using namespace std;

int main () {
    string name;

    std::cout << "What is your name? " << std::ends;
    std::cin >> name;

    std::cout << "Hello, " << name << "!" << std::endl;
}