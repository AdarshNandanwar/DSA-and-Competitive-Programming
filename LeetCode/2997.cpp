// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

// Method 1 (XOR, O(n)):

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int XOR = k;
        for(auto num:nums){
            XOR ^= num;
        }
        int operations = 0;
        while(XOR){
            operations += (1&XOR);
            XOR >>= 1;
        }
        return operations;
    }
};
