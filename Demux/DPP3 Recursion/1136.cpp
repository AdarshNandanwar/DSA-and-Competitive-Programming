// https://leetcode.com/problems/n-th-tribonacci-number/

vector<int> dp(38, -1);

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};