#include <iostream>
#include <iomanip>
#include <math.h>

void collectInput(int n, double xArr[], double yArr[], char cArr[]) {
    for (int i = 0; i < n; i++) {
        std::cin >> xArr[i] >> yArr[i] >> cArr[i];
    }
}

void distances(double x, double y, double xArr[], double yArr[], int n, double distArr[]) {
    int highest;
    int highestIndex;
    for (int i = 0; i < n; i++) {
        double diffX = abs(x - xArr[i]);
        double diffY = abs(y - yArr[i]);
        double dist = sqrt(pow(diffX, 2) + pow(diffY, 2));

        distArr[i] = dist;
    }
    return;
}

void sort(int n, double distArr[], char cArr[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (distArr[j - 1] > distArr[j]) {
                std::swap(distArr[j - 1], distArr[j]);
                std::swap(cArr[j - 1], cArr[j]);
            }
        }
    }
}

void countRsBs(int k, int *ptrR, int *ptrB, char cArr[]) {
    for (int i = 0; i < k; i++) {
        if (cArr[i] == 'R') {
            *ptrR = *ptrR + 1;
        }
        else if (cArr[i] == 'B') {
            *ptrB = *ptrB + 1;
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    double xArr[n], yArr[n], distArr[n];
    char cArr[n];

    collectInput(n, xArr, yArr, cArr);

    double x, y;
    std::cin >> x >> y;

    distances(x, y, xArr, yArr, n, distArr);
    sort(n, distArr, cArr);

    int numR = 0; int numB = 0;
    int *ptrR = &numR; int *ptrB = &numB;
    countRsBs(k, ptrR, ptrB, cArr);

    if (numB > numR) {
        std::cout << 'B' << std::endl;
    }
    else if (numR > numB) {
        std::cout << 'R' << std::endl;
    }

    return 0;
}

// WORKS