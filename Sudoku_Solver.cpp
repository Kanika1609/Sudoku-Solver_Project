#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int value) {
    for (int i = 0; i < 9; i++) {
        // Row check
        if (board[row][i] == value) {
            return false;
        }
        // Column check
        if (board[i][col] == value) {
            return false;
        }
        // 3x3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    int n = 9;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // Cell empty
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        // Recursive call
                        bool aagesolpossible = solve(board);
                        if (aagesolpossible) {
                            return true;
                        }
                        else {
                            // Backtracking
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

void inputSudoku(vector<vector<int>>& sudoku) {
    cout << "Enter the Sudoku puzzle (0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9, 0));

    inputSudoku(sudoku);

    solveSudoku(sudoku);

    cout << "Solved Sudoku:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
