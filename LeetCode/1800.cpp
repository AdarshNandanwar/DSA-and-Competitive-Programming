// https://leetcode.com/problems/maximum-ascending-subarray-sum/

// Method 1 (Loop, O(n)):

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int curSum = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                curSum += nums[i];
            } else {
                curSum = nums[i];
            }
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
