// https://leetcode.com/problems/valid-sudoku/

// Method 1 (O(n2)):

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> blocks(9, vector<bool>(9, false));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int value = board[i][j]-'1';
                
                if(rows[i][value]) return false;
                rows[i][value] = true;
                
                if(cols[j][value]) return false;
                cols[j][value] = true;
                
                int block = (3*(i/3))+(j/3);
                if(blocks[block][value]) return false;
                blocks[block][value] = true;
            }
        }
        return true;
    }
};