#include <iostream>
#include <iomanip>

void leading_spaces() {

}

void middle_spaces() {

}

void top() {
    leading_spaces()
    std::cout << "*"
    middle_spaces()
    std::cout << "*"
}

void bottom() {

}

int main () {
    int n;
    std::cin >> n;

    float middle = n / 2;

    if (n % 2 != 0) {
        top()
        bottom()
    }
    else {
        std::cout << "Sorry, not odd" << std::endl;
    }

    return 0;
}