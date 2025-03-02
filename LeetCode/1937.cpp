// https://leetcode.com/problems/maximum-number-of-points-with-cost/

// Method 1 (2D DP with optimization, O(n*m)):

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n));
        for(int j=0; j<n; j++){
            dp[m-1][j] = points[m-1][j];
        }

        for(int i=m-2; i>=0; i--){
            vector<long long> leftMax(n);
            leftMax[0] = dp[i+1][0];
            for(int j=1; j<n; j++){
                leftMax[j] = max(leftMax[j-1]-1, dp[i+1][j]);
            }

            vector<long long> rightMax(n);
            rightMax[n-1] = dp[i+1][n-1];
            for(int j=n-2; j>=0; j--){
                rightMax[j] = max(rightMax[j+1]-1, dp[i+1][j]);
            }

            for(int j=0; j<n; j++){
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        return *max_element(dp[0].begin(), dp[0].end());
    }
};
