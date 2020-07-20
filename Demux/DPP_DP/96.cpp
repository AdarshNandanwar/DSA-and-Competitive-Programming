// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int helper(int n, vector<int> & dp){
        if(n <= 1) return 1;
        if(dp[n]!=-1) return dp[n];
        int res = 0;
        for(int i = 0; i<n; i++) res += (helper(i, dp)*helper(n-i-1, dp));
        return dp[n] = res;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};