// https://leetcode.com/problems/maximum-subarray/

// Method 1 (Kadane's Algorithm, O(n) time, O(1) space):

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = -1, maxSum = INT_MIN;
        for(auto &num:nums){
            if(curSum < 0){
                curSum = 0;
            }
            curSum += num;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};

// Method 2 (DP, O(n) time, O(n) space):

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        // sum of longest subarray ending at i
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i =1; i<n; i++){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
        }
        return *max_element(dp.begin(), dp.end());
        
    }
};

// Method 3 (O(n) time, O(1) space):

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefixSum = 0, minPrefixSum = 0, ans = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            prefixSum += nums[i];
            ans = max(ans, prefixSum-minPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum);
        }
        return ans;
    }
};