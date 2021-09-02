// https://leetcode.com/problems/decode-ways-ii/

// Method 1 (DP, O(n)):

#define MOD 1000000007

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<long> dp(n+2, 0);
        dp[n] = dp[n+1] = 1;
        for(int i = n-1; i>=0; i--){
            if(s[i] == '*'){
                dp[i] = (dp[i] + 9*dp[i+1])%MOD;
                // * => 1
                if(i+1 < n and s[i+1] == '*') dp[i] = (dp[i] + 9*dp[i+2])%MOD;
                else if(i+1 < n) dp[i] = (dp[i] + dp[i+2])%MOD;
                // * => 2
                if(i+1 < n and s[i+1] == '*') dp[i] = (dp[i] + 6*dp[i+2])%MOD;
                else if(i+1 < n and s[i+1] <= '6') dp[i] = (dp[i] + dp[i+2])%MOD;                
            } else if(s[i] == '1'){
                dp[i] = dp[i+1];
                if(i+1 < n and s[i+1] == '*') dp[i] = (dp[i] + 9*dp[i+2])%MOD;
                else if(i+1 < n) dp[i] = (dp[i] + dp[i+2])%MOD;
            } else if(s[i] == '2'){
                dp[i] = dp[i+1];
                if(i+1 < n and s[i+1] == '*') dp[i] = (dp[i] + 6*dp[i+2])%MOD;
                else if(i+1 < n and s[i+1] <= '6') dp[i] = (dp[i] + dp[i+2])%MOD;  
            } else if(s[i] != '0'){
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};