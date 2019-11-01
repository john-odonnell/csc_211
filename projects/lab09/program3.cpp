#include <iostream>
#include <iomanip>

void print_rev_arr(int *arr, int n) {
    if (n == 0) {
        return;
    }
    else {
        print_rev_arr(arr + 1, n - 1);
        std::cout << *arr << std::endl;
        return;
    }
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = &arr[0];

    print_rev_arr(ptr, 10);

    return 0;
}