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
        // dp[i][j][k] = max paths to boundary starting from {i, j} in k moves
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxMove+1, -1)));
        return dfs(n, m, startRow, startColumn, maxMove, dp);
    }
};