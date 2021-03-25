// https://leetcode.com/problems/find-peak-element/

// Method 1 (Binary Search, O(logn)):

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // FT last F
        int n = nums.size(), lo = 1, hi = n-1, mid;
        if(n <= 1) return 0;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(nums[mid-1]>=nums[mid]){
                hi = mid-1;
            } else {
                lo = mid;
            }
        }
        return nums[lo-1]>=nums[lo] ? 0 : lo;
    }
};