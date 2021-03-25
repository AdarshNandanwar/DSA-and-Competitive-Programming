// https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 2; i<=n; i++){
            for(int j = 1; (i-j)>=2; j++){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};