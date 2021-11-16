// https://leetcode.com/problems/unique-binary-search-trees/

// Method 1 (Recursion DP, O(n2)):

class Solution {
public:
    unordered_map<int, int> dp;
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp.count(n)) return dp[n];
        int res = 0;
        for(int i=0; i<n; i++){
            res += (numTrees(i)*numTrees(n-i-1));
        }
        return dp[n] = res;
    }
};