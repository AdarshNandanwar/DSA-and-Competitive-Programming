// https://www.interviewbit.com/problems/regular-expression-ii/

// Method 1 (DP, O(na*nb)):

int Solution::isMatch(const string A, const string B) {
    
    int na = A.length(), nb = B.length();

    // dp[i][j] = is [i..na-1] and [j..nb-1] matching
    vector<vector<bool>> dp(na+1, vector<bool>(nb+1, 0));

    // base case
    dp[na][nb] = 1;

    for(int i = na; i>=0; i--){
        for(int j = nb; j>=0; j--){
            if(A[i] == B[j] or B[j] == '.'){
                if(i+1 <= na and j+1 <= nb) dp[i][j] = dp[i+1][j+1];
                if(j+1<nb and B[j+1] == '*'){
                    // take B[j] zero times
                    dp[i][j] = dp[i][j] or dp[i][j+2];
                    // take B[j] one time
                    if(i+1 <= na) dp[i][j] = dp[i][j] or dp[i+1][j];
                }
            } else {
                if(j+1<nb and B[j+1] == '*'){
                    // take B[j] zero times
                    dp[i][j] = dp[i][j+2];
                }
            }
        }
    }

    return dp[0][0];
}