// https://leetcode.com/problems/split-array-largest-sum/

// Method 1 (Binary Search, O(sum)):

class Solution {
public:
    int getCount(const vector<int>& nums, const int& maxSum){
        int curSum = 0, count = 1;
        for(auto &i:nums){
            curSum += i;
            if(curSum > maxSum){
                curSum = i;
                count++;
            }
        }
        return count;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // FT first T
        int lo, hi, mid, sum = 0;
        lo = *max_element(nums.begin(), nums.end());
        for(auto &i:nums) sum += i;
        hi = sum;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(getCount(nums, mid) <= m){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(getCount(nums, lo) <= m) return lo;
        else return -1;
    }
};