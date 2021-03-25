// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    
    bool solve(vector<vector<char>>& board, vector<vector<bool>> & row, vector<vector<bool>> & col, vector<vector<bool>> & box, int i, int j) {
        for(; i<9; i++){
            for(; j<9; j++){
                if(board[i][j]=='.'){
                    for(int k = 0; k<9; k++){
                        if(row[i][k] or col[j][k] or box[((i/3)*3)+(j/3)][k]){
                            continue;
                        }
                        row[i][k] = col[j][k] = box[((i/3)*3)+(j/3)][k] = true;
                        board[i][j] = '1'+k;
                        if(solve(board, row, col, box, i, j)){
                            return true;
                        }
                        board[i][j] = '.';
                        row[i][k] = col[j][k] = box[((i/3)*3)+(j/3)][k] = false;
                    }
                    return false;
                }
            }
            j = 0;
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9)), col(9, vector<bool>(9)), box(9, vector<bool>(9));
        for(int i =0; i<9; i++){
            for(int j =0; j<9; j++){
                if(board[i][j]!='.'){
                    row[i][board[i][j]-'1'] = col[j][board[i][j]-'1'] = box[((i/3)*3)+(j/3)][board[i][j]-'1'] = true;
                }
            }
        }
        solve(board, row, col, box, 0, 0);
    }
};