// https://leetcode.com/problems/hamming-distance/

// Method 1 (Bitset):

class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32>(x^y).count();
    }
};

// Method 2 (Manual Counting):

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