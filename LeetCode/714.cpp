// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Method 1 (DP, O(n)):

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), c = 1;
        if(n <= 1) return 0;
        
//         // dp[i][k][c] = max profit in [0, i] with atmost k transactions and c stock bought 
//         // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
//         // dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])
        
//         vector<vector<int>> dp(n, vector<int>(c+1, 0));
        
//         // base case
//         dp[0][1] = -prices[0]-fee;
        
//         for(int i = 1; i<n; i++){
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
//             dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee);
//         }
//         return dp[n-1][0];
        
        
        // STATE SPACE OPTIMIZATION
        
        int dpi0, dpi1, dpi_10, dpi_11;
        
        // base case
        dpi_10 = 0;
        dpi_11 = -prices[0]-fee;
        
        for(int i = 1; i<n; i++){
            dpi0 = max(dpi_10, dpi_11+prices[i]);
            dpi1 = max(dpi_11, dpi_10-prices[i]-fee);
            dpi_10 = dpi0;
            dpi_11 = dpi1;
        }
        return dpi0;
        
    }
};