// https://leetcode.com/problems/island-perimeter/

// Method 1 (if else, O(n*m)):

class Solution {
public:    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, nbr_i, nbr_j;
        vector<int> dir = {0, -1, 0, 1, 0};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    for(int k = 0; k<4; k++){
                        nbr_i = i+dir[k]; nbr_j = j+dir[k+1];
                        if(nbr_i<0 or nbr_i>=n or nbr_j<0 or nbr_j>=m or grid[nbr_i][nbr_j] == 0){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// Method 2 (DFS, O(n*m)):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    void dfs(vector<vector<int>> & grid, vector<vector<bool>> & visited, int i, int j, int & ans){
        int n = grid.size(), m = grid[0].size();
        visited[i][j] = true;
        for(int k = 0; k<4; k++){
            int nbr_i = i+dir[k], nbr_j = j+dir[k+1];
            if(nbr_i<0 or nbr_i>=n or nbr_j<0 or nbr_j>=m or grid[nbr_i][nbr_j] == 0){
                ans++;
                continue;
            } 
            if(visited[nbr_i][nbr_j]) continue;
            dfs(grid, visited, nbr_i, nbr_j, ans);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, done = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] and !visited[i][j]){
                    dfs(grid, visited, i, j, ans);
                    done = 1;
                    break;
                }
            }
            if(done) break;
        }
        return ans;
    }
};