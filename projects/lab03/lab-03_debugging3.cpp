#include <iostream>
int main () {
    int test = 0;
    // original version did not include curly braces around the if statement
    if (test == 0) {
        std::cout << "Hello World" << std::endl;
        std::cout << "Hello World2" << std::endl;
    }
    else {
        std::cout << "foo bar" << std::endl;
    }
    return 0;
}