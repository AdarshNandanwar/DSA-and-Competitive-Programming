// https://leetcode.com/problems/count-vowels-permutation/

// Method 1 (DP, O(n)):

#define MOD 1000000007

class Solution {
public:
    int countVowelPermutation(int n) {
        // a => 0;
        // e => 1;
        // r => 2;
        // o => 3;
        // u => 4;
        vector<vector<long long>> dp(n+1, vector<long long>(5));
        dp[1] = {1,1,1,1,1};
        for(int i = 2; i<=n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4])%MOD;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%MOD;
            dp[i][4] = dp[i-1][0];
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0ll)%MOD;
    }
};