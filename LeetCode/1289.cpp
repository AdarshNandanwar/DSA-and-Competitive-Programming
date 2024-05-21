// https://leetcode.com/problems/minimum-falling-path-sum-ii/

// Method 1 (2D DP, O(n^2) time, O(1) space):

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int prevMinIndex = min_element(grid[n-1].begin(), grid[n-1].end())-grid[n-1].begin();
        int prevMin = grid[n-1][prevMinIndex];
        grid[n-1][prevMinIndex] = INT_MAX;
        int prevSecondMin = *min_element(grid[n-1].begin(), grid[n-1].end());
        grid[n-1][prevMinIndex] = prevMin;

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                if(j == prevMinIndex){
                    grid[i][j] += prevSecondMin;
                } else {
                    grid[i][j] += prevMin;
                }
            }

            prevMinIndex = min_element(grid[i].begin(), grid[i].end())-grid[i].begin();
            prevMin = grid[i][prevMinIndex];
            grid[i][prevMinIndex] = INT_MAX;
            prevSecondMin = *min_element(grid[i].begin(), grid[i].end());
            grid[i][prevMinIndex] = prevMin;
        }

        return *min_element(grid[0].begin(), grid[0].end());
    }
};

// Method 2 (2D DP, O(n^2) time, O(n^2) space):

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int prevMin = 0, prevMinIndex = 0, prevSecondMin = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                dp[i][j] = grid[i][j];
                if(j == prevMinIndex){
                    dp[i][j] += prevSecondMin;
                } else {
                    dp[i][j] += prevMin;
                }
            }

            prevMinIndex = min_element(dp[i].begin(), dp[i].end())-dp[i].begin();
            prevMin = dp[i][prevMinIndex];
            dp[i][prevMinIndex] = INT_MAX;
            prevSecondMin = *min_element(dp[i].begin(), dp[i].end());
            dp[i][prevMinIndex] = prevMin;
        }
        
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

// Method 3 (2D DP, O(n^3) time, O(n^2) space):

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[n-1] = grid[n-1];
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(k == j){
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], dp[i+1][k]);
                }
                dp[i][j] += grid[i][j];
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
