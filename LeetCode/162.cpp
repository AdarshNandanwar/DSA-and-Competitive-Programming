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

// Alternate Code:

class Solution {
public:
    bool predicate(vector<int>& nums, int i){
        int n = nums.size();
        if(i==n-1) return true;
        return nums[i]>nums[i+1];
    }
    
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // FT first T
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(predicate(nums, mid)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(predicate(nums, lo)) return lo;
        return -1;
    }
};