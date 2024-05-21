// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

// Method 1 (Backtracking, O(2^n)):

class Solution {
    void helper(const vector<int> & nums, int i, int curXor, int & xorSum){
        int n = nums.size();
        if(i == n){
            xorSum += curXor;
            return;
        }
        helper(nums, i+1, curXor, xorSum);
        helper(nums, i+1, curXor ^ nums[i], xorSum);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int xorSum = 0;
        helper(nums, 0, 0, xorSum);
        return xorSum;
    }
};
