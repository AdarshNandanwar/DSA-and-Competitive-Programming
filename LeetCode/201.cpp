// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// Method 1 (Bit Manipulation, O(1)):

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left != right){
            shift++;
            left = left >> 1;
            right = right >> 1;
        }
        return left << shift;
    }
};

// Method 2 (Bit Manipulation, O(1)):

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // for every bit, 
        // check the highest number which is <= right with that bit unset
        // if it is >= left, that bit in AND will not be set
        // e.g.
        // for right = 110110, checking if 
        // 110101 is < left for bit 1
        // 110011 is < left for bit 2
        // 101111 is < left for bit 4
        // 011111 is < left for bit 5
        int res = 0, mask, val;
        for(int i = 0; i<32; i++){
            mask = (1<<i);
            if(right&mask){
                val = right;
                val |= (mask-1);
                val &= (~mask);
                if(val < left) res += mask;
            }
        }
        return res;
    }
};