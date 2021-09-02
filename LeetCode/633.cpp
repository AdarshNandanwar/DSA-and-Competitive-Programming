// https://leetcode.com/problems/sum-of-square-numbers/

// Method 1 (brute force):

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i<=sqrt(c); i++){
            int rt = sqrt(c-i*i);
            if (rt*rt == c-i*i) return true;
        }
        return false;
    }
};