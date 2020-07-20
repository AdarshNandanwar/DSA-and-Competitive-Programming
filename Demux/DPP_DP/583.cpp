// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // similar to https://leetcode.com/problems/edit-distance/
        
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, INT_MAX));
        
        // Base Case
        for(int i = 0; i<=l1; i++) dp[i][l2] = l1-i;
        for(int i = 0; i<=l2; i++) dp[l1][i] = l2-i;
        
        for(int i = l1-1; i>=0; i--){
            for(int j = l2-1; j>=0; j--){
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(1+dp[i+1][j], 1+dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
};