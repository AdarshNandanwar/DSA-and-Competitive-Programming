// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    // base case
    dp[n-1][m-1] = A[n-1][m-1];
    for(int i = n-2; i>=0; i--) dp[i][m-1] = dp[i+1][m-1]+A[i][m-1];
    for(int j = m-2; j>=0; j--) dp[n-1][j] = dp[n-1][j+1]+A[n-1][j];
    
    for(int i = n-2; i>=0; i--){
        for(int j = m-2; j>=0; j--){
            dp[i][j] = A[i][j]+min(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}
