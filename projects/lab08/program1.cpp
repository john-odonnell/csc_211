#include <iostream>

void square(int *ptr) {
    *ptr = *ptr * *ptr;
}

int main() {
    int a = 6;
    int *ptr = &a;

    square(ptr);

    std::cout << *ptr << std::endl;

    return 0;
}