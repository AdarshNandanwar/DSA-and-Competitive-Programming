// https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    
    int helper(vector<vector<int>> & grid, int r1, int c1, int r2, vector<vector<vector<int>>> & dp){
        int n = grid.size();
        int len = r1+c1;
        int c2 = len-r2;
        
        if(r1>=n or c1>=n or r2>=n or c2>=n) return -1;
        
        if(grid[r1][c1] == -1 or grid[r2][c2] == -1) return -1;
        
        if(r1 == n-1 and c1 == n-1) return grid[r1][c1];
        
        if(dp[r1][c1][r2] != -2) return dp[r1][c1][r2];
        
        int res = -1;
        
        int t1 = helper(grid, r1+1, c1, r2, dp);
        res = max(res, (t1 == -1)?-1:t1+grid[r1][c1]);
        
        int t2 = helper(grid, r1+1, c1, r2+1, dp);
        res = max(res, (t2 == -1)?-1:t2+grid[r1][c1]);
        
        int t3 = helper(grid, r1, c1+1, r2, dp);
        res = max(res, (t3 == -1)?-1:t3+grid[r1][c1]);
        
        int t4 = helper(grid, r1, c1+1, r2+1, dp);
        res = max(res, (t4 == -1)?-1:t4+grid[r1][c1]);
        
        // not same point
        if(r1 != r2 and res != -1){
            res += grid[r2][c2];
        }
        
        return dp[r1][c1][r2] = res;       
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // -1 : no path
        // -2 : value not previously calculated
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -2)));
        // dp[i][j][k] : i,j is r1,c1 for the head of path1 and k is r2 of head of path2
        //               both path are of same length = r+c
        
        int res = helper(grid, 0, 0, 0, dp);
        return (res == -1)?0:res;
        
    }
};