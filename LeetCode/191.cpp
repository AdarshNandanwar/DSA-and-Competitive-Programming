// https://leetcode.com/problems/number-of-1-bits/

// Method 1 (Rightmost Set Bit, O(#ones)):

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            int rightMostSetBit = n&(-n);
            n -= rightMostSetBit;
            count++;
        }
        return count;
    }
};

// Method 2 (Loop, O(place of most significant one)):

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            res += (n&1);
            n = n>>1;
        }
        return res;
    }
};

// Alternate Code:

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count += (n&1);
            n /= 2;
        }
        return count;
    }
};