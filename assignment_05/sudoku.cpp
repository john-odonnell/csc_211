#include "sudoku.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// reads a file containing a sudoku puzzle represented as
// 9 rows, each consisting of 9 comma-separated values
Sudoku::Sudoku(const char *fname) {
    // create a file reader stream to read data from a file
    ifstream infile;

    // will store lines and numbers
    string line, number;

    // index to write value to in puzzle
    int i = 0;

    // open a stream to the given file
    infile.open(fname);

    // get a line of input from the file
    while(getline(infile, line)) {
        // store the line inside a stringstream
        stringstream parser(line);
        // use stringstream to split line along ','
        while(getline(parser, number, ',')) {
            // convert string to an integer, store it, and update iterator
            puzzle[i++] = stoi(number);
        }
    }
    // close the filestream once we are done wiht it
    infile.close();
}

// destruct Sudoku object
Sudoku::~Sudoku() {
    // since we never allocated any memory on the heap, we don't need
    // to define behavior for the deconstructor
}

// this is the funciton call which will be made by the autograder to test
// your implementation for problem 3. It takes no parameters and
// should overwrite the 0s in puzzle to so that it represents a solved puzzle
void Sudoku::solve() {
    bool *solved = new bool {false};
    bool *found = new bool[81] {false};
    int possBoard[81][11];
    _initPossBoard(possBoard, found);
    _fillPossBoard(possBoard, found);
    _extrapolate(possBoard, found, 1);
    *solved = _checkSolved(found);
    if (*solved == false) {
        _solve(0, possBoard, solved, found);
    }

    delete [] found;
    delete solved;

    return;
}

void Sudoku::_initPossBoard(int possBoard[81][11], bool found[81]) {
    for (int i = 0; i < 81; i++) {
        possBoard[i][0] = this->puzzle[i];
        possBoard[i][10] = 0;
        for (int j = 1; j < 10; j++) {
            possBoard[i][j] = 0;
            if (this->puzzle[i] == j) {
                possBoard[i][j] = 1;
                possBoard[i][10] = -1;
                found[i] = true;
            }
        }
    }
    return;
}

void Sudoku::_fillPossBoard(int possBoard[81][11], bool found[81]) {
    for (int i = 0; i < 81; i++) {
        if (!found[i]) {
            for (int j = 1; j < 10; j++) {
                int col = i % 9;
                int row = (i - col) / 9;
                if (_checkPlacement(j, row, col)) {
                    possBoard[i][j] = 1;
                    possBoard[i][10]++;
                }
            }
        }
    }
}

bool Sudoku::_checkPlacement(int place, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (place == puzzle[(row * 9) + i]) {
            return false;
        }
        if (place == puzzle[(i * 9) + col]) {
            return false;
        }
    }

    int *top = new int {0};
    int *bottom = new int {0};
    int *left = new int {0};
    int *right = new int {0};
    _topBottomLeftRight(row, col, top, bottom, left, right);
    for (int i = *top; i <= *bottom; i++) {
        for (int j = *left; j <= *right; j++) {
            if (!((i == row) && (j == col))) {
                if (this->puzzle[(i * 9) + j] == place) {
                    return false;
                }
            }
        }
    }

    return true;
}

void Sudoku::_topBottomLeftRight(int row, int col, int *top, int *bottom, int *left, int *right) {
    if ((col >= 0) && (col <= 2)) {
        *left = 0;
        *right = 2;
    }
    else if ((col >= 3) && (col <= 5)) {
        *left = 3;
        *right = 5;
    }
    else if ((col >= 6) && (col <= 8)) {
        *left = 6;
        *right = 8;
    }

    if ((row >= 0) && (row <= 2)) {
        *top = 0;
        *bottom = 2;
    }
    else if ((row >= 3) && (row <= 5)) {
        *top = 3;
        *bottom = 5;
    }
    else if ((row >= 6) && (row <= 8)) {
        *top = 6;
        *bottom = 8;
    }
    return;
}

void Sudoku::_extrapolate(int possBoard[81][11], bool found[81], int count) {
    if (count == 0) {
        return;
    }
    else {
        count = 0;
        for (int i = 0; i < 81; i++) {
            if (possBoard[i][10] == 1) {
                int j = 1;
                while (possBoard[i][j] != 1) {
                    j++;
                }
                possBoard[i][0] = j;
                possBoard[i][10] = -1;
                this->puzzle[i] = j;
                found[i] = true;
                count++;
                _updatePulse(possBoard, i, j);
            }
        }
        return _extrapolate(possBoard, found, count);
    }
}

void Sudoku::_updatePulse(int possBoard[81][11], int idx, int val) {
    int col = idx % 9;
    int row = (idx - col) / 9;

    for (int i = 0; i < 9; i++) {
        if (possBoard[(row * 9) + i][val] == 1) {
            possBoard[(row * 9) + i][val] = 0;
            possBoard[(row * 9) + i][10]--;
        }
        if (possBoard[(i * 9) + col][val] == 1) {
            possBoard[(i * 9) + col][val] = 0;
            possBoard[(i * 9) + col][10]--;
        }
    }

    int *top = new int {0};
    int *bottom = new int {0};
    int *left = new int {0};
    int *right = new int {0};
    _topBottomLeftRight(row, col, top, bottom, left, right);
    for (int i = *top; i <= *bottom; i++) {
        for (int j = *left; j <= *right; j++) {
            if (!((i == row) && (j == col))) {
                if (possBoard[(i * 9) + j][val] == 1) {
                    possBoard[(i * 9) + j][val] = 0;
                    possBoard[(i * 9) + j][10]--;
                }
            }
        }
    }
}

bool Sudoku::_checkSolved(bool found[81]) {
    int i = 0;
    for (int i = 0; i < 81; i++) {
        if (found[i] == false) {
            return false;
        }
    }
    return true;
}

void Sudoku::_solve(int idx, int possBoard[81][11], bool *solved, bool found[81]) {
    if (idx == 81) {
        *solved = true;
        return;
    }
    else if (this->puzzle[idx] != 0) {
        _solve(idx + 1, possBoard, solved, found);
        return;
    }
    else {
        for (int i = 1; i < 10; i++) {
            int col = idx % 9;
            int row = (idx - col) / 9;
            if (possBoard[idx][i] == 1 && _checkPlacement(i, row, col)) {
                int place = i;
                this->puzzle[idx] = place;
                found[idx] = true;

                _solve(idx + 1, possBoard, solved, found);
                if (*solved == true) {
                    return;
                }

                this->puzzle[idx] = 0 ;
                found[idx] = false;
            }
        }
        return;
    }
}

// this function prints your puzzle in 2D format with commas
// separating your values
void Sudoku::print() {
    for(int i = 0; i < 9; i++) {
        std::cout << puzzle[i*9];
        int base = i*9;
        for(int offset = 1; offset < 9; offset++) {
            std::cout << ',' << puzzle[base + offset];
        }
        std::cout << std::endl;
    }
}