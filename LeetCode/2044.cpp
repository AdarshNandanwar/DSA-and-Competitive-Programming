// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

// Method 1 (Brute Force, O(2^n)):

class Solution {
    int helper(vector<int>& nums, int index, int cur, const int target){
        int n = nums.size();
        if(index == n){
            return cur == target;
        }

        return helper(nums, index+1, cur | nums[index], target) + helper(nums, index+1, cur, target);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(int num:nums){
            target |= num;
        }
        return helper(nums, 0, 0, target);
    }
};
