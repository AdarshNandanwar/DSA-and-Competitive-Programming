// https://leetcode.com/problems/powx-n/

class Solution {
public:
    unordered_map<int, double> dp;
    double myPow(double x, int n) {
        if(x == 0 or x == 1) return x;
        if(n == -1) return 1/x;
        if(n == 0) return 1;
        if(n == 1) return x;
        if(dp.count(n)) return dp[n];
        else return dp[n] = myPow(x, n/2)*myPow(x, n-n/2);
    }
};