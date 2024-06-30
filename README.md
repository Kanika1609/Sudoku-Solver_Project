# Sudoku-Solver_Project
This project implements a Sudoku solver in C++ using a backtracking algorithm. The solver reads an initial Sudoku board and fills it in according to Sudoku rules, ensuring that each number from 1 to 9 appears exactly once in each row, column, and 3x3 sub-grid.


Features:-


Backtracking Algorithm: Utilizes a recursive backtracking algorithm to explore possible solutions and backtrack when a solution is not possible.

Input Handling: Reads a 9x9 Sudoku board with some pre-filled values and empty cells represented by 0.

Validation Function: Includes a helper function 'isSafe' to check if placing a number in a given cell is valid according to Sudoku rules.

Output: Prints the solved Sudoku board to the console.


Code Overview:-


isSafe Function: Checks if a given number can be placed at a specific row and column without violating Sudoku rules.

solve Function: Uses backtracking to solve the Sudoku by recursively trying to place numbers in empty cells.

solveSudoku Function: Wrapper function that calls the solve function to start solving the Sudoku.

main Function: Initializes the Sudoku board, calls the solver, and prints the solved board.
