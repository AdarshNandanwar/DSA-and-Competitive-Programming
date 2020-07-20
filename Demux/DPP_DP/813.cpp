// https://leetcode.com/problems/largest-sum-of-averages/

// Method 1 (DP, O(n*n*k)):

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        
        // next partition
        // dp[i][k] : max sum in [i,n-1] with k groups (k-1 partitions)
        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));
        
        // base case
        for(int i = 0; i<n; i++) dp[i][0] = INT_MIN;
        
        for(int i = n-1; i>=0; i--){
            double cumSum = A[i];
            for(int j = i+1; j<=n; j++){
                for(int k = 1; k<=min(K, n-i); k++){
                    dp[i][k] = max(dp[i][k], cumSum/(j-i) + dp[j][k-1]);
                }
                if(j<n) cumSum += A[j];
            }
        }
        
        return *max_element(dp[0].begin(), dp[0].end());
    }
};