#include <iostream>
#include <math.h>
#include <array>
#include <string>

int main () {
    int input;
    bool is_even;
    bool is_div_by_3;
    std::string output;

    std::cout << "~~1 if Even, 2 if Odd, 3 if div2, 4 id div3~~" << std::endl;
    std::cout << "Input Number: " << std::ends;

    std::cin >> input;

    if (input % 2 == 0) {
        is_even = true;
    }
    else {
        is_even = false;
    }

    if (input % 3 == 0) {
        is_div_by_3 = true;
    }
    else {
        is_div_by_3 = false;
    }

    if (is_even && is_div_by_3) {
        output = "134";
    }
    else if (is_even && !is_div_by_3) {
        output = "13";
    }
    else if (!is_even && is_div_by_3) {
        output = "24";
    }
    else if (!is_even && !is_div_by_3) {
        output = "";
    }

    std::cout << "Output: " << output << std::endl;

}