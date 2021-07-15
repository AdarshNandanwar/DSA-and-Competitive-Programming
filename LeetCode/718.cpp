// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

// Method 2 (PD, O(n2));

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), res = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(nums1[i] == nums2[j]) dp[i][j] = 1+dp[i+1][j+1];
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};