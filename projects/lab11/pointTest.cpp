#include <iostream>
#include "Point.h"
using namespace std;

//No need to touch the main.cpp file. However - if might be helpfull
//to look at how I'm using your soon-to-be defined Point.cpp class

int main(){

    Point myPt(10, 5, 8);
    Point myPt2(3, 10, 15);

    int myX = myPt.getX();

    cout << myX << endl;

    cout << myPt.toCord() << endl;

    myPt.setX(3);

    cout << myPt.toCord() << endl;

    cout << myPt.euDistance(myPt2) << endl;

return 0;
}