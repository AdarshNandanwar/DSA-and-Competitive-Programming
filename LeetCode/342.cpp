// https://leetcode.com/problems/power-of-four/

// Method 1 (using bit, O(1)):

class Solution {
public:
    bool isPowerOfFour(int num) {
        // 1. num > 0
        // 2. num must have only 1 set bit
        // 3. the only set bit must be in an even index
        return num>0 and (num & num-1) == 0 and (num & 0b01010101010101010101010101010101) != 0;
    }
};

// Method 2 (using bit loop, O(16)):

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return 0;
        for(int i = 0; i<32; i+=2) if(num == (1<<i)) return 1;
        return 0;
    }
};