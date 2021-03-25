// https://leetcode.com/problems/unique-paths-iii/

const int X[4] = {1, 0, -1, 0};
const int Y[4] = {0, 1, 0, -1};

class Solution {
public:
    
    void traverse(vector<vector<int>> & grid, int & n, int & m, int i, int j, int remaining, int & pathCount){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] == -1) return;
        
        if(grid[i][j] == 2){
            if(remaining == 0) pathCount++;
            return;
        }
        
        grid[i][j] = -1;
        for(int k = 0; k<4; k++) traverse(grid, n, m, i+Y[k], j+X[k], remaining-1, pathCount);
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), remaining = 0, I = 0, J = 0, pathCount = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0) remaining++;
                if(grid[i][j] == 1){
                    I = i;
                    J = j;
                }
            }
        }
        grid[I][J] = -1;
        for(int k = 0; k<4; k++) traverse(grid, n, m, I+Y[k], J+X[k], remaining, pathCount);
        return pathCount;
    }
};