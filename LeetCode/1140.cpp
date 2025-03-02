// https://leetcode.com/problems/stone-game-ii/

// Method 1 (2D DP, Game Theory, O(n3) time, O(n2) space):

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffixSum(n+1, 0);
        for(int i=n-1; i>=0; i--){
            suffixSum[i] = piles[i] + suffixSum[i+1];
        }

        // dp[i][j] = stones collected in [i..n-1] when played optimally with m=j
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n; i>=0; i--){
            for(int j=n; j>=0; j--){
                for(int x=1; x<=min(2*j, n-i); x++){
                    dp[i][j] = max(dp[i][j], suffixSum[i] - suffixSum[i+x] + (suffixSum[i+x] - dp[i+x][max(x, j)]));
                }
            }
        }

        return dp[0][1];
    }
};
