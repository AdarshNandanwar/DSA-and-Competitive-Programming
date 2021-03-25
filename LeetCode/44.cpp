// https://leetcode.com/problems/wildcard-matching/

// Method 1 (DP, O(n*m)):

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        // dp[i][j] = isMatching s[i, n-1] and p[j, m-1]
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        dp[n][m] = 1;
        for(int j = m-1; j>=0; j--) if(p[j] == '*') dp[n][j] = dp[n][j+1];
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(p[j] == '*') {
                    dp[i][j] = dp[i+1][j] or dp[i][j+1];
                } else if(s[i] == p[j] or p[j] == '?') {
                    dp[i][j] = dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};