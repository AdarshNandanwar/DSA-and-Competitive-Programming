// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Method 1 (Binary Search, O(logn)):

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // FT First T
        int lo = 0, hi = n-1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] < nums[0]){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int pivot = 0;
        if(nums[lo] < nums[0]){
            pivot = lo;
        }
        // FT First T
        lo = 0;
        hi = n-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[(mid+pivot)%n] >= target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[(lo+pivot)%n] == target){
            return (lo+pivot)%n;
        } else {
            return -1;
        }
    }
};