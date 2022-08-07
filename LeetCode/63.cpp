// https://leetcode.com/problems/unique-paths-ii/

// Method 1 (Bottom Up DP):

typedef long long ll;

class Solution {
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ll n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        dp[n-1][m-1] = !obstacleGrid[n-1][m-1];
        for(ll i = n-1; i>=0; i--){
            for(ll j = m-1; j>=0; j--){
                if(i == n-1 and j == m-1) continue;
                if(!obstacleGrid[i][j]) dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

// Alternate Code:

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long>> dp(n+1, vector<long>(m+1, 0));
        dp[n-1][m] = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(obstacleGrid[i][j]){
                    continue;
                }
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

// Method 2 (Top Down DP):

class Solution {
public:
    int helper(vector<vector<int>> & obstacleGrid, int i, int j, vector<vector<int>> & dp){
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(i == n or j == m or obstacleGrid[i][j]) return 0;
        if(i == n-1 and j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        res += helper(obstacleGrid, i+1, j, dp);
        res += helper(obstacleGrid, i, j+1, dp);
        return dp[i][j] = res;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(obstacleGrid, 0, 0, dp);
    }
};