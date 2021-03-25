// https://leetcode.com/problems/stone-game/

// Method 1 (DP, trick, decision 1):

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][j] = diff in score of current-other player in piles[i..j] when played optimally
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // base case
        for(int i =0; i<n; i++){
            dp[i][i] = piles[i];
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                dp[i][j] = max(piles[i]-dp[i+1][j], piles[j]-dp[i][j-1]);
            }
        }
        
        return dp[0][n-1]>0;        
    }
};

// Method 2 (DP, decision 2):

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> suffixSum(n+1, 0);
        for(int i=n-1; i>=0; i--){
            suffixSum[i] = suffixSum[i+1]+piles[i];
        }
        
        // dp[i][j] = max score the current player can get in piles[i..j]
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // base case
        for(int i =0; i<n; i++){
            dp[i][i] = piles[i];
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                dp[i][j] = max(piles[i]+(suffixSum[i+1]-suffixSum[j+1])-dp[i+1][j], piles[j]+(suffixSum[i]-suffixSum[j])-dp[i][j-1]);
            }
        }
        
        return 2*dp[0][n-1]>suffixSum[0];        
    }
};