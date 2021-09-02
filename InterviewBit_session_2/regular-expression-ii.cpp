// https://www.interviewbit.com/problems/regular-expression-ii/

int Solution::isMatch(const string A, const string B) {
    int la = A.length(), lb = B.length();
    vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));
    dp[la][lb] = 1;
    for(int i = lb-1; i>=0; i--){
        if(B[i] == '*'){
            dp[la][i--] = 1;
            if(i) dp[la][i] = 1;
        } else break;
    }
    for(int i = la-1; i>=0; i--){
        for(int j = lb-1; j>=0; j--){
            if(j+1<lb and B[j+1] == '*'){
                dp[i][j] = dp[i][j+1];
                continue;
            } 
            if(A[i] == B[j] or B[j] == '.'){
                dp[i][j] = dp[i+1][j+1];
            } else if(B[j] == '*'){
                dp[i][j] = dp[i][j+1];
                if(j == 0) return 0;
                if(A[i] == B[j-1] or B[j-1] == '.'){
                    dp[i][j] = dp[i][j] or dp[i+1][j];
                }
            }
        }
    }
    return dp[0][0];
}
