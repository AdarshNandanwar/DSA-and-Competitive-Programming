// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), lis = 1;
        if(n == 0) return 0;
        vector<pair<int, int>> dp(n, {1, 1});
        unordered_map<int, int> m;
        
        // base case
        dp[0] = {1, 1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j] < nums[i]){
                    if(dp[i].first < 1+dp[j].first){
                        dp[i].first = 1+dp[j].first;
                        dp[i].second = 0;
                    }
                    if(dp[i].first == 1+dp[j].first){
                        dp[i].second += dp[j].second;
                    }
                }
            }
            m[dp[i].first] += dp[i].second;
            lis = max(lis, dp[i].first);
        }           
        return m[lis];
    }
};