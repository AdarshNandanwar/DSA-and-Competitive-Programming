// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    
    // dp[i][1] = max profit in [0..i] with 1 stock bought currently
    // dp[i][0] = max profit in [0..i] with 0 stock bought currently
    vector<vector<int>> dp(n, vector<int>(2));
    
    // base case
    dp[0][0] = 0;
    dp[0][1] = -A[0];
    
    for(int i = 1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+A[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-A[i]);
    }
    
    return dp[n-1][0];
}
