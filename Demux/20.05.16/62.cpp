// https://leetcode.com/problems/unique-paths/

// Method 1 (Math):

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 0 or m == 0) return 0;
        if(n == 1 or m == 1) return 1;
        n--; m--;
        // (n+m)! / (n! * m!)
        long long res = 1;
        for(int i = n+m; i>max(n, m); i--) res *= i;
        for(int i = min(n, m); i>=1; i--) res /= i;
        return res;
    }
};

// Method 2 (DP):

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(n == 0){
            return 0;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i == n-1 and j == m-1){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] += dp[i+1][j];
                    dp[i][j] += dp[i][j+1];
                }
            }
        }

        return dp[0][0];
    }
};