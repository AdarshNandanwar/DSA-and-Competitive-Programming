// https://leetcode.com/problems/largest-divisible-subset/

// Method 1 (DP and path reconstruction using backtracking, O(n2)):

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), max_len = 1, last_index = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), backtrack(n, -1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]%nums[j] == 0 and dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                    backtrack[i] = j;
                }
            }
            if(max_len < dp[i]){
                max_len = dp[i];
                last_index = i;
            }
        }
        vector<int> ans;
        for(int i = last_index; i != -1; i = backtrack[i]){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};