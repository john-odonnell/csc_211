#include <iostream>
#include <iomanip>

int main () {
    int digit;
    std::string output;

    std::cin >> digit;

    switch (digit) {
        case 9: output = "Nine"; break;
        case 8: output = "Eight"; break;
        case 7: output = "Seven"; break;
        case 6: output = "Six"; break;
        case 5: output = "Five"; break;
        case 4: output = "Four"; break;
        case 3: output = "Three"; break;
        case 2: output = "Two"; break;
        case 1: output = "One"; break;
        case 0: output = "Zero"; break;
        default: output = "Not a valid number"; break;
    }

    std::cout << output << std::endl;

    return 0;
}