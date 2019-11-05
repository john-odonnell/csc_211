#include <iostream>
#include <iomanip>

void move(int *ptr0, int *ptrNext) {
    *ptr0 = *ptrNext;
    *ptrNext = 0;
    return;
}

void changeWithInput(int board[][3], int *leftColumn[], int *rightColumn[], int *ptr0) {
    char direction;

    while (std::cin >> direction) {
        bool onLeft = false;
        bool onRight = false;
        for (int i = 0; i < 3; i++) {
            if (ptr0 == leftColumn[i]) {
                onLeft = true;
            }
            if (ptr0 == rightColumn[i]) {
                onRight = true;
            }
        }

        switch (direction) {
            case 'U':
                if (ptr0 > &board[0][2]) {
                    move(ptr0, ptr0 - 3);
                    ptr0 -= 3;
                }
                break;
            case 'D':
                if (ptr0 < &board[2][0]) {
                    move(ptr0, ptr0 + 3);
                    ptr0 += 3;
                }
                break;
            case 'L':
                if (!onLeft) {
                    move(ptr0, ptr0 - 1);
                    ptr0 -= 1;
                }
                break;
            case 'R':
                if (!onRight) {
                    move(ptr0, ptr0 + 1);
                    ptr0 += 1;
                }
                break;
        }
    }
}

int main() {
    int board[3][3];
    int solved[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    int *leftColumn[3];
    int *rightColumn[3];
    int *ptr0;
    std::string output;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> board[i][j];
            if (board[i][j] == 0) {
                ptr0 = & board[i][j];
            }
            if (j == 0) {
                leftColumn[i] = &board[i][j];
            }
            if (j == 2) {
                rightColumn[i] = &board[i][j];
            }
        }
    }

    changeWithInput(board, leftColumn, rightColumn, ptr0);

    bool solution = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != solved[i][j]) {
                solution = false;
            }
        }
    }

    if (solution) {
        output = "Solution is good!";
    }
    else {
        output = "Wrong solution!";
    }

    std::cout << output << std::endl;

    return 0;
}

// WORKS