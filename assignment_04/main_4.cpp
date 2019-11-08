#include <iostream>
#include <iomanip>
#include <math.h>

void collectInput(int n, double xArr[], double yArr[], char cArr[]) {
    for (int i = 0; i < n; i++) {
        std::cin >> xArr[i] >> yArr[i] >> cArr[i];
    }
}

int findHighest(int nearestArr[], double distArr[], int k) {
    int index = 0;
    int highest = distArr[nearestArr[index]];
    for (int i = 1; i < k; i++) {
        if (distArr[nearestArr[i]] > highest) {
            highest = distArr[nearestArr[i]];
            index = i;
        }
    }
    return index;
}

void distances(double x, double y, double xArr[], double yArr[], int n, int k, double distArr[], int nearestArr[]) {
    int highest;
    int highestIndex;
    for (int i = 0; i < n; i++) {
        double diffX = abs(x - xArr[i]);
        double diffY = abs(y - yArr[i]);
        double dist = sqrt(pow(diffX, 2) + pow(diffY, 2));

        //std::cout << i << std::endl;
        //std::cout << dist << std::endl;

        distArr[i] = dist;

        if (i < k) {
            nearestArr[i] = i;
        }
        else {
            int highestIndex = findHighest(nearestArr, distArr, k);
            //std::cout << highestIndex << std::endl;
            if (dist < distArr[nearestArr[highestIndex]]) {
                nearestArr[highestIndex] = i;
            }
        }

        //for (int i = 0; i < k; i++) {
            //std::cout << nearestArr[i] << " ";
        //}
        //std::cout << std::endl;
    }
    return;
}

void countRsBs(int k, int *ptrR, int *ptrB, char cArr[], int nearestArr[]) {
    for (int i = 0; i < k; i++) {
        if (cArr[nearestArr[i]] == 'R') {
            *ptrR = *ptrR + 1;
            //std::cout << "R: " << *ptrR << std::endl;
        }
        else if (cArr[nearestArr[i]] == 'B') {
            *ptrB = *ptrB + 1;
            //std::cout << "B: " << *ptrB << std::endl;
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    double xArr[n], yArr[n];
    char cArr[n];

    collectInput(n, xArr, yArr, cArr);

    double x, y;
    std::cin >> x >> y;

    double distArr[n];
    int nearestArr[k];
    distances(x, y, xArr, yArr, n, k, distArr, nearestArr);

    int numR = 0; int numB = 0;
    int *ptrR = &numR; int *ptrB = &numB;
    countRsBs(k, ptrR, ptrB, cArr, nearestArr);

    if (numB > numR) {
        std::cout << 'B' << std::endl;
    }
    else if (numR > numB) {
        std::cout << 'R' << std::endl;
    }

    return 0;
}

// DOES NOT WORK: 37/50