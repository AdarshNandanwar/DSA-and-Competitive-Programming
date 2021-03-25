// https://leetcode.com/problems/maximum-subarray/

// Method 1 (Dynamic Programming):

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        // sum of longest subarray ending at i
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i =1; i<n; i++){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
        }
        return *max_element(dp.begin(), dp.end());
        
    }
};

// Method 2 (Kadane's Algorithm):

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int sum = 0, max_sum = INT_MIN;
        for(int i =0; i<n; i++){
            sum+=nums[i];
            max_sum = max(max_sum, sum);
            if(sum<0) sum = 0;
        }
        return max_sum;
    }
};


