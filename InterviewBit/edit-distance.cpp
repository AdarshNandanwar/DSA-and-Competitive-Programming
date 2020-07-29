// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int na = A.length(), nb = B.length();
    
    // dp[i][j] = step to convert A[i..na-1] to B[j..nb-1]
    vector<vector<int>> dp(na+1, vector<int>(nb+1, INT_MAX));
    
    // base case
    for(int i = 0; i<=na; i++) dp[i][nb] = na-i;
    for(int i = 0; i<=nb; i++) dp[na][i] = nb-i;
    
    for(int i = na-1; i>=0; i--){
        for(int j = nb-1; j>=0; j--){
            if(A[i] == B[j]){
                dp[i][j] = dp[i+1][j+1];
            } else {
                dp[i][j] = min(dp[i][j], 1+dp[i+1][j+1]);
                dp[i][j] = min(dp[i][j], 1+dp[i][j+1]);
                dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}
