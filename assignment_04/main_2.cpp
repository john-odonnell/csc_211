#include <iostream>
#include <iomanip>

void fillFirstPointers(char *first_ptrs[], char *first_ptr, int m, int n) {
    for (int i = 0; i < m; i++) {
        first_ptrs[i] = first_ptr;
        first_ptr += n;
    }
    return;
}

void fillLastPointers(char *last_ptrs[], char *last_ptr, int m, int n) {
    for (int i = 0; i < m; i++) {
        last_ptrs[i] = last_ptr;
        last_ptr -= n;
    }
    return;
}

int check(char *ptr) {
    if (*ptr == '*') {
        return 1;
    }
    return 0;
}

int checkNeighbors(char *ptr, char *first_ptrs[], char *last_ptrs[], int m, int n) {
    bool inFirstPointers = false;
    bool inLastPointers = false;
    for (int i = 0; i < m; i++) {
        if (ptr == first_ptrs[i]) {
            inFirstPointers = true;
        }
        if (ptr == last_ptrs[i]) {
            inLastPointers = true;
        }
    }

    int U = 0;
    int UR = 0;
    int R = 0;
    int DR = 0;
    int D = 0;
    int DL = 0;
    int L = 0;
    int UL = 0;
    bool checkU = false;
    bool checkD = false;
    bool checkL = false;
    bool checkR = false;
    if (ptr < first_ptrs[m - 1]) {
        D = check(ptr + n);
        checkD = true;
    }
    if (ptr > last_ptrs[m - 1]) {
        U = check(ptr - n);
        checkU = true;
    }
    if (!inFirstPointers) {
        L = check(ptr - 1);
        checkL = true;
    }
    if (!inLastPointers) {
        R = check(ptr + 1);
        checkR = true;
    }
    if (checkD && checkR) {
        DR = check(ptr + n + 1);
    }
    if (checkD && checkL) {
        DL = check(ptr + n - 1);
    }
    if (checkU && checkR) {
        UR = check(ptr - n + 1);
    }
    if (checkU && checkL) {
        UL = check(ptr - n - 1);
    }

    return U + UR + R + DR + D + DL + L + UL;
}

void updateGrid(char *ptr, char *first_ptrs[], char *last_ptrs[], int m, int n) {
    if (ptr > last_ptrs[0]) {
        return;
    }
    else {
        int neighbors = checkNeighbors(ptr, first_ptrs, last_ptrs, m, n);

        updateGrid(ptr + 1, first_ptrs, last_ptrs, m, n);

        if (*ptr == '*') {
            if (neighbors < 2 || neighbors > 3) {
                *ptr = '.';
            }
        }
        else {
            if (neighbors == 3) {
                *ptr = '*';
            }
        }

        return;
    }
}

void outputGrid(char *ptr, char *last_ptrs[], int m, int n) {
    for (int i = 1; i <= (m * n); i++) {
        std::cout << *ptr;
        if (i % n == 0) {
            std::cout << std::endl;
        }
        else {
            std::cout << " ";
        }

        ptr++;
    }
}

int main() {
    int m, n, g;
    std::cin >> m >> n >> g;

    char arr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> arr[i][j];
        }
    }

    char *first_ptrs[m];
    char *last_ptrs[m];
    fillFirstPointers(first_ptrs, &arr[0][0], m, n);
    fillLastPointers(last_ptrs, &arr[m - 1][n - 1], m, n);

    for (int i = 0; i < g; i++) {
        updateGrid(&arr[0][0], first_ptrs, last_ptrs, m, n);
    }

    outputGrid(&arr[0][0], last_ptrs, m, n);

    return 0;
}

// WORKS