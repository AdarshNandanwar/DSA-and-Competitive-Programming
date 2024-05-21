// https://leetcode.com/problems/cherry-pickup-ii/description/

// Method 1 (3D DP, O(n*m*m)):

class Solution {
    int helper(const vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(row == n){
            return 0;
        }
        if(col1<0 or col1>=m or col2<0 or col2>=m){
            return INT_MIN;
        }
        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }
        
        int currentCherries = grid[row][col1];
        if(col2 != col1){
            currentCherries += grid[row][col2];
        }

        int maxCherries = INT_MIN;
        for(int offset1 = -1; offset1<=1; offset1++){
            for(int offset2 = -1; offset2<=1; offset2++){
                maxCherries = max(maxCherries, currentCherries+helper(grid, row+1, col1+offset1, col2+offset2, dp));
            }
        }
        return dp[row][col1][col2] = maxCherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return helper(grid, 0, 0, m-1, dp);
    }
};