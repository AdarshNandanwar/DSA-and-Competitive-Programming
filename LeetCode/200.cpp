// https://leetcode.com/problems/number-of-islands/

// Method 1 (DFS, O(n*m) time, O(n*m) space):

class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(const vector<vector<char>>& grid, int i, int j, vector<vector<bool>> & visited){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] == '0' or visited[i][j]){
            return;
        }
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int nbrI = i+dir[k];
            int nbrJ = j+dir[k+1];
            dfs(grid, nbrI, nbrJ, visited);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and !visited[i][j]){
                    count++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return count;
    }
};
