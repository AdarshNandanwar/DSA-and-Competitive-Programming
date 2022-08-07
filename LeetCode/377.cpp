// https://leetcode.com/problems/combination-sum-iv/

// Method 1 (Recursion, DP):

class Solution {
public:
    
    int helper(vector<int>& nums, int target, vector<int> & dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            if(target-nums[i] >= 0) res += helper(nums, target-nums[i], dp);
        }
        return dp[target] = res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(nums, target, dp);
    }
};

// Method 2 (Bottom Up DP, Runtime error due to integer value overflow):
// as the intermediate targets may have more than INT_MAX ways

class Solution {
public:    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i<=target; i++)
            for(int j = 0; j<nums.size(); j++)
                if(i-nums[j] >= 0) dp[i] += dp[i-nums[j]];
        return dp[target];
    }
};

// Runtime Error Fix

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // dp[i] = number of combinations for target = i
        vector<long> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(int j=0; j<n and i>=nums[j]; j++){
                // since answer fits in in32, any alue that exceeds it won't be needed in valid path
                dp[i] = (dp[i]+dp[i-nums[j]])%INT_MAX;      
            }
        }
        return dp[target];
    }
};  