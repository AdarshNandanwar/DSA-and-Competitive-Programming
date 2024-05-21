// https://leetcode.com/problems/house-robber/

// Method 1 (1D DP, Bottom Up, O(n)):

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = max money that can be robbed in [i..n)
        vector<int> dp(n+1, 0);
        dp[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};

// Alternate Code:

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = max profit till house i
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            dp[i] = max(nums[i], dp[i-1]);
            if(i-2 >= 0) dp[i] = max(dp[i], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

// Method 2 (1D DP, Top Down, O(n)):

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