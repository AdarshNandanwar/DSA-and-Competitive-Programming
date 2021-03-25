// https://leetcode.com/problems/domino-and-tromino-tiling/

// Method 1 (DP, O(n)):

#define MOD 1000000007

class Solution {
public:
    int numTilings(int N) {
        // dp[i][0] = tiling of width i with last col bottom empty
        // dp[i][1] = tiling of width i with last col complete
        // NOTE-Top empty and bottom empty are symetric and thus their count will be the same. 
        //      Even though they are different states, we don't store redundant info to save space
        vector<vector<long>> dp(N+1, vector<long>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[1][0] = 0;
        dp[1][1] = 1;
        for(int i = 2; i<=N; i++){
            dp[i][0] = (dp[i-1][0]+dp[i-2][1])%MOD;
            dp[i][1] = (2*dp[i-1][0]+dp[i-1][1]+dp[i-2][1])%MOD;
        }
        return dp[N][1];
    }
};