// https://www.interviewbit.com/problems/maximum-path-in-triangle/

// Method 1 (DP, O(n2)):

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    // dp[i][j] = max path sum from bottom to row i
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // base case
    dp[n-1] = A[n-1];
    for(int i = n-2; i>=0; i--){
        for(int j = i; j>=0; j--){
            dp[i][j] = A[i][j]+max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
