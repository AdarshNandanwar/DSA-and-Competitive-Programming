// https://leetcode.com/problems/n-queens-ii/

// Method 1 (Hash Table):

class Solution {
    int getPlacements(const int & n, vector<bool> & columnsUsed, vector<bool> & leftDiagonalsUsed, vector<bool> & rightDiagonalsUsed, vector<string> & placement){
        int row = placement.size();
        if(row == n){
            return 1;
        }
        int count = 0;
        for(int col=0; col<n; col++){
            int leftDiagonal = row-col+n-1;
            int rightDiagonal = row+col;
            if(!columnsUsed[col] and !leftDiagonalsUsed[leftDiagonal] and !rightDiagonalsUsed[rightDiagonal]){
                columnsUsed[col] = true;
                leftDiagonalsUsed[leftDiagonal] = true;
                rightDiagonalsUsed[rightDiagonal] = true;                
                string boardRow = string(n, '.');
                boardRow[col] = 'Q';
                placement.push_back(boardRow);
                count += getPlacements(n, columnsUsed, leftDiagonalsUsed, rightDiagonalsUsed, placement);
                columnsUsed[col] = false;
                leftDiagonalsUsed[leftDiagonal] = false;
                rightDiagonalsUsed[rightDiagonal] = false;
                placement.pop_back();
            }
        }
        return count;
    }
public:
    int totalNQueens(int n) {
        vector<string> placement;
        vector<bool> columnsUsed(n, false);
        vector<bool> leftDiagonalsUsed(2*n-1, false);
        vector<bool> rightDiagonalsUsed(2*n-1, false);
        return getPlacements(n, columnsUsed, leftDiagonalsUsed, rightDiagonalsUsed, placement);
    }
};

// Alternate Code:

void helper(int & n, int row, vector<bool> & col, vector<bool> & diag1, vector<bool> & diag2, int & ans){
    if(row == n){
        ans++;
        return;
    }
    for(int i = 0; i<n; i++){
        if(col[i] or diag1[i-row+n] or diag2[i+row]) continue;
        col[i] = diag1[i-row+n] = diag2[i+row] = 1;
        helper(n, row+1, col, diag1, diag2, ans);
        col[i] = diag1[i-row+n] = diag2[i+row] = 0;
    }
}

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> col(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        helper(n, 0, col, diag1, diag2, ans);
        return ans;
    }
};

// Method 2 (Brute Force):

class Solution {
public:
    
    bool is_valid(vector<string> & board, int row, int col){
        int i, j, n = board.size();
        
        i = row;
        while(i>=0) if(board[i--][col] == 'Q') return false;
        i = row; j = col;
        while(i>=0 and j>=0) if(board[i--][j--] == 'Q') return false;
        i = row; j = col;
        while(i>=0 and j<n) if(board[i--][j++] == 'Q') return false;
        
        return true;
    }
    
    void helper(vector<string> & board, int row, int & ans){
        if(row == board.size()){
            ans++;
            return;
        }
        for(int i = 0; i<board.size(); i++){
            if(is_valid(board, row, i)){
                board[row][i] = 'Q';
                helper(board, row+1, ans);
                board[row][i] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        helper(board, 0, ans);
        return ans;
    }
};