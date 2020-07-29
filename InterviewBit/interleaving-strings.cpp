// https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    int na = A.length(), nb = B.length(), nc = C.length();
    if(na+nb != nc) return 0;
    string s1 = A+B, s2 = C;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 != s2) return 0;
    
    // dp[i][j] = does A[i..na-1] and B[j..nb-1] interleave to make C[i+j..na+nb-1]
    vector<vector<bool>> dp(na+1, vector<bool>(nb+1, 0));
    
    // base cases
    dp[na][nb] = 1;
    for(int i = na-1; i>=0; i--){
        dp[i][nb] = dp[i+1][nb];
        if(A[i] != C[nb+i]) dp[i][nb] = 0;
    }
    for(int i = nb-1; i>=0; i--){
        dp[na][i] = dp[na][i+1];
        if(B[i] != C[na+i]) dp[na][i] = 0;
    }
    
    for(int i = na-1; i>=0; i--){
        for(int j = nb-1; j>=0; j--){
            if(A[i] == C[i+j]) dp[i][j] = dp[i][j] or dp[i+1][j];
            if(B[j] == C[i+j]) dp[i][j] = dp[i][j] or dp[i][j+1];
        }
    }
    
    return dp[0][0];
}
