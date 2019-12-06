
/*  Sudoku Overview:
 *
 *  Sudoku takes a file of comma-separated lines and uses
 *  it to store a sudoku board state as a 1D array of ints
 *  in row-major order.
 *
 *  For Programming Assignment 05, this class will be used to
 *  test problem 3.
 *
 *  Problem 3 will be tested by calling the solve member function
 *
 *  Note: in a proper C++ class you would have Getters and Setters
 *  however, here we don't do that since all values are changed
 *  internally from within the class itself.
 */

#ifndef _SUDOKU_H_
#define _SUDOKU_H_

class Sudoku {
    private:
        // puzzle will store the Sudoku puzzle in 1D space
        int puzzle[81];

        // initialize the board of possible values from the input puzzle
        void _initPossBoard(int possBoard[81][11], bool found[81]);
        // fill all subarrays based on the input puzzle
        void _fillPossBoard(int possBoard[81][11], bool found[81]);
        // checks the placement ofa a value at an idx
        bool _checkPlacement(int place, int row, int col);
        // gets values respresenting the 3x3 box the idx is found in
        void _topBottomLeftRight(int row, int col, int *top, int *bottom, int *left, int *right);
        // extrapolates form known data to most solved state without employing brute force
        void _extrapolate(int possBoard[81][11], bool found[81], int count);
        // updates the row, column and box of possible values due to the placement of a value at an idx
        void _updatePulse(int possBoard[81][11], int i, int j);
        // checks if the puzzle is solved
        bool _checkSolved(bool found[81]);
        // brute force solve
        void _solve(int idx, int possBoard[81][11], bool *solved, bool found[81]);

    public:
        /* Class constructors and destructors */
        // class constructor using a file
        Sudoku(const char *fname);
        // class destructor
        ~Sudoku();
        /* Member functions */
        // solve the sudoku puzzle
        void solve();
        // prints the Sudoku puzzle in 2D format
        void print();

    // arrays: rows, columns and boxes
};
#endif