// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Method 1 (Binary Search, O(logn)):

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        if(start == end){
            return {-1, -1};
        } else {
            return {start, end-1};
        }
    }
};

// Alternate Code:

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0){
            return {-1, -1};
        }
        
        // FT First T
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] >= target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[lo] != target){
            return {-1, -1};
        }
        int start = lo;
        
        // TF Last T
        lo = 0;
        hi = n-1;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(nums[mid] <= target){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        return {start, lo};
    }
};