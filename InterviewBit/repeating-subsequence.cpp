// https://www.interviewbit.com/problems/repeating-subsequence/

int Solution::anytwo(string A) {
    int n = A.length();
    
    // longest common subsequence of A and A
    
    // dp[i][j] = longest common subsequence in A[0..i] and A[0..j] with index different
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // base case
    for(int i = 1; i<n; i++){
        dp[i][0] = dp[i-1][0];
        dp[0][i] = dp[0][i-1];
        if(A[i] == A[0]) dp[i][0] = dp[0][i] = 1;
    } 
    
    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            if(A[i] == A[j] and i!=j){
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n-1][n-1] >= 2;
}
