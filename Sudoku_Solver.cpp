#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(int row,int col,vector<vector<int>> &board,int value ){
    for(int i = 0;i<9;i++){
        //row check
        if(board[row][i] == value){
            return false;
        }
        //col check
        if(board[i][col] == value){
            return false;
        }

        // 3*3 matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == value){
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board){
    int n = 9;

    for(int row = 0; row<9;row++){
        for(int col = 0;col<9;col++){
            //cell empty
            if(board[row][col] == 0){
                for(int val = 1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;
                        //recursive call
                        bool aagesolpossible = solve(board);
                        if(aagesolpossible){
                            return true;
                        }
                        else{
                            //bactracking
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

void solveSudoku(vector<vector<int>> &sudoko){
    solve(sudoko);


}


int main() {
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

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