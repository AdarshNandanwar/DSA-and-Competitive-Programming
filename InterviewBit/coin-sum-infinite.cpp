// https://www.interviewbit.com/problems/coin-sum-infinite/

// Method 2 (2D DP, MLE):

#define MOD 1000007

int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size();
    // dp[i][j] = no. of ways using [i..n-1] to make sum j
    vector<vector<long>> dp(n+1, vector<long>(B+1, 0));
    // base case
    for(int i = 0; i<n; i++) dp[i][0] = 1;
    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<=B; j++){
            dp[i][j] = ((j-A[i]>=0 ? dp[i][j-A[i]] : 0) + dp[i+1][j])%MOD;
        }
    }
    return dp[0][B];
}
