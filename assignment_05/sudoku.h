
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

        void _initPossBoard(int possBoard[81][11], bool found[81]);
        void _fillPossBoard(int possBoard[81][11], bool found[81]);
        bool _checkPlacement(int place, int row, int col);
        void _topBottomLeftRight(int row, int col, int *top, int *bottom, int *left, int *right);
        void _extrapolate(int possBoard[81][11], bool found[81], int count);
        void _updatePulse(int possBoard[81][11], int i, int j);
        bool _checkSolved(bool found[81]);
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