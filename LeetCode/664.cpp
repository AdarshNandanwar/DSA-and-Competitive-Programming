// https://leetcode.com/problems/strange-printer/

// Method 1 (2D DP, O(n3)):

class Solution {
    int helper(const string & s, int i, int j, vector<vector<int>> & dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int differentI = i;
        while(differentI <= j and s[differentI] == s[i])
        {
            differentI++;
        }

        // Worst case: Print each character group one by one
        int ans = 1 + helper(s, differentI, j, dp);

        // Idea: cost for aXa = cost for aX
        // This becomes branching problem of if we want to make a charater group disappear
        // by merging it with a similar group that appeared earlier
        for(int k=differentI; k<=j; k++){
            if(s[i] == s[k]){
                int differentK = k+1;
                while(differentK <= j and s[differentK] == s[k]){
                    differentK++;
                }
                ans = min(ans, helper(s, i, k-1, dp) + helper(s, differentK, j, dp));
                k = differentK;
            }
        }

        return dp[i][j] = ans;
    }
public:
    int strangePrinter(string s) {
        int n = s.length();

        // dp[i][j] = answer for s[i, j]
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(s, 0, n-1, dp);
    }
};
