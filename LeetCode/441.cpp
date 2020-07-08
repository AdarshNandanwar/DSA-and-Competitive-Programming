// https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = sqrt(2l*n);
        while((ans-1l)*(ans) <= 2l*n) ans++;
        return ans-2;
    }
};