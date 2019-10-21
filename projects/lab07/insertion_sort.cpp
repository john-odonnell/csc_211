#include <iostream>

void insertion_sort(int arr[], int length) {
    int value;
    int j;
    int sorted = 0;

    for (int i = sorted + 1; i < length; i++) {
        value = arr[i];
        j = i - 1;

        while ((j >= 0) && (arr[j] > value)) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = value;
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    insertion_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}