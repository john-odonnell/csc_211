#include <iostream>
#include <iomanip>

unsigned int arr_len(int arr[]) {
    int counter = 0;
    while (arr[counter]) {
        counter++;
    }
    return counter;
}

bool sorted(int arr[], int length) {
    bool sorted = true;
    bool complete = false;

    while (sorted && !complete) {
        for (int i = 1; i < length; i++) {
            if (arr[i - 1] < arr[i]) {
                sorted = false;
            }
        }
        complete = true;
    }

    return sorted;
}

int main() {
    int arr[100];
    int value;
    int input_counter = 0;

    while (std::cin >> value) {
        arr[input_counter] = value;
        input_counter++;
    }

    if (sorted(arr, input_counter)) {
        std::cout << "Sorted" << std::endl;
    }
    else {
        std::cout << "Not Sorted" << std::endl;
    }

    return 0;
}

// WORKS