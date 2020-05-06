// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/

class Solution {
public:
    int findMin(vector<int>& nums) {
        // FFFFFTTT
        // p(x): nums[x] < nums[0]
        // First T
        
        int n = nums.size(), lo, hi, mid;
        lo = 0, hi = n-1;
        while(lo < hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] < nums[0])
                hi = mid;
            else 
                lo = mid+1;
        }
        if(nums[lo] < nums[0])
            return nums[lo];
        else
            return nums[0];
    }
};