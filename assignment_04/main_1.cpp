#include <iostream>
#include <iomanip>

void sudokuInput(int arr[][9]) {
    int this_digit;
    // take 81 int values as input
    // store them in the array in row column order
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> this_digit;
            arr[i][j] = this_digit;
        }
    }

    return;
}

bool checkRow(int arr[][9], int row, int column) {
    // check the value in question against all the values in its row to the right
    for (int i = column + 1; i < 9; i++) {
        if (arr[row][column] == arr[row][i]) {
            return false;
        }
    }
    return true;
}

bool checkColumn(int arr[][9], int row, int column) {
    // check the value in question against all the values in its column below
    for (int i = row + 1; i < 9; i++) {
        if (arr[row][column] == arr[i][column]) {
            return false;
        }
    }
    return true;
}

void getTopBottomLeftRight(int row, int column, int *top, int *bottom, int *left, int *right) {
    // establishes values for top and bottom based on current row
    if (row == 0 || row == 1 || row == 2) {
        *top = 0;
        *bottom = 2;
    }
    else if (row == 3 || row == 4 || row == 5) {
        *top = 3;
        *bottom = 5;
    }
    else {
        *top = 6;
        *bottom = 8;
    }
    // established values for left and right based on current column
    if (column == 0 || column == 1 || column == 2) {
        *left = 0;
        *right = 2;
    }
    else if (column == 3 || column == 4 || column == 5) {
        *left = 3;
        *right = 5;
    }
    else {
        *left = 6;
        *right = 8;
    }
}

bool checkBox(int arr[][9], int row, int column) {
    int top, bottom, left, right;
    // get values referencing the top, bottom, left and right sides of the box
    getTopBottomLeftRight(row, column, &top, &bottom, &left, &right);

    // check all other members of the box for value collision
    for (int i = left; i <= right; i++) {
        for (int j = top; j <= bottom; j++) {
            if (i != column && j != row) {
                if (arr[row][column] == arr[j][i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkSudoku(int arr[][9], int row, int column) {
    // base case
    // if the function passes the final row, return true
    if (row == 9) {
        return true;
    }
    // if the value in the board is out of the acceptable range, return false
    else if (arr[row][column] > 9 || arr[row][column] < 1) {
        return false;
    }
    else {
        // check the row, column, and box of the index in question
        bool rowCheck = checkRow(arr, row, column);
        bool columnCheck = checkColumn(arr, row, column);
        bool boxCheck = checkBox(arr, row, column);

        // if the row, column, and box test pass, recursive call for the next index
        if (rowCheck && columnCheck && boxCheck) {
            return checkSudoku(arr, row + 1, (column + 1) % 9);
        }
        // otherwise, return false
        else {
            return false;
        }
    }
}

int main() {
    // establish 9 x 9 sudoku board
    int arr[9][9];
    std::string output;

    // fill the sudoku board from input
    sudokuInput(arr);

    // check the board for collisions
    bool solution = checkSudoku(arr, 0, 0);

    // print the results
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