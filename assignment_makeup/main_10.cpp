#include <iostream>
#include <iomanip>

void top_bottom_line(int n) {
    std::cout << "#";
    for (int i = 0; i < 2 * n; i++) {
        std::cout << "==";
    }
    std::cout << "#" << std::endl;
}

void spaces(int n) {
    for (int i = n; i > 0; i --) {
        std::cout << "  ";
    }
}

void dots(int line) {
    for (int i = line; i > 0; i--) {
        std::cout << "....";
    }
}

void middle_to_middle(int n) {
    int line = 0;
    for (int i = n - 1; i >= 0; i--) {
        std::cout << "|";
        spaces(i);
        std::cout << "<>";
        dots(line);
        std::cout << "<>";
        spaces(i);
        std::cout << "|" << std::endl;
        line++;
    }
}

void middle_to_bottom(int n) {
    int line = n - 1;
    for (int i = 0; i <= n - 1; i++) {
        std::cout << "|";
        spaces(i);
        std::cout << "<>";
        dots(line);
        std::cout << "<>";
        spaces(i);
        std::cout << "|" << std::endl;
        line--;
    }
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