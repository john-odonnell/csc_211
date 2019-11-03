#include <iostream>
#include <iomanip>

int sum(int *arr, int n) {
    if (n == 0) return 0;
    else {
        return *arr + sum(arr + 1, n - 1);
    }
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5};
    int *ptr = &arr[0];

    std::cout << sum(ptr, 6) << std::endl;

    return 0;
}