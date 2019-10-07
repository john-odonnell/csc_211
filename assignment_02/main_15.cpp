#include <iostream>
#include <iomanip>

void top_bottom_line(int n) {
    std::cout << "#";
    for (int i = 0; i < 2 * n; i++) {
        std::cout << "==";
    }
    std::cout << "#" << std::endl;
}

void spaces(int n, int l) {

}

void middle_to_middle(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "|";

    }
}

void middle_to_bottom(int n) {

}

void a_lovely_rug(int n) {
    top_bottom_line(n);
    middle_to_middle(n);
    middle_to_bottom(n);
    top_bottom_line(n);
}

int main() {
    int n;
    std::cin >> n;

    a_lovely_rug(n);

    return 0;
}