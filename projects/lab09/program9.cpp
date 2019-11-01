#include <iostream>
#include <iomanip>

void print_level(int level) {
    for (int i = 0; i < level; i++) {
        std::cout << "+";
    }
    std::cout << std::endl;
    return;
}

void pyr(int levels, int current_level) {
    if (current_level == levels + 1) {
        return;
    }
    else {
        print_level(current_level);
        pyr(levels, current_level + 1);
        print_level(current_level);

        return;
    }
}

int main() {
    int n;
    std::cin >> n;

    pyr(n, 0);

    return 0;
}