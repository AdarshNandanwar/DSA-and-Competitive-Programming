// https://leetcode.com/problems/largest-plus-sign/

// Method 1 (Prefix Sum, Space Optimized, O(n2)):

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int res = 0, prefix_sum = 0;
        // initial value is INT_MAX
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for(auto &mine:mines){
            for(int k=0; k<4; k++){
                grid[mine[0]][mine[1]] = 0;
            }
        }
        // min prefix sum {right, down, left, up}
        for(int i=0; i<n; i++){
            prefix_sum = 0;
            for(int j=0; j<n; j++){
                prefix_sum = grid[i][j] ? prefix_sum+1 : 0;
                grid[i][j] = min(grid[i][j], prefix_sum);
            }
            prefix_sum = 0;
            for(int j=n-1; j>=0; j--){
                prefix_sum = grid[i][j] ? prefix_sum+1 : 0;
                grid[i][j] = min(grid[i][j], prefix_sum);
            }
        }
        for(int j=0; j<n; j++){
            prefix_sum = 0;
            for(int i=0; i<n; i++){
                prefix_sum = grid[i][j] ? prefix_sum+1 : 0;
                grid[i][j] = min(grid[i][j], prefix_sum);
            }
            prefix_sum = 0;
            for(int i=n-1; i>=0; i--){
                prefix_sum = grid[i][j] ? prefix_sum+1 : 0;
                grid[i][j] = min(grid[i][j], prefix_sum);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }
};

// Method 2 (Prefix Sum, O(n2)):

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto &mine:mines){
            for(int k=0; k<4; k++){
                grid[mine[0]][mine[1]] = 0;
            }
        }
        // {right, down, left, up}
        vector<vector<vector<int>>> prefix_sum(4, grid);
        for(int i=0; i<n; i++){
            for(int j = 1; j<n; j++){
                if(grid[i][j]) prefix_sum[0][i][j] += prefix_sum[0][i][j-1];
            }
            for(int j=n-2; j>=0; j--){
                if(prefix_sum[2][i][j]) prefix_sum[2][i][j] += prefix_sum[2][i][j+1];
            }
        }
        for(int j=0; j<n; j++){
            for(int i=1; i<n; i++){
                if(grid[i][j]) prefix_sum[1][i][j] += prefix_sum[1][i-1][j];
            }
            for(int i=n-2; i>=0; i--){
                if(grid[i][j]) prefix_sum[3][i][j] += prefix_sum[3][i+1][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int smallest_axis = n;
                for(int k=0; k<4; k++){
                    smallest_axis = min(smallest_axis, prefix_sum[k][i][j]);
                }
                res = max(res, smallest_axis);
            }
        }
        return res;
    }
};