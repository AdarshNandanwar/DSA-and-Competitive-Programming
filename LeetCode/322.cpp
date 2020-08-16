// https://leetcode.com/problems/coin-change/

// Method 1 (DP, O(n*amount)):

class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<int> & dp){
        if(amount == 0) return 0;
        if(dp[amount] != -2) return dp[amount];
        int res = INT_MAX;
        for(auto c:coins){
            if(amount-c<0) continue;
            int h = helper(coins, amount-c, dp);
            if(h != -1) res =  min(res, 1+h);
        }
        return dp[amount] = (res == INT_MAX ? -1 : res);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2);
        return helper(coins, amount, dp);
    }
};

// Method 2 (DP, runs all but TLE, O(n*amount)):

class Solution {
public:
    int helper(vector<int>& coins, int amount, int index, vector<vector<int>> & dp){
        if(amount == 0) return 0;
        if(index == coins.size()) return -1;
        if(dp[amount][index] != -2) return dp[amount][index];
        int res = INT_MAX;
        for(int i = amount/coins[index]; i>=0; i--){
            int h = helper(coins, amount-i*coins[index], index+1, dp);
            if(h != -1) res =  min(res, i+h);
        }
        return dp[amount][index] = (res == INT_MAX ? -1 : res);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -2));
        return helper(coins, amount, 0, dp);
    }
};