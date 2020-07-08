// https://leetcode.com/problems/island-perimeter/

int dir[5] = {0, 1, 0, -1, 0};

class Solution {
public:
   
    void dfs(vector<vector<int>>& grid, int i, int j, int & n, int & m, int & count, vector<vector<bool>>& visited){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == 0){
            count++;
            return;
        }
        if(visited[i][j]) return;
        visited[i][j] = true;
        for(int k = 0; k<4; k++){
            dfs(grid, i+dir[k], j+dir[k+1], n, m, count, visited);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size(), count = 0;
        vector<vector<bool>> visited(n, vector(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    dfs(grid, i, j, n, m, count, visited);
                    return count;
                }
            }
        }
        return count;
    }
};