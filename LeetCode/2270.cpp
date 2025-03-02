// https://leetcode.com/problems/number-of-ways-to-split-array/

// Method 1 (Prefix Sum, O9(n)):

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long sum = 0;
        for(int num:nums){
            sum += num;
        }

        long prefixSum = 0;
        int ways = 0;
        for(int i=0; i<n-1; i++){
            prefixSum += nums[i];
            if(prefixSum >= sum-prefixSum){
                ways++;
            }
        }
        
        return ways;
    }
};
