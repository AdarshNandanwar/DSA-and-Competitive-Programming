// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    B = min(B, n/2);
    
    // dp[i][j][k] = max profit in [0..i] with atmost j transactions and k stocks in hand
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, 0)));
    // base case
    for(int j = 1; j<=B; j++) dp[0][j%2][1] = -A[0];
    for(int j = 1; j<=B; j++){
        for(int i = 1; i<n; i++){
            dp[i][j%2][0] = max(dp[i-1][j%2][0], dp[i-1][j%2][1]+A[i]);
            dp[i][j%2][1] = max(dp[i-1][(j-1)%2][0]-A[i], dp[i-1][j%2][1]);
        }
    }
    return dp[n-1][B%2][0];
}
