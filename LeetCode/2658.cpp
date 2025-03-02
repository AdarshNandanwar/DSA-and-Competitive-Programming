// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

// Method 1 (DFS, O(n*m)):

class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};
    int dfs(int i, int j, const vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int n = grid.size(), m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] == 0 or visited[i][j]){
            return 0;
        }
        visited[i][j] = true;

        int fishes = grid[i][j];
        for(int k=0; k<4; k++){
            int nbrI = i + dirs[k];
            int nbrJ = j + dirs[k+1];
            fishes += dfs(nbrI, nbrJ, grid, visited);
        }

        return fishes;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));

        int maxFishes = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxFishes = max(maxFishes, dfs(i, j, grid, visited));
            }
        }

        return maxFishes;
    }
};
