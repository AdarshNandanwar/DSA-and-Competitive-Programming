// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x or y){
            res += ((x^y)&1);
            x = x>>1;
            y = y>>1;
        }
        return res;
    }
};