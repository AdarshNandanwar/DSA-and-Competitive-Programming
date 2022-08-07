// https://leetcode.com/problems/powx-n/

// Method 1 (Hash map DP,O(logn)):

class Solution {
public:
    unordered_map<int, double> dp;
    double myPow(double x, int n) {
        if(dp.count(n)) return dp[n];
        if(n == -1) return (double)1/x;
        if(n == 0) return 1;
        if(n == 1) return x;
        return dp[n] = myPow(x, n/2)*myPow(x, n-n/2);
    }
};