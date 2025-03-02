// https://leetcode.com/problems/2-keys-keyboard/

// Method 1 (1D DP, O(n2)):

class Solution {
    int helper(int n, vector<int>& dp){
        if(n == 1){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = INT_MAX;
        for(int i=1; i<=n/2; i++){
            if(n % i == 0){
                ans = min(ans, (n/i) + helper(i, dp));
            }
        }

        return dp[n] = ans;
    }
public:
    int minSteps(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};
