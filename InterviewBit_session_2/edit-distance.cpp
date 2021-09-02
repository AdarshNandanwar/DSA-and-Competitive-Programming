// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int la = A.length(), lb = B.length();
    vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));
    for(int i = 0; i<la; i++) dp[i][lb] = la-i;
    for(int i = 0; i<lb; i++) dp[la][i] = lb-i;
    for(int i = la-1; i>=0; i--){
        for(int j = lb-1; j>=0; j--){
            if(A[i] == B[j]) dp[i][j] = dp[i+1][j+1];
            else dp[i][j] = 1+min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));    
        }
    }
    return dp[0][0];
}
