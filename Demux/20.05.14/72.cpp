// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        
        // prefix subarray
        // dp[i][j] = number of operations required to convert
        //            word[0..i) to word2[0..j)
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        // base cases
        // word1 == ""
        for(int i=0; i<=n2; i++){
            // all insertions
            dp[0][i] = i;
        }
        // word2 == ""
        for(int i =0; i<=n1; i++){
            // all deletions
            dp[i][0] = i;
        }
        
        for(int i = 1; i<=n1; i++){
            for(int j =1; j<=n2; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // insert
                    dp[i][j] = 1+dp[i][j-1];

                    // delete
                    dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);

                    // replace
                    dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
        
    }
};