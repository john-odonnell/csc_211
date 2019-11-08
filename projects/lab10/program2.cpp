#include <iostream>

int changeCombos(int amount, int values[]) {
    if (amount == 0) {
        return 1;
    }
    else if (amount < 0) {
        return 0;
    }
    else {
        return changeCombos(amount - values[0], values) +
            changeCombos(amount - values[1], values) +
            changeCombos(amount - values[2], values) +
            changeCombos(amount - values[3], values);
    }
}

int main() {
    int amount;
    std::cin >> amount;

    int values[] = {25, 10, 5, 1};

    int combos = changeCombos(amount, values);

    std::cout << combos << std::endl;
    return 0;
}