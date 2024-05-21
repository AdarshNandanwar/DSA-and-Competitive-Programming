// https://leetcode.com/problems/climbing-stairs/

// Method 1 (DP, O(n)):

class Solution {
public:
    int climbStairs(int n) {        
        // dp[i] = number of ways to climb i staircase
        vector<int> dp(n+1, 1);
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};