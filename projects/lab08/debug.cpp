#include <iostream>

void foo(int x, int *someP) {
    *someP = x + 1;
    x = 80;
}

int main() {
    int a = 30;
    int b = 60;
    int *p = &a;
    int *z = &b;

    *p = 12;
    b = a;
    *p = 21;

    std::cout << "1: a=" << a << ", b=" << b << std::endl;
    foo(a, z);
    std::cout << "2: a=" << a << ", b=" << b << std::endl;

    *p = 1;
    p = z;
    *p = 3;

    std::cout << "3: a=" << a << ", b=" << b << std::endl;

    return 0;
}