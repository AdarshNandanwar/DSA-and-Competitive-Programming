// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// Method 1 (DP, O(n)):

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1]+prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0]-prices[1]);   // IMP, no cooldown on the first time
        for(int i = 2; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);    // IMP, no i-2>=0 check as the loop starts from i=2
        }
        return dp[n-1][0];
    }
};

// Alternate Code

class Solution {
public:    
    int maxProfit(vector<int>& prices) {    
        int n = prices.size(), c = 1;
        if(n <= 1) return 0;
        
        // dp[i][k][c] = max profit in [0, i] with atmost k transactions and c stock bought 
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
        
        vector<vector<int>> dp(n, vector<int>(c+1, 0));
        
        // base case
        dp[0][1] = -prices[0];
        
        for(int i = 1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], (i-2>=0?dp[i-2][0]:0)-prices[i]);
        }
        return dp[n-1][0];
    }
};