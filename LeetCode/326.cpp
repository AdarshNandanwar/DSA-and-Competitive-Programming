// https://leetcode.com/problems/power-of-three/

// Method 1 (math):

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 = 1162261467 (max power of 3 <= INT_MAX)
        return n>0 and 1162261467%n == 0; 
    }
};

// Method 2 (loop):

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return 0;
        while(n>1){
            if(n%3) return 0;
            n /= 3;
        }
        return 1;
    }
};