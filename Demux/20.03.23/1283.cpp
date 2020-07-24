// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int evaluateQ(vector<int> &nums, int x){
        int n = nums.size(), i, Q = 0;
        for(i = 0; i <n; i++){
            Q += (ceil((float)nums[i]/x));
        }
        
        return Q;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), maxEle = INT_MIN, i, hi, lo, mid;
        
        for(i = 0; i<n; i++){
            maxEle = max(maxEle, nums[i]);
        }
        
        lo = 1, hi = maxEle;
        while(lo < hi){
            mid = lo+(hi-lo)/2;
            if(evaluateQ(nums, mid) <= threshold){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        return lo;
    }
};