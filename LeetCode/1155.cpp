// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Method 1 (Recursive 2D DP, O(n*k*target)):

#define MOD 1000000007
class Solution {
    int helper(int n, const int & k, int target, vector<vector<int>> & dp){
        if(target==0 and n==0){
            return 1;
        }
        if(target<0 or n==0 or n*k<target){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int res = 0;
        for(int i=1; i<=k; i++){
            res = (res+helper(n-1, k, target-i, dp))%MOD;
        }
        return dp[n][target] = res;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return helper(n, k, target, dp);
    }
};

// Method 2 (Iterative 2D DP, O(n*target*k)):

#define MOD 1000000007

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][j] = number of ways to get j sum using i dice

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=target; j++){
                for(int face = 1; face <= k and j-face>=0; face++){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-face])%MOD;
                }
            }
        }
        return dp[n][target];
    }
};
