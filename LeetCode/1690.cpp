// https://leetcode.com/problems/stone-game-vii/

// Method 1 (DP, Bottom Up, O(n2)):

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> cum_sum(n+1, 0);
        for(int i = n-1; i>=0; i--) cum_sum[i] = cum_sum[i+1]+stones[i];
        // dp[i][j] = maximum value of (score of current player - score of other player) in the game [i,j]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int j = i+1; j<n; j++){
                dp[i][j] = max(cum_sum[i]-cum_sum[j]-dp[i][j-1], cum_sum[i+1]-cum_sum[j+1]-dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};