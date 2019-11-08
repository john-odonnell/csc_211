#include <iostream>

int foo(int a) {
    if(a < 3) {
        return a;
    }

    return foo(a-3) + foo(a-2) + foo(a-1);
}

int main() {
    std::cout << foo(5) << std::endl;
    return 0;
}