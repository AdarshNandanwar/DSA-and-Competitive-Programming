// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size(), trans = 2;
    if(n <= 1) return 0;
    // dp[i][j][k] = max profit in [0..i) days with atmost j transactions with k stock bought in hand
    
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(trans+1, vector<int>(2, 0)));
    
    for(int j = 1; j<=trans; j++) dp[0][j][1] = INT_MIN;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=trans; j++){
            dp[i%2][j][0] = max(dp[(i-1)%2][j][0], dp[(i-1)%2][j][1]+A[i-1]);
            dp[i%2][j][1] = max(dp[(i-1)%2][j][1], dp[(i-1)%2][j-1][0]-A[i-1]);
        }
    }
    
    return dp[n%2][trans][0];
}
