#include <iostream>
#include <iomanip>

int main () {
    int a, b, ans;  // instantiate a b ans
    char c;         // and operation character c

    // push strings to the output streams
    std::cout << "~~Calculator~~" << std::endl;
    std::cout << "Enter two numbers, and the operation you'd like to perform: " << std::endl;

    // push input stream to a b and c
    std::cin >> a >> b >> c;

    if (c == '*') {         // if op char is *
        ans = a * b;        // multiple
    }
    else if (c == '/') {    // if op char is /
        ans = a / b;        // divide
    }
    else if (c == '+') {    // if op char is +
        ans = a + b;        // add
    }
    else if (c == '-') {    // if op char is -
        ans = a - b;        // subtract
    }

    // push results to the output stream
    std::cout << a << " " << c << " " << b << " = " << ans << std::endl;

    return 0;
}