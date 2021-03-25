// https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/

// Method 1 (DP, O(n*m)):

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
    }
    
    int res = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // base case
    for(int i = 0; i<n; i++){
        if(A[i][0] > 0) res = dp[i][0] = 1;
    } 
    for(int j = 0; j<m; j++){
        if(A[0][j] > 0) res = dp[0][j] = 1;
    } 
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(A[i][j]) dp[i][j] = min(A[i][j], 1+min(dp[i][j-1], dp[i-1][j-1]));
            res = max(res, dp[i][j]*dp[i][j]);
        }
    }
    return res;
}
