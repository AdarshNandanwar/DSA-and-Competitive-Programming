// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        int n = prices.size(), K = 2, c =1;
        if(n <= 1) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(K+1, vector<int>(c+1, 0)));
        
        // transaction begins at buy
        // dp[i][j][k] = max profit in [0,i] with at most j transactions and k stock currently bought
        // dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
        // dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
        
        // base case
        for(int i=1; i<=K; i++) dp[0][i][1] = -prices[0];
        
        for(int i = 1; i<n; i++){
            for(int j = 1; j<=K; j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        
        return dp[n-1][K][0];
    }
};