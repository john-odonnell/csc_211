#include <iostream>

int main() {
    int * pnt = new int[5];
    int * pntMax;

    int value;

    int i = 0;
    while(std::cin >> value) {
        pnt[i] = value;
        if (i = 0) {
            pntMax = &pnt[i];
        }
        else {
            if (value > *pntMax) {
                pntMax = &pnt[i];
            }
        }

        i++;
    }

    std::cout << *pntMax << std::endl;

    return 0;
}