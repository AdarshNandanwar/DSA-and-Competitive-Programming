// https://leetcode.com/problems/target-sum/

// Method 1 (Top Down 2D DP, O(n*target)):

class Solution {
    int helper(const vector<int>& nums, int index, int target, vector<unordered_map<int, int>> & dp){
        int n = nums.size();
        if(index == n){
            return target == 0;
        }
        if(dp[index].count(target)){
            return dp[index][target];
        }

        int res = 0;
        res += helper(nums, index+1, target-nums[index], dp);
        res += helper(nums, index+1, target+nums[index], dp);
        return dp[index][target] = res;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n); // dp[i] = number of ways to sum to target using [i, n)
        return helper(nums, 0, target, dp);
    }
};
