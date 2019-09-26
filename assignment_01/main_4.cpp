#include <iostream>
#include <iomanip>

int main () {
    int a, b, ans;
    char c;

    std::cout << "~~Calculator~~" << std::endl;
    std::cout << "Enter two numbers, and the operation you'd like to perform: " << std::endl;

    std::cin >> a >> b >> c;

    if (c == '*') {
        ans = a * b;
    }
    else if (c == '/') {
        ans = a / b;
    }
    else if (c == '+') {
        ans = a + b;
    }
    else if (c == '-') {
        ans = a - b;
    }

    std::cout << a << " " << c << " " << b << " = " << ans << std::endl;

    return 0;
}