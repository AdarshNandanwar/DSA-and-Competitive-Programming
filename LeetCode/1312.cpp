// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Method 1 (DP, O(n2)):

class Solution {
public:
    
    int helper(string & s, int st, int end, vector<vector<int>> & dp){
        if(st>=end) return 0;
        if(dp[st][end] != -1) return dp[st][end];
        if(s[st] == s[end]) return dp[st][end] = helper(s, st+1, end-1, dp);
        else return dp[st][end] = 1+min(helper(s, st+1, end, dp), helper(s, st, end-1, dp));
    }
    
    int minInsertions(string s) {
        int n =s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, 0, n-1, dp);
    }
};