// https://leetcode.com/problems/power-of-two/

// Method 1 (Last set bit, O(1)):

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        return n - (n&(-n)) == 0;
    }
};

// Method 2 (Loop, O(1)):

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        while(n % 2 == 0){
            n /= 2;
        }
        return n == 1;
    }
};