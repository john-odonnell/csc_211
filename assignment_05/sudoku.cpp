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
    // found represents if each position has an extablished value
    bool *found = new bool[81] {false};
    // initialize 2D array of possible values of each idx
    int possBoard[81][11];
    // fill the board of possible values from the input puzzle
    _initPossBoard(possBoard, found);
    // fill each idx's array of possible values
    _fillPossBoard(possBoard, found);
    // use possible value data to extrapolate other known values
    _extrapolate(possBoard, found, 1);
    // check if the puzzle was solved by extrapolation
    *solved = _checkSolved(found);
    // if the puzzle was not solved by extrapolation, solve by brute force
    if (*solved == false) {
        _solve(0, possBoard, solved, found);
    }

    // delete dynamically allocated data
    delete [] found;
    delete solved;

    return;
}

// initializes the board of possible values based on the input puzzle
void Sudoku::_initPossBoard(int possBoard[81][11], bool found[81]) {
    // for each idx of the board...
    for (int i = 0; i < 81; i++) {
        // store the input value in the first index of the subarray
        possBoard[i][0] = this->puzzle[i];
        // [i][10] stores the number of values the idx can have
        possBoard[i][10] = 0;
        // for each number 1 through 9...
        for (int j = 1; j < 10; j++) {
            // 0 is assigned to [i][j], indicating j is not a possible value
            possBoard[i][j] = 0;
            // if the input puzzle already has a value stored at the idx represented...
            if (this->puzzle[i] == j) {
                // the value is represented as possible with a 1
                possBoard[i][j] = 1;
                // the possible value counter is set to -1, indicating it is known
                possBoard[i][10] = -1;
                // the idx's found state is set to true
                found[i] = true;
            }
        }
    }
    return;
}

// fills the subarrays of the board of possible values with possible values of unknown idxs
void Sudoku::_fillPossBoard(int possBoard[81][11], bool found[81]) {
    // for each idx in the puzzle...
    for (int i = 0; i < 81; i++) {
        // if the value at that idx has not been found...
        if (!found[i]) {
            // for each digit 1 through 9...
            for (int j = 1; j < 10; j++) {
                int col = i % 9;
                int row = (i - col) / 9;
                // if the digit is a possible value...
                if (_checkPlacement(j, row, col)) {
                    // [i][j] is set to 1, indicating j is a possible value
                    possBoard[i][j] = 1;
                    // the idx's possible value counter is incremented
                    possBoard[i][10]++;
                }
            }
        }
    }
}

// checks the placement of a value at an idx
bool Sudoku::_checkPlacement(int place, int row, int col) {
    // checks if the value is already present in the idx's row/column
    for (int i = 0; i < 9; i++) {
        // check row
        if (place == puzzle[(row * 9) + i]) {
            return false;
        }
        // check column
        if (place == puzzle[(i * 9) + col]) {
            return false;
        }
    }

    // pointers representing the top, bottom, left and right of the
    // 3x3 box which contains the current idx
    int *top = new int {0};
    int *bottom = new int {0};
    int *left = new int {0};
    int *right = new int {0};
    // assign values to the pointers
    _topBottomLeftRight(row, col, top, bottom, left, right);
    // for every idx in the box besides the current idx...
    for (int i = *top; i <= *bottom; i++) {
        for (int j = *left; j <= *right; j++) {
            if (!((i == row) && (j == col))) {
                // check if the box contains the value in question
                if (this->puzzle[(i * 9) + j] == place) {

                    delete top;
                    delete bottom;
                    delete left;
                    delete right;

                    return false;
                }
            }
        }
    }

    delete top;
    delete bottom;
    delete left;
    delete right;

    // if all tests pass without returning false, return true
    return true;
}

// assigns values indicating the top, bottom, left and right of the
// 3x3 box which contains the current idx
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

// extrapolate other known values based on the initial state of the puzzle
void Sudoku::_extrapolate(int possBoard[81][11], bool found[81], int count) {
    // if the previous round of extrapolation made no decisions, return
    if (count == 0) {
        return;
    }
    else {
        // counts the number of decisions made by this round of extrapolation
        count = 0;
        // for each idx in the puzzle...
        for (int i = 0; i < 81; i++) {
            // if there is only one possible value to an idx...
            if (possBoard[i][10] == 1) {
                // find the value by looping through the subarray at [i]
                int j = 1;
                while (possBoard[i][j] != 1) {
                    j++;
                }
                // assign the value to the first position of the subarray at [i]
                possBoard[i][0] = j;
                // assign the idx possible value counter to -1
                possBoard[i][10] = -1;
                // assign the value to the puzzle at the idx
                this->puzzle[i] = j;
                // mark the idx as having been found
                found[i] = true;
                // increment decision counter
                count++;
                // update the board of possible values based on the current decision
                _updatePulse(possBoard, i, j);
            }
        }
        // begin next round of extrapolation
        return _extrapolate(possBoard, found, count);
    }
}

// updates the board of possible values based on the assignment of a value at an idx
void Sudoku::_updatePulse(int possBoard[81][11], int idx, int val) {
    // determine row and column of idx
    int col = idx % 9;
    int row = (idx - col) / 9;

    // for each cell in the same row and column as the idx in question...
    for (int i = 0; i < 9; i++) {
        // row
        // if the assigned value is a possible value...
        if (possBoard[(row * 9) + i][val] == 1) {
            // remove as posibility
            possBoard[(row * 9) + i][val] = 0;
            // decrement possible value counter
            possBoard[(row * 9) + i][10]--;
        }
        // col
        if (possBoard[(i * 9) + col][val] == 1) {
            possBoard[(i * 9) + col][val] = 0;
            possBoard[(i * 9) + col][10]--;
        }
    }

    // pointers representing the top, bottom, left and right of the
    // 3x3 box in which the idx in question resides
    int *top = new int {0};
    int *bottom = new int {0};
    int *left = new int {0};
    int *right = new int {0};
    // assign values to the pointers
    _topBottomLeftRight(row, col, top, bottom, left, right);
    // for each idx in the box...
    for (int i = *top; i <= *bottom; i++) {
        for (int j = *left; j <= *right; j++) {
            // if it is not the idx in question...
            if (!((i == row) && (j == col))) {
                // if the value is listed as possible..
                if (possBoard[(i * 9) + j][val] == 1) {
                    // remove of value as possible
                    possBoard[(i * 9) + j][val] = 0;
                    // decrement the possible value counter
                    possBoard[(i * 9) + j][10]--;
                }
            }
        }
    }

    delete top;
    delete bottom;
    delete left;
    delete right;
}

// check if the puzzle has been sufficiently solved
bool Sudoku::_checkSolved(bool found[81]) {
    // for each idx in the puzzle...
    for (int i = 0; i < 81; i++) {
        // if the value not been found...
        if (found[i] == false) {
            // return false
            return false;
        }
    }
    // if every value has been found, return true
    return true;
}

// solves the remained of the puzzle with an informed brute force strategy
// based on the arrays of all possible values at each idx
void Sudoku::_solve(int idx, int possBoard[81][11], bool *solved, bool found[81]) {
    // if the end of the puzzle has been reached, the puzzle is solved
    if (idx == 81) {
        *solved = true;
        return;
    }
    // if the value at the idx has already been discovered, solve the next idx
    else if (this->puzzle[idx] != 0) {
        _solve(idx + 1, possBoard, solved, found);
        return;
    }
    else {
        // find the row and col of the current idx in question
        int col = idx % 9;
        int row = (idx - col) / 9;
        // for each value 1 through 9...
        for (int i = 1; i < 10; i++) {
            // if the value is listed as possible at the current idx
            // and its placement does not interfere with previous brute force decisions...
            if (possBoard[idx][i] == 1 && _checkPlacement(i, row, col)) {
                // place the value in the puzzle at the idx
                this->puzzle[idx] = i;
                // list the idx as found
                found[idx] = true;

                // solve the next idx
                _solve(idx + 1, possBoard, solved, found);
                // if the puzzle has been solved, return
                if (*solved == true) {
                    return;
                }

                // reset the puzzle at the idx
                this->puzzle[idx] = 0 ;
                // list the idx as not found
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