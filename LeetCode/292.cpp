// https://leetcode.com/problems/nim-game/

// Method 1 (O(1)):

class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};

// Method 2 (O(n)):

class Solution {
public:
    bool canWinNim(int n) {
        if(n == 0) return false;
        if(n <= 3) return true;
        vector<bool> dp(n+1, false);
        dp[1] = dp[2] = dp[3] = true;
        for(int i = 4; i<=n; i++) dp[i] = !dp[i-1] or !dp[i-2] or !dp[i-3];
        return dp[n];
    }
};