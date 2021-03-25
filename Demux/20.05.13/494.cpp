// https://leetcode.com/problems/target-sum/

class Solution {
public:
    
    int helper(vector<int>& nums, int S, int index, vector<vector<int>> & dp){
        if(index == nums.size()){
            if(S == 0){
                return 1;
            } else {
                return 0;
            }
        }
        if(S>1000 or S<-1000){
            return 0;
        }
        if(dp[index][S+1000] != -1){
            return dp[index][S+1000];
        }
        
        int res = helper(nums, S+nums[index], index+1, dp)+helper(nums, S-nums[index], index+1, dp);
        
        return dp[index][S+1000] = res;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        // dp[index][reqSum]
        vector<vector<int>> dp(n+1, vector<int>(2001, -1));
        
        return helper(nums, S, 0, dp);
    }
};