// https://leetcode.com/problems/count-servers-that-communicate/

// Method 1 (DFS, O(n*m)):

class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int & sz){
        int n = grid.size(), m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or visited[i][j] or grid[i][j] == 0){
            return;
        }
        visited[i][j] = true;
        sz++;
        for(int k=0; k<n; k++){
            if(grid[k][j] == 1 and !visited[k][j]){
                dfs(k, j, grid, visited, sz);
            }
        }
        for(int k=0; k<m; k++){
            if(grid[i][k] == 1 and !visited[i][k]){
                dfs(i, k, grid, visited, sz);
            }
        }
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int serverCount = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sz = 0;
                dfs(i, j, grid, visited, sz);
                if(sz >= 2){
                    serverCount += sz;
                }
            }
        }
        return serverCount;
    }
};
