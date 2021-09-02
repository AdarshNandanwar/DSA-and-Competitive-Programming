// https://leetcode.com/problems/search-insert-position/

// Method 1 (Binary Search, O(logn)):

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // FT first T
        int lo = 0, hi = nums.size()-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[lo]>=target) return lo;
        return nums.size();
    }
};