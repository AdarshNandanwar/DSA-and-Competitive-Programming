// https://leetcode.com/problems/k-inverse-pairs-array/

// Method 1 *Bottom Up DP, Time Optimised, O(n*k)):

#define MOD 1000000007

class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange [1..i] with exactly j inversions
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i = 0; i<=n; i++) dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=k ; j++){
                // dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-(n-2)] + dp[i-1][j-(n-1)]
                // dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-1-(n-2)] + dp[i-1][j-1-(n-1)]
                // => dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][i-j];
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
                if(j-i >= 0) dp[i][j] = (dp[i][j] - dp[i-1][j-i])%MOD;
            }
        }
        return dp[n][k]<0 ? dp[n][k]+MOD : dp[n][k];
    }
};

// Method 2 (Bottom Up DP, O(n*k*k), TLE):

class Solution {
public:
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange [1..i] with exactly j inversions
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i = 0; i<=n; i++) dp[i][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=k ; j++){
                for(int a = 0; a<=min(i-1, j); a++){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-a])%1000000007;
                }
            }
        }
        return dp[n][k];
    }
};

// Method 3 (Top Down DP, O(n*k*k), TLE):

class Solution {
public:
    int helper(int n, int k, vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][k] != -1) return dp[n][k];
        int res = 0;
        for(int i = 0; i<=min(n-1, k); i++){
            res = (res+helper(n-1, k-i, dp))%1000000007;
        }
        return dp[n][k] = res;
    }
    
    int kInversePairs(int n, int k) {
        // dp[i][j] = number of ways to arrange [1..i] with exactly j inversions
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(n, k, dp);
    }
};