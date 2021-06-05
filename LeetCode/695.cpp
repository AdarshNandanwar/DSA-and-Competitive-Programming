// https://leetcode.com/problems/max-area-of-island/

// Method 1 (DFS):

class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    
    int dfs(int i, int j, vector<vector<int>> & grid, vector<vector<bool>> & visited){
        int n = grid.size(), m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or !grid[i][j] or visited[i][j]) return 0;
        visited[i][j] = true;
        int res = 1;
        for(int k = 0; k<4; k++){
            res += dfs(i+dir[k], j+dir[k+1], grid, visited);
        }
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res = max(res, dfs(i, j, grid, visited));
            }
        }
        return res;
    }
};