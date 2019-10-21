#include <iostream>
#include <iomanip>

int updateX(int currentX, int value) {
    int changeToX[] = {2, 2, 1, -1, -2, -2, -1, 1};
    int updatedX = currentX + changeToX[value];
    return updatedX;
}

int updateY(int currentY, int value) {
    int changeToY[] = {1, -1, -2, -2, -1, 1, 2, 2};
    int updatedY = currentY + changeToY[value];
    return updatedY;
}

int main() {
    int startingX, startingY;
    int currentX, currentY;

    int value;

    std::cin >> startingX >> startingY;
    currentX = startingX;
    currentY = startingY;

    bool invalid = false;
    while ((std::cin >> value) && (!invalid)) {
        currentX = updateX(currentX, value);
        currentY = updateY(currentY, value);

        if ((currentX < 1) || (currentX > 8) ||
            (currentY < 1) || (currentY > 8))
        {
            std::cout << "Invalid sequence" << std::endl;
            invalid = true;
        }
    }

    if ((currentX > 0) && (currentX < 9) &&
        (currentY > 0) && (currentY < 9))
    {
        std::cout << currentX << " " << currentY << std::endl;
    }

    return 0;
}