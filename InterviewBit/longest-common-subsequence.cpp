// https://www.interviewbit.com/problems/longest-common-subsequence/

int Solution::solve(string A, string B) {
    int n = A.length(), m = B.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(A[i] == B[j]) dp[i][j] = 1+dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}
