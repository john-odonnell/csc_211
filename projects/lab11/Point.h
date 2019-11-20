#ifndef __point_h__
#define __point_h__
#include <string>

class Point {
    private:
        int x;
        int y;
        int z;

    public:
        Point(int a, int b, int c);

        void setX(int a);
        void setY(int b);
        void setZ(int c);

        int getX();
        int getY();
        int getZ();

        std::string toCord();

        double euDistance(Point p2);
};

#endif