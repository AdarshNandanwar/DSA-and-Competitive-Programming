// https://leetcode.com/problems/single-element-in-a-sorted-array/

// Method 1 (Binary Search, O(log(n))):

class Solution {
public:
    
    bool is_valid(vector<int> & nums, int index){
        if(index%2){
            return index-1>=0 and nums[index-1] == nums[index];
        } else {
            return index+1<nums.size() and nums[index+1] == nums[index];
        }
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        // Binary Search
        // predicate: repeated number is in the right, if i is even, or left, if i is odd
        // TF first F
        int lo = 0, hi = nums.size(), mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(is_valid(nums, mid)){
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        if(!is_valid(nums, lo)) return nums[lo];
        return -1;
    }
};