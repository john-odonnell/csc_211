#include <iostream>

void countEvens(int numbers[], int *ptr) {
    int count = 0;
    int *lastPnt = &numbers[10];

    while (ptr < lastPnt) {
        if (*ptr % 2 == 0) {
            count++;
        }
        ptr++;
    }

    std::cout << count << std::endl;

    return;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr = &numbers[0];

    countEvens(numbers, ptr);

    return 0;
}