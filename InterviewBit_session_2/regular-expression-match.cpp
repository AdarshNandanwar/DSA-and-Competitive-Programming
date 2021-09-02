// https://www.interviewbit.com/problems/regular-expression-match/

int Solution::isMatch(const string A, const string B) {
    int la = A.length(), lb = B.length();
    vector<vector<bool>> dp(la+1, vector<bool>(lb+1, 0));
    dp[la][lb] = 1;
    for(int i = lb-1; i>=0; i--){
        if(B[i] != '*') break;
        dp[la][i] = 1;
    } 
    for(int i = la-1; i>=0; i--){
        for(int j = lb-1; j>=0; j--){
            if(A[i] == B[j] or B[j] == '?') dp[i][j] = dp[i+1][j+1];
            else if(B[j] == '*') dp[i][j] = dp[i+1][j] or dp[i][j+1];
        }
    }
    return dp[0][0];
}
