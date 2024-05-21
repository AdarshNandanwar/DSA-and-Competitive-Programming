// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/

// Method 1 (2D DP, Iterative, O(n^2*d)):

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        // dp[i][j] = cost if we start a new group at this index and use j days (create exactly j groups)
        vector<vector<int>> dp(n+1, vector<int>(d+1, 1e5));
        dp[n][0] = 0;

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=d; j++){
                int maxValInGroup = -1;
                for(int k=i; k<n; k++){
                    maxValInGroup = max(maxValInGroup, jobDifficulty[k]);
                    if(j-1 > n-k-1){
                        break;
                    }
                    dp[i][j] = min(dp[i][j], maxValInGroup + dp[k+1][j-1]);
                }
            }
        }
        return dp[0][d] >= 1e5 ? -1 : dp[0][d];
    }
};