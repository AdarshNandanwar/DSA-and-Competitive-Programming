// https://leetcode.com/problems/n-queens-ii/

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