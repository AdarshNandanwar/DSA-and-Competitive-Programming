// https://leetcode.com/problems/n-queens/

// Method 1 (DP check):

class Solution {
public:
    
    void solve(int n, vector<string> & curr, vector<bool> & row, vector<bool> & col, vector<bool> & diag1, vector<bool> & diag2, vector<vector<string>> & ans, int queensLeft, int r){
        if(queensLeft == 0){
            ans.push_back(curr);
            return;
        }
        
        if(r>=n) return;
        
        for(int j = 0; j<n; j++){
            if(col[j] or diag1[r+j] or diag2[r-j+n-1]) continue;
            curr[r][j] = 'Q';
            row[r] = col[j] = diag1[r+j] = diag2[r-j+n-1] = true;
            solve(n, curr, row, col, diag1, diag2, ans, queensLeft-1, r+1);
            curr[r][j] = '.';
            row[r] = col[j] = diag1[r+j] = diag2[r-j+n-1] = false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> row(n, false), col(n, false), diag1(2*n-1, false), diag2(2*n-1, false);
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> curr(n, s);
        solve(n, curr, row, col, diag1, diag2, ans, n, 0);
        return ans;
    }
};

// Method 2 (Brute Force check):

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
    
    void helper(vector<string> & board, int row, vector<vector<string>> & ans){
        if(row == board.size()){
            ans.push_back(board);
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
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        helper(board, 0, ans);
        return ans;
    }
};