// https://leetcode.com/problems/out-of-boundary-paths/

// Method 1 (Top Down DP, DFS, O(n*m*moves)):

#define MOD 1000000007
class Solution {
    vector<int> dir = {0, -1, 0, 1, 0};
    int dfs(const int & n, const int & m, int curRow, int curColumn, int movesRemaining, vector<vector<vector<int>>> & dp){
        if(curRow<0 or curRow>=n or curColumn<0 or curColumn>=m){
            return 1;
        }
        if(movesRemaining<=0){
            return 0;
        }
        if(dp[curRow][curColumn][movesRemaining] != -1){
            return dp[curRow][curColumn][movesRemaining];
        }
        int pathCount = 0;
        for(int k=0; k<4; k++){
            int nbrRow = curRow+dir[k];
            int nbrColumn = curColumn+dir[k+1];
            pathCount = (pathCount+dfs(n, m, nbrRow, nbrColumn, movesRemaining-1, dp))%MOD;
        }
        return dp[curRow][curColumn][movesRemaining] = pathCount;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        swap(n, m);
        // dp[i][j][k] = max paths to boundary starting from {i, j} in at most k moves
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxMove+1, -1)));
        return dfs(n, m, startRow, startColumn, maxMove, dp);
    }
};

// Alternate Code:

#define MOD 1000000007

class Solution {
    vector<int> dirs = {0, -1, 0, 1, 0};

    int helper(const int m, const int n, int row, int column, int maxMove, vector<vector<vector<int>>>& dp){
        if(row < 0 or column < 0 or row >= m or column >= n){
            return maxMove == 0;
        }
        if(maxMove <= 0){
            return 0;
        }
        if(dp[row][column][maxMove] != -1){
            return dp[row][column][maxMove];
        }
        
        long pathCount = 0;
        for(int i=0; i<4; i++){
            int nextRow = row + dirs[i];
            int nextColumn = column + dirs[i+1];
            pathCount = (pathCount + helper(m, n, nextRow, nextColumn, maxMove-1, dp)) % MOD; 
        }
        return dp[row][column][maxMove] = pathCount;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[i][j][k] = Number of ways to move ball outside boundary from (i,j) position with exactly k moves.
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        long pathCount = 0;
        while(maxMove){
            pathCount = (pathCount + helper(m, n, startRow, startColumn, maxMove, dp)) % MOD;
            maxMove--;
        }
        return pathCount;
    }
};