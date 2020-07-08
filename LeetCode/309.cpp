// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {    
        int n = prices.size();
        if(n <= 1) return 0;
        
        // dp[i][0] = max profit when last transaction in [0, i] is buy = max(dp[i-1][0]+prices[i], dp[i-2][1]+prices[i])
        // dp[i][1] = max profit when last transaction in [0, i] is sell = max(dp[i-1][1], dp[i-1][0]+prices[i])
        
        vector<vector<int>> dp(n, vector<int> (2, INT_MIN));
        vector<int> diff(n, 0);
        for(int i = 1; i<n; i++) diff[i] = prices[i]-prices[i-1];
        
        // base case
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = max(0, dp[0][0]+diff[1]);
        dp[1][1] = max(dp[0][1], dp[0][0]+diff[1]);
        
        for(int i = 2; i<n; i++){
            dp[i][0] = max(dp[i-1][0]+diff[i], dp[i-2][1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+diff[i]);
        }
        return dp[n-1][1];
    }
};