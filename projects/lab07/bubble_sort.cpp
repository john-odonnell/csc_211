#include <iostream>

void bubble_sort(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 1; j < length - i; j++) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubble_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}