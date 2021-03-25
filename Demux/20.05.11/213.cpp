// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    
    int helper(vector<int>& nums, int index, vector<int> & dp){
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        dp[index] = max(nums[index]+helper(nums, index+2, dp), helper(nums, index+1, dp));
        return dp[index];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        // excluding [0]
        vector<int> dp1(n, -1);
        int a1 = helper(nums, 1, dp1);
        nums.pop_back();
        // excluding [n-1]
        vector<int> dp2(n-1, -1);
        int a2 = helper(nums, 0, dp2);
        return max(a1, a2);
    }
};