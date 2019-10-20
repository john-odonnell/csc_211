#include <iostream>

void selection_sort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int lowest_val = arr[i];
        int lowest_index = i;

        for (int j = i + 1; j < length; j++) {
            if (arr[j] < lowest_val) {
                lowest_val = arr[j];
                lowest_index = j;
            }
        }

        if (i != lowest_index) {
            std::swap(arr[i], arr[lowest_index]);
        }
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selection_sort(arr, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}