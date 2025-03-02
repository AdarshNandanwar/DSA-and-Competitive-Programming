// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

// Method 1 (Bit Manipulation, o(1)):

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_diff = (start ^ goal);
        int flips = 0;
        while(xor_diff){
            flips += (xor_diff&1);
            xor_diff >>= 1;
        }
        return flips;
    }
};

// Method 2 (Bit Manipulation, Pop count, O(1)):

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);;
    }
};
