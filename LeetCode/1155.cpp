// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Method 1 (2D DP, O(n*k*target)):

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