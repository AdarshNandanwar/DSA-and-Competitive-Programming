// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

// Method 1 (Prefix Sum, O(n)):

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = 0;
        int minPrefixSum = 0, maxPrefixSum = 0;
        int prefixSum = 0;
        for(int num:nums){
            prefixSum += num;
            minPrefixSum = min(minPrefixSum, prefixSum);
            maxPrefixSum = max(maxPrefixSum, prefixSum);
            res = max(res, max(prefixSum - minPrefixSum, maxPrefixSum - prefixSum));
        }
        return res;
    }
};
