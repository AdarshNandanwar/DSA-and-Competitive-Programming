// https://leetcode.com/problems/coin-change/

// Method 1 (Bottom Up 1D DP, O(n*amount) time, O(amount) space):

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min number of coins required to make amount i
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto &coin:coins){
                int remainingAmount = i-coin;
                if(remainingAmount >= 0){
                    dp[i] = min(dp[i], 1+dp[remainingAmount]);
                }
            }
        }
        if(dp[amount] > amount) return -1;
        else return dp[amount];        
    }
};

// Method 2 (Top Down 1D DP, O(n*amount)):

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

// Method 3 (Bottom Up 2D DP, O(n*amount)):

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[i][j] = min number of coins required to make j amount using [i..n-1] demoninations
        vector<vector<long>> dp(n+1, vector<long>(amount+1, INT_MAX));
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=amount; j++){
                if(j-coins[i] >= 0){
                    dp[i][j] = min(1+dp[i][j-coins[i]], dp[i+1][j]);
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][amount] >= INT_MAX ? -1 : dp[0][amount];
    }
};

// Method 4 (DP, runs all but TLE, O(n*amount)):

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