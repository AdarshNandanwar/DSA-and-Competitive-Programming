// https://www.interviewbit.com/problems/subset-sum-problem/

// Method 1 (DP, O(n*sum)):

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(B+1, 0));
    for(int i = 0; i<=n; i++) dp[i][0] = 1;
    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<=B; j++){
            dp[i][j] = dp[i+1][j];
            if(j-A[i] >= 0) dp[i][j] |= dp[i+1][j-A[i]];
        }
    }
    return dp[0][B];
}
