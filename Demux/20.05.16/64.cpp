// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        if(n==0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        
        for(int i = n-1; i>=0; i--){
            for(int j= m-1; j>=0; j--){
                if(i == n-1 and j == m-1)
                    dp[i][j] = grid[i][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};