// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9)), col(9, vector<bool>(9)), box(9, vector<bool>(9));
        for(int i =0; i<9; i++){
            for(int j =0; j<9; j++){
                if(board[i][j]!='.'){
                    if(row[i][board[i][j]-'1'] or col[j][board[i][j]-'1'] or box[((i/3)*3)+(j/3)][board[i][j]-'1']){
                        return false;
                    } else {
                        row[i][board[i][j]-'1'] = col[j][board[i][j]-'1'] = box[((i/3)*3)+(j/3)][board[i][j]-'1'] = true;
                    }
                }
            }
        }
        return true;
    }
};