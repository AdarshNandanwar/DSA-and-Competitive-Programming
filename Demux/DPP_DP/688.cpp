// https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
    
    int R[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int C[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    
    double helper(int r, int c, int k, int & n, vector<vector<vector<double>>> & dp){
        if(r<0 or c<0 or r>=n or c>=n) return  0.0;
        if(k == 0) return 1.0;
        
        if(dp[r][c][k] != -1) return dp[r][c][k];
        double res = 0;
        
        for(int a = 0; a<8; a++) res += helper(r+R[a], c+C[a], k-1, n, dp);
        
        return dp[r][c][k] = res/8.0;
    }
    
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, -1)));
        return helper(r, c, K, N, dp);
    }
};