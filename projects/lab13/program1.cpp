#include <vector>
#include <iostream>

int main() {
    int size;
    std::cout << "Vector Size: ";
    std::cin >> size;

    std::vector<int> vec = {};

    for (int i = 0; i < size; i++) {
        vec.push_back(i);
    }

    for (int i = 0; i < size; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}