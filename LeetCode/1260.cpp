// https://leetcode.com/problems/shift-2d-grid/

// Method 1 (Index, O(n*m) time, O(n*m) space):

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int index=0; index<n*m; index++){
            int row = index/m;
            int col = index%m;
            int newIndex = (index+k)%(n*m);
            int newRow = newIndex/m;
            int newCol = newIndex%m;
            ans[newRow][newCol] = grid[row][col];
        }
        return ans;
    }
};