// https://leetcode.com/problems/stone-game-ii/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size(), sum = 0;
        vector<int> suffixSum(n+1, 0);
        for(int i = n-1; i>=0; i--){
            suffixSum[i] = piles[i]+suffixSum[i+1];
        }
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][j] = the max score the current player can get when 
        //            the game is at i index and the value of m for the turn is j
        
        for(int i = n-1; i>=0; i--){
            for(int j = 1; j<=n; j++){
                sum = 0;
                for(int k = 1; i+k-1<n and k<=2*j; k++){
                    sum+=piles[i+k-1];
                    dp[i][j] = max(dp[i][j], sum+suffixSum[i+k]-dp[i+k][max(j, k)]);
                }
            }
        }
        
        return dp[0][1];
    }
};