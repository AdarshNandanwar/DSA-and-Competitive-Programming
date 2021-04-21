// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    int helper(vector<vector<int>>& matrix, int r, int c, int prev, vector<vector<int>>& dp){
        int n = matrix.size(), m = matrix[0].size();
        if(r<0 or r>=n or c<0 or c>=m or matrix[r][c] <= prev or dp[r][c] == 0) return 0;
        if(dp[r][c] != -1)  return dp[r][c];
        dp[r][c] = 0;   // marking visited
        int res = 0;
        for(int k = 0; k<4; k++){
            res = max(res, 1+helper(matrix, r+dir[k], c+dir[k+1], matrix[r][c], dp));
        }
        return dp[r][c] = res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res = max(res, helper(matrix, i, j, -1, dp));
            }
        }
        return res;
    }
};