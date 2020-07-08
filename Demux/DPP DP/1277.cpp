// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), sum = 0;
        
        // Histogram stack logic
        vector<vector<int>> cumMatrix = matrix;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(cumMatrix[i][j]) cumMatrix[i][j] += cumMatrix[i-1][j];
            }
        }
                
        // dp[i][j] = length of largest square having bottom left corner at (i,j) 
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Base case
        for(int j = 0; j<m; j++) sum += dp[0][j] = matrix[0][j];
        for(int i = 0; i<n; i++) sum += dp[i][m-1] = matrix[i][m-1];
        sum -= dp[0][m-1];
        
        for(int i = 1; i<n; i++){
            for(int j = m-2; j>=0; j--){
                if(dp[i-1][j+1] >= dp[i][j+1]) dp[i][j] = min(cumMatrix[i][j], 1+dp[i][j+1]);
                else dp[i][j] = min(cumMatrix[i][j], dp[i][j+1]);
                sum += dp[i][j];
            }
        }
        
        return sum;
    }
};