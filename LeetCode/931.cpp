// https://leetcode.com/problems/minimum-falling-path-sum/description/

// Method 1 (2D DP, O(n2)):

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                dp[i][j] = matrix[i][j] + dp[i+1][j];
                if(j-1>=0){
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i+1][j-1]);
                }
                if(j+1<n){
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i+1][j+1]);
                }
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};