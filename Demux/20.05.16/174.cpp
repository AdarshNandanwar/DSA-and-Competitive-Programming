// https://leetcode.com/problems/dungeon-game/

// Method 1 (DP, clean):

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), req = 0;
        if(n == 0) return 0;
        int m =dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        
        dp[n-1][m-1] = max(1, 1-dungeon[n-1][m-1]);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 and j == m-1) 
                    continue;
                if(i+1<n)
                    dp[i][j] = min(dp[i][j], max(1, dp[i+1][j]-dungeon[i][j]));
                if(j+1<m)
                    dp[i][j] = min(dp[i][j], max(1, dp[i][j+1]-dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};

// Method 1 (DP, high level code, 0 allowed):

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        if(n == 0) return 0;
        int m =dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        
        dp[n-1][m-1] = -min(0, dungeon[n-1][m-1]);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 and j == m-1) continue;
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                if(dp[i][j] < 0){
                    dp[i][j] += abs(dungeon[i][j]);
                } else {
                    dp[i][j] = max(0, dp[i][j]-dungeon[i][j]);
                }
            }
        }
        return dp[0][0]+1;
    }
};

// Method 1 (DP, self explanatory code):

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), req = 0;
        if(n == 0) return 0;
        int m =dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        
        if(dungeon[n-1][m-1] >= 0){
            dp[n-1][m-1] = 1;
        } else {
            dp[n-1][m-1] = 1+abs(dungeon[n-1][m-1]);
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 and j == m-1) continue;
                req = min(dp[i+1][j], dp[i][j+1]);
                if(dungeon[i][j] >= 0){
                    if(dungeon[i][j]-req < 0){
                        dp[i][j] = req-dungeon[i][j];
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = req + abs(dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};