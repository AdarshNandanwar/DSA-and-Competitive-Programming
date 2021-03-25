// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> & visited){
        
        int n = grid.size(), m = grid[0].size();
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == '0' or visited[i][j]){
            return;
        }
        
        int X[4] = {1, 0, -1, 0};
        int Y[4] = {0, 1, 0, -1};
        
        visited[i][j] = true;
        
        for(int k = 0; k<4; k++){
            dfs(grid, i+Y[k], j+X[k], visited);
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int count = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] and grid[i][j] == '1'){
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};