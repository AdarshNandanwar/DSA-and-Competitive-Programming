// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

// Method 1 (DP, O(n2)):

class Solution {
public:
    
    int helper(int st, int end, vector<vector<int>> & dp){
        if(end-st <= 0) return 0;
        
        if(dp[st][end] != -1) return dp[st][end];
        int res = INT_MAX;
        for(int i = st; i<=end; i++){
            res = min(res, i+max(helper(st, i-1, dp), helper(i+1, end, dp)));
        }
        return dp[st][end] = res;
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(1, n, dp);
    }
};