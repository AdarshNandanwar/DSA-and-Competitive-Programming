// https://leetcode.com/problems/max-area-of-island/

int dir[5] = {0,1,0,-1,0};

class Solution {
public:
    
    int dfs(vector<vector<int>> & grid, int i, int j, int & n, int & m){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        int res = 1;
        for(int x = 0; x<4; x++) res += dfs(grid, i+dir[x], j+dir[x+1], n, m);
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size(), res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res = max(res, dfs(grid, i, j, n, m));
            }
        }
        return res;
    }
};