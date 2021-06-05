// https://leetcode.com/problems/delete-operation-for-two-strings/

// Method 1 (DP, O(n2)):

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        // base case
        for(int i = 0; i<l1; i++) dp[i][l2] = l1-i;
        for(int j = 0; j<l2; j++) dp[l1][j] = l2-j;
        
        for(int i = l1-1; i>=0; i--){
            for(int j = l2-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1+min(dp[i+1][j], dp[i][j+1]);                    
                }
            }
        }
        return dp[0][0];
    }
};