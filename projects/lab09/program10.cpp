#include <iostream>
#include <iomanip>

bool is_sorted(int *arr, int n) {
    if (n == 0) {
        return true;
    }
    else if (*arr <= *(arr + 1)) {
        return is_sorted(arr + 1, n - 1);
    }
    else {
        return false;
    }
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 4, 6, 7, 8, 9};

    std::cout << is_sorted(arr, 10) << std::endl;

    return 0;
}