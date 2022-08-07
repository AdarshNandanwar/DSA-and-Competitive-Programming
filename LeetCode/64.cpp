// https://leetcode.com/problems/minimum-path-sum/

// Method 1 (2D DP, O(n*m)):

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n-1][m] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                dp[i][j] = grid[i][j]+min(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};