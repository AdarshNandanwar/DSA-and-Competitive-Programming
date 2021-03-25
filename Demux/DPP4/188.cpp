// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// Method 2 (DP, O(k*n2)):

// Gives MLE

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(K+1, 0));
        
        for(int i = n-1; i>=0; i--){
            for(int k = 1; k<=K; k++){
                for(int j = i+1; j<=n; j++){
                    dp[i][k] = max(dp[i][k], max(dp[j][k], dp[j][k-1]+prices[j-1]-prices[i]));
                }
            }
        }
        return dp[0][K];
    }
};