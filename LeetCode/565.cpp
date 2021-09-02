// https://leetcode.com/problems/array-nesting/

// Method 1 (Graph Cycle Detection, O(n)):

class Solution {
public:
    
    int cycle_length(vector<int>& nums, int index){
        if(nums[index] == -1) return 0;
        int next = nums[index];
        nums[index] = -1;
        return 1+cycle_length(nums, next);
    }
    
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            res = max(res, cycle_length(nums, i));
        }
        return res;
    }
};