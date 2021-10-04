// https://leetcode.com/problems/dungeon-game/

// Method 1 (2D DP, O(n*m)):

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        // dp[i][j] = minimum health required for the knight to go from [i,j] to [n-1,m-1]
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[n-1][m-1] = max(1, 1-dungeon[n-1][m-1]);
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i+1<n) dp[i][j] = min(dp[i][j], max(1, dp[i+1][j]-dungeon[i][j]));
                if(j+1<m) dp[i][j] = min(dp[i][j], max(1, dp[i][j+1]-dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};