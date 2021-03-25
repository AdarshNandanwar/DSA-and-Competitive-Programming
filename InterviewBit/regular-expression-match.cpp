// https://www.interviewbit.com/problems/regular-expression-match/

// Method 1 (DP, O(n*m)):

int Solution::isMatch(const string A, const string B) {
    int n = A.length(), m = B.length();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
    // base case
    dp[n][m] = 1;
    for(int j = m-1; j>=0; j--){
        if(B[j] == '*') dp[n][j] = 1;
        else break;
    }
    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(B[j] == '*'){
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
            } else if(A[i] == B[j] or B[j] == '?'){
                dp[i][j] = dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];
}
