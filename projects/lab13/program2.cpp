#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int input;

    while (true) {
        std::cout << "Input: ";
        std::cin >> input;
        if (input == 0) {
            break;
        }
        vec.push_back(input);
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}