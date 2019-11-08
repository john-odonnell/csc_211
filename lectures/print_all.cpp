#include <iostream>

void printall(char *A, int idx, int len) {
    if (idx == len) {
        A[idx] = '\0';
        std::cout << A << std::endl;
        return;
    }

    A[idx] = 'A';
    printall(A, idx + 1, len);
    A[idx] = 'B';
    printall(A, idx + 1, len);
    A[idx] = 'C';
    printall(A, idx + 1, len);
    A[idx] = 'D';
    printall(A, idx + 1, len);
}

int main() {
    int n;
    std::cin >> n;
    char A[n + 1];

    printall(A, 0, n);

    return 0;
}