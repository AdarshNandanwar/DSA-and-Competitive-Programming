// https://leetcode.com/problems/path-with-maximum-gold/

// Method 1 (DFS + Backtracking + Optimization, O(n*m*4^(n*m)) = O(n*m*4^(25))):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};

    int getDegree(const vector<vector<int>> & grid, int row, int col){
        int n = grid.size(), m = grid[0].size();
        int degree = 0;
        for(int k=0; k<4; k++){
            int i = row + dir[k];
            int j = col + dir[k+1];
            if(i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0){
                continue;
            }
            degree++;
        }
        return degree;
    }

    int dfs(const vector<vector<int>> & grid, int row, int col, vector<vector<bool>> & visited){
        int n = grid.size(), m = grid[0].size();
        if(row < 0 or row >= n or col < 0 or col >= m or grid[row][col] == 0 or visited[row][col]){
            return 0;
        }
        visited[row][col] = true;
        int gold = 0;
        for(int k=0; k<4; k++){
            int i = row + dir[k];
            int j = col + dir[k+1];
            gold = max(gold, grid[row][col] + dfs(grid, i, j, visited));
        }
        visited[row][col] = false;
        return gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));

        int totalGold = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                totalGold += grid[i][j];
            }
        }
        
        int maxGold = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // Optimization 1: Skip high degree nodes
                if(getDegree(grid, i, j) > 2){
                    continue;
                }
                
                int gold = dfs(grid, i, j, visited);
                
                // Optimization 2: Early termination
                if(gold == totalGold){
                    return gold;
                }

                maxGold = max(maxGold, gold);
            }
        }
        return maxGold;
    }
};

// Method 2 (DFS + Backtracking, O(n*m*4^(n*m)) = O(n*m*4^(25))):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    int dfs(const vector<vector<int>> & grid, int row, int col, vector<vector<bool>> & visited){
        int n = grid.size(), m = grid[0].size();
        if(row < 0 or row >= n or col < 0 or col >= m or grid[row][col] == 0 or visited[row][col]){
            return 0;
        }
        visited[row][col] = true;
        int gold = 0;
        for(int k=0; k<4; k++){
            int i = row + dir[k];
            int j = col + dir[k+1];
            gold = max(gold, grid[row][col] + dfs(grid, i, j, visited));
        }
        visited[row][col] = false;
        return gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int maxGold = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxGold = max(maxGold, dfs(grid, i, j, visited));
            }
        }
        return maxGold;
    }
};
