// https://leetcode.com/problems/partition-array-for-maximum-sum/

// Method 1 (1D DP, O(n*k) time, O(n) space):

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // dp[i] = Max sum after partitioning [i,n)
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int subarrayMax = 0;
            for(int j=0; j<k and i+j<n; j++){
                subarrayMax = max(subarrayMax, arr[i+j]);
                dp[i] = max(dp[i], (j+1)*subarrayMax + dp[i+j+1]);
            }
        }
        return dp[0];
    }
};