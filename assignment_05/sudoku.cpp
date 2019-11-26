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
    // TODO:
    // implement solution to problem 3

    // This is where your private helper method which does the
    // backtracking should be called
    bool *solved;
    *solved = false;
    this->_solve(0, 0, this->puzzle, solved);
    return;
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

bool Sudoku::_checkPlacement(int place, int row, int col, int puzzle[81]) {
    for (int i = 0; i < 9; i++) {
        if (place == puzzle[(row * 9) + i]) {
            return false;
        }
        if (place == puzzle[(i * 9) + col]) {
            return false;
        }
    }

    int *top; int *bottom; int *left; int *right;
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

void Sudoku::_solve(int row, int col, int puzzle[81], bool *solved) {
    cout << ((row * 9) + col) << endl;
    if (((row * 9) + col) == 81) {
        *solved = true;
        return;
    }
    else {
        while (this->puzzle[(row * 9) + col] != 0) {
            if ((col + 1) == 9) {
                row++;
                col = 0;
            }
            else {
                col++;
            }
        }
        int place = 1;
        while (*solved == false) {
            if (!_checkPlacement(place, row, col, puzzle)) {
                place++;
            }
            this->puzzle[(row * 9) + col] = place;
            if ((col + 1) == 9) {
                _solve(row + 1, 0, puzzle, solved);
            }
            else {
                _solve(row, col + 1, puzzle, solved);
            }
        }
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