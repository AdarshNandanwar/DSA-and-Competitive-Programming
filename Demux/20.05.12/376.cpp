// https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        if(n == 0){
            return 0;
        }
        // <inc, dec>
        vector<pair<int, int>> dp(n, {1,1});
        for(int i = 1; i<n ; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i].first = max(dp[i].first, 1+dp[j].second);
                } else if(nums[i]<nums[j]){
                    dp[i].second = max(dp[i].second, 1+dp[j].first);
                }
            }
            maxLen = max(maxLen, max(dp[i].first, dp[i].second));
        }
        return maxLen;
    }
};