// https://leetcode.com/problems/house-robber/

class Solution {
public:
    
    int helper(vector<int>& nums, int index, vector<int> & dp){
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        dp[index] = max(nums[index]+helper(nums, index+2, dp), helper(nums, index+1, dp));
        return dp[index];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};