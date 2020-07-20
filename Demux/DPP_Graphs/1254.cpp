// https://leetcode.com/problems/number-of-closed-islands/

// Method 1:

int dir[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    void dfs(vector<vector<int>> & grid, int i, int j, int & n, int & m){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == 1) return;
        grid[i][j] = 1;
        for(int x = 0; x<4; x++) dfs(grid, i+dir[x], j+dir[x+1], n, m);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; i++){
            dfs(grid, i, 0, n, m);
            dfs(grid, i, m-1, n, m);
        }
        for(int j = 0; j<m; j++){
            dfs(grid, 0, j, n, m);
            dfs(grid, n-1, j, n, m);
        }
        int count = 0;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return count;
    }
};

// Method 2:

int dir[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    bool dfs(vector<vector<int>> & grid, int i, int j, int & n, int & m){
        if(i<0 or i>=n or j<0 or j>=m) return false;
        if(grid[i][j] == 1) return true;
        grid[i][j] = 1;
        bool res = true;
        for(int x = 0; x<4; x++) res = dfs(grid, i+dir[x], j+dir[x+1], n, m) and res;
        return res;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(grid[i][j] == 0 and dfs(grid, i, j, n, m)) count++;
            }
        }
        return count;
    }
};