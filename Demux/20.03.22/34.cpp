// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int lb, ub;
        
        if(!nums.size()){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        
        int lo, hi, mid;
        lo = 0, hi = nums.size()-1;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(nums[mid] >= target)
                hi = mid;
            else 
                lo = mid+1;
        }
        if(nums[lo] >= target)
            lb = lo;
        else
            lb = INT_MAX;
        
        lo = 0, hi = nums.size()-1;
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(nums[mid] > target)
                hi = mid-1;
            else 
                lo = mid;
        }
        if(!(nums[lo] > target))
            ub = lo;
        else
            ub = -1;
        
        if(lb<=ub){
            v.push_back(lb);
            v.push_back(ub);
            return v;
        }
        else{
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
    }
};