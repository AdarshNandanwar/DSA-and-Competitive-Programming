// https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    
    int helper(int amount, int index, vector<int>& coins, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(index == coins.size()) return 0;
        if(dp[amount][index] != -1) return dp[amount][index];
        int res = 0;
        for(int i = 0; amount-i*coins[index]>=0; i++){
            res += helper(amount-i*coins[index], index+1, coins, dp);
        }
        return dp[amount][index] = res;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        return helper(amount, 0, coins, dp);
    }
};