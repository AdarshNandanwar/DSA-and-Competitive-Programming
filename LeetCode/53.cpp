// https://leetcode.com/problems/maximum-subarray/

// Method 1 (DP, O(n)):

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

// Method 2 (O(n)):

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