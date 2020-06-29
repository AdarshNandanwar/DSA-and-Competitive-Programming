// https://leetcode.com/problems/partition-equal-subset-sum/

// Method 1 (Check if sum can be made 0 by assigning each element + or - sign) (496 leetcode):

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
        if(S>20000 or S<-20000){
            return 0;
        }
        if(dp[index][S+20000] != -1){
            return dp[index][S+20000];
        }
        
        int res = helper(nums, S+nums[index], index+1, dp) | helper(nums, S-nums[index], index+1, dp);
        
        return dp[index][S+20000] = res;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        // dp[index][reqSum]
        vector<vector<int>> dp(n+1, vector<int>(40001, -1));
        
        return helper(nums, 0, 0, dp);
    }
};

// Method 2 (Inclusion, Exclusion):

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
        if(S == 0){
            return 1;
        } else if(S < 0){
            return 0;
        }
        
        if(dp[index][S] != -1){
            return dp[index][S];
        }
        
        int res = helper(nums, S, index+1, dp) | helper(nums, S-nums[index], index+1, dp);
        
        return dp[index][S] = res;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        // dp[index][reqSum]
        vector<vector<int>> dp(n+1, vector<int>(20001, -1));
        
        for(auto i:nums){
            sum += i;
        }

        if(sum%2) return false;
        return helper(nums, sum/2, 0, dp);
    }
};