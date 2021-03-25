// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int lo, hi, mid, pivot, index, n = nums.size();
        if(n == 0) return -1;
        
        // find pivot
        // p(x): nums[i] < nums[0];
        // FFFTTT
        // First true;
        
        lo = 0;
        hi = n-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] < nums[0]){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(nums[lo]<nums[0]){
            pivot = lo;
        } else {
            pivot = 0;
        }
        
        
        // find index in translated array 
        // (i+pivot)%n
        
        // p(x): nums[i] >= target;
        // FFFTTT
        // First true;
        
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
            index = (lo+pivot)%n;
        } else {
            index = -1;
        }    
        
        return index;
    }
};