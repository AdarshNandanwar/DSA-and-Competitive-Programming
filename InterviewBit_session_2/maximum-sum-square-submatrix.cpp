// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

// Method 1 (Cumulative sum, O(n2)):

int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size(), res = INT_MIN;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            dp[i][j] = A[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1];
        }
    }
    for(int i = 0; i<n-B+1; i++){
        for(int j = 0; j<n-B+1; j++){
            res = max(res, dp[i][j]-dp[i+B][j]-dp[i][j+B]+dp[i+B][j+B]);
        }
    }
    return res;
}
