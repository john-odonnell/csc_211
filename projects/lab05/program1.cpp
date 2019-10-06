#include <iostream>
#include <iomanip>

int add(int a, int b) {
    int c = a + b;
    return c;

}

int mult(int a, int b) {
    int total = 0;
    for (b; b > 0; b--) {
        total += a;
    }
    return total;
}

int expo(int a, int b) {
    int total = 1;
    for (b; b > 0; b--) {
        total *= a;
    }
    return total;
}

int main() {
    std::cout << expo(2,6) << std::endl;
}