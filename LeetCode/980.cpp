// https://leetcode.com/problems/unique-paths-iii/

// Method 1 (DFS, O(3^(n*m))):

class Solution {
public:
    
    vector<int> dir = {0, -1, 0, 1, 0};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int remaining){
        int n = grid.size(), m = grid[0].size();
        if(grid[i][j] == 2){
            if(remaining == 0) return 1;
            else return 0;
        }
        grid[i][j] = -1;
        remaining--;
        int res = 0;
        for(int k = 0; k<4; k++){
            int nbrI = i+dir[k];
            int nbrJ = j+dir[k+1];
            if(nbrI>=0 and nbrI<n and nbrJ>=0 and nbrJ<m and grid[nbrI][nbrJ] != -1){
                res += dfs(grid, nbrI, nbrJ, remaining);
            }
        }
        grid[i][j] = 0;
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int stI, stJ, remaining = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    stI = i;
                    stJ = j;
                }
                if(grid[i][j] == 0) remaining++;
            }
        }
        grid[stI][stJ] = 0;
        return dfs(grid, stI, stJ, remaining);
    }
};