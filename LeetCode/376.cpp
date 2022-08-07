// https://leetcode.com/problems/wiggle-subsequence/

// Method 1 (2D DP, O(n)):

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        // dp[i][j] = longest wiggle subsequence ending on or before i with sign j
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            } else {
                bool sign = nums[i-1]<nums[i];
                dp[i][sign] = 1+dp[i-1][!sign];
                dp[i][!sign] = dp[i-1][!sign];
                maxLen = max(maxLen, dp[i][sign]);
            }
        }
        return maxLen;
    }
};

// Method 1 (2D DP, O(n2)):

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        // dp[i][j] = longest wiggle subsequence starting on i with sign j
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]){
                    continue;
                }
                bool sign = nums[i]<nums[j];
                dp[i][sign] = max(dp[i][sign], 1+dp[j][!sign]);
                maxLen = max(maxLen, dp[i][sign]);
            }
        }
        return maxLen;
    }
};