#include <iostream>
int main () {
    int test = 0;
    // the if statement used the assignment opperator instead
    // of the equality operator
    if (test == 10) {
        std::cout << "Hello World" << std::endl;
    }
    else {
        std::cout << "foo bar" << std::endl;
    }
    return 0;
}