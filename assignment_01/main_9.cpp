#include <iostream>
#include <iomanip>

int main () {
    int age;
    std::string privilege;

    std::cin >> age;

    if (age < 16) {
        privilege = "Too young";
    }
    else if (age < 18) {
        privilege = "Can drive";
    }
    else if (age < 21) {
        privilege = "Can join the military";
    }
    else {
        privilege = "Can have a beer";
    }

    std::cout << privilege << std::endl;

    return 0;
}