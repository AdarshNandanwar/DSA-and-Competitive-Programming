// https://leetcode.com/problems/distinct-subsequences/

// Method 1 (2D DP, O(n*m)):

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        // dp[i][j] = subproblem for s[i..n-1] and t[j..m-1]
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        for(int i = 0; i<n+1; i++) dp[i][m] = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                dp[i][j] = dp[i+1][j];
                if(s[i] == t[j]) 
                    dp[i][j] = (dp[i][j]+dp[i+1][j+1])%10000000000;
                    // Force fitting it within 32 bit to prevent overflow
                    // Bad problem statement
            }
        }
        return dp[0][0];
    }
};