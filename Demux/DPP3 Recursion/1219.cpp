// https://leetcode.com/problems/path-with-maximum-gold/

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};

class Solution {
public:
    
    void traverse(vector<vector<int>> & grid, int & n, int & m, int i, int j, int curGold, int & maxGold){
        if(i<0 or j<0 or i>=n or j>=m or !grid[i][j]) return;
        
        maxGold = max(maxGold, curGold+grid[i][j]);
        int temp = grid[i][j];
        grid[i][j] = 0;
        for(int k = 0; k<4; k++) traverse(grid, n, m, i+Y[k], j+X[k], curGold+temp, maxGold);
        grid[i][j] = temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxGold = 0, curGold = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                traverse(grid, n, m, i, j, 0, maxGold);
            }
        }
        return maxGold;
    }
};