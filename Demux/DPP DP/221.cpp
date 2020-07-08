// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // similar question with int matrix https://leetcode.com/problems/count-square-submatrices-with-all-ones/
        
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), maxLength = 0;
        if(m == 0) return 0;
        
        for(auto &i:matrix) for(auto &j:i) j -= '0';
        
        // Histogram stack logic
        vector<vector<char>> cumMatrix = matrix;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(cumMatrix[i][j]) cumMatrix[i][j] += cumMatrix[i-1][j];
            }
        }
                
        // dp[i][j] = length of largest square having bottom left corner at (i,j) 
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Base case
        for(int j = 0; j<m; j++) maxLength = max(maxLength, dp[0][j] = matrix[0][j]);
        for(int i = 0; i<n; i++) maxLength = max(maxLength, dp[i][m-1] = matrix[i][m-1]);
        
        for(int i = 1; i<n; i++){
            for(int j = m-2; j>=0; j--){
                if(dp[i-1][j+1] >= dp[i][j+1]) dp[i][j] = cumMatrix[i][j]>1+dp[i][j+1]?1+dp[i][j+1]:cumMatrix[i][j];
                else dp[i][j] = cumMatrix[i][j]>dp[i][j+1]?dp[i][j+1]:cumMatrix[i][j];
                maxLength = max(maxLength, (int)dp[i][j]);
            }
        }
        
        return maxLength*maxLength;
    }
};