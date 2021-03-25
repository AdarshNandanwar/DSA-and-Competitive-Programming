// https://www.interviewbit.com/problems/nqueens/

void helper(int & n, int row, vector<bool> & col, vector<bool> & diag1, vector<bool> & diag2, vector<string> & cur, vector<vector<string> > & ans){
    if(row == n){
        ans.push_back(cur);
        return;
    }
    string s = string(n, '.');
    for(int i = 0; i<n; i++){
        if(col[i] or diag1[i-row+n] or diag2[i+row]) continue;
        s[i] = 'Q';
        col[i] = diag1[i-row+n] = diag2[i+row] = 1;
        cur.push_back(s);
        helper(n, row+1, col, diag1, diag2, cur, ans);
        cur.pop_back();
        col[i] = diag1[i-row+n] = diag2[i+row] = 0;
        s[i] = '.';
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<string> > ans;
    vector<string> cur;
    vector<bool> col(A, 0), diag1(2*A, 0), diag2(2*A, 0);
    
    helper(A, 0, col, diag1, diag2, cur, ans);
    return ans;
}
