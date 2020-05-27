// https://leetcode.com/problems/n-queens/

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