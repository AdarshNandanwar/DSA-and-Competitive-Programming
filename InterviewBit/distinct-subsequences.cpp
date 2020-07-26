//  https://www.interviewbit.com/problems/distinct-subsequences/

int helper(string& A, string& B, int indA, int indB, vector<vector<int>>& dp){
    if(B.length() == indB) return 1;
    if(A.length() == indA) return 0;
    
    if(dp[indA][indB] != -1) return dp[indA][indB];
    
    int res = 0;
    // include
    if(A[indA] == B[indB]) res += helper(A, B, indA+1, indB+1, dp);
    // exclude
    res += helper(A, B, indA+1, indB, dp);
    
    return dp[indA][indB] = res;
}

int Solution::numDistinct(string A, string B) {
    vector<vector<int>> dp(A.length(), vector<int>(B.length(), -1));
    return helper(A, B, 0, 0, dp);
}
