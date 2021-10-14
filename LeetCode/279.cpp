// https://leetcode.com/problems/perfect-squares/

// Method 1 (DP, O(n*sqrt(n))):

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j*j<=i; j++){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};