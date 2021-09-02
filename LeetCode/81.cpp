// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Method 1 (Binary Search, worst case O(n), average case O(logn));

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0] == target) return 1;
        int lo = 0, hi = n-1, mid;
        while(lo<=hi and nums[lo] == nums[0]) lo++;
        if(lo == n) return 0;
        // FT first T
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid]<=nums[0]){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int pivot = 0;
        if(nums[lo]<=nums[0]) pivot = lo;
        lo = 0; hi = n-1;
        // FT first T
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[(mid+pivot)%n] >= target){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return nums[(lo+pivot)%n] == target;
    }
};