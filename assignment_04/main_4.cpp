#include <iostream>
#include <iomanip>
#include <math.h>

void distances(double x, double y, double xArr[], double yArr[], int n, int k, double distArr[], int nearestArr[]) {
    for (int i = 0; i < n; i++) {
        double diffX = abs(x - xArr[i]);
        double diffY = abs(y - yArr[i]);
        double dist = sqrt(pow(diffX, 2) + pow(diffY, 2));

        distArr[i] = dist;

        if (i < k) {
            nearestArr[i] = i;
        }
        else {
            int j = 0;
            bool inNearest = false;
            while (j < k && !inNearest) {
                if (dist < nearestArr[j]) {
                    nearestArr[j] = i;
                    inNearest = true;
                }
                else {
                    j++;
                }
            }
        }
    }
    return;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    double xArr[n], yArr[n];
    char cArr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> xArr[i] >> yArr[i] >> cArr[i];
    }

    double x, y;
    std::cin >> x >> y;

    double distArr[n];
    int nearestArr[k];
    distances(x, y, xArr, yArr, n, k, distArr, nearestArr);

    int numR = 0; int numB = 0;
    for (int i = 0; i < k; i++) {
        if (cArr[nearestArr[i]] == 'R') {
            numR++;
        }
        else if (cArr[nearestArr[i]] == 'B') {
            numB++;
        }
    }

    if (numB > numR) {
        std::cout << 'B' << std::endl;
    }
    else {
        std::cout << 'R' << std::endl;
    }

    return 0;
}

// WORKS