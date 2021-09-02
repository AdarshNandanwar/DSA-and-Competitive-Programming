// https://www.interviewbit.com/problems/distinct-subsequences/

// Method 1 (DP, O(n*m)):

int Solution::numDistinct(string A, string B) {
    int n = A.length(), m = B.length();
    if(n < m) return 0;

    // dp[i][j] = A[i..n], B[j..m]
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<=n; i++) dp[i][m] = 1;
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(A[i] == B[j]) dp[i][j] = dp[i+1][j+1];
            dp[i][j] += dp[i+1][j];
        }
    }
    return dp[0][0];
}
