// https://leetcode.com/problems/largest-divisible-subset/

// Method 1 (DP and path reconstruction using backtracking, O(n2)):

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxSubsetEndIndex = 0, maxSubsetSize = 1;
        // dp[i] = number of multiples of nums[i] in sorted nums[0,i]
        vector<int> dp(n);
        // prev[i] = index of prev multiple of nums[i] in sorted nums[0,i] so that the max size subset can be formed. This may not be the last multiple in sorted nums[0,i].
        vector<int> prev(n, -1);
        for(int i=0; i<n; i++){
            dp[i] = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[i] % nums[j] == 0 and dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    prev[i] = j;
                }
            }
            if(dp[i] > maxSubsetSize){
                maxSubsetSize = dp[i];
                maxSubsetEndIndex = i;
            }
        }
        vector<int> answer;
        for(int i = maxSubsetEndIndex; i != -1; i = prev[i]){
            answer.push_back(nums[i]);
        }
        return answer;
    }
};