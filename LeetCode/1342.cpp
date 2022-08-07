// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// Method 1 (Bit Manipulation, O(logn)):

class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0){
            return 0;
        }
        int bitLength = 0, setBits = 0;
        while(num){
            setBits += (num&1);
            bitLength++;
            num >>= 1;
        }
        return bitLength+setBits-1;
    }
};

// Method 2 (O(logn)):

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num){
            if(num%2){
                num -= 1;
            } else {
                num /= 2;
            }
            count++;
        }
        return count;
    }
};