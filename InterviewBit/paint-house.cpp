// https://www.interviewbit.com/problems/paint-house/

// Method 1 (DP, O(n)):

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0] = A[0];
    for(int i = 1; i<n; i++){
        dp[i][0] = A[i][0]+min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = A[i][1]+min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = A[i][2]+min(dp[i-1][0], dp[i-1][1]);
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}
