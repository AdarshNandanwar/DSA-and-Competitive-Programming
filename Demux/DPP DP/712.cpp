// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        // similar to https://leetcode.com/problems/edit-distance/
        
        int l1 = s1.length(), l2 = s2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, INT_MAX));
        
        // Base Case
        dp[l1][l2] = 0;
        for(int i = l1-1; i>=0; i--) dp[i][l2] = s1[i]+dp[i+1][l2];
        for(int i = l2-1; i>=0; i--) dp[l1][i] = s2[i]+dp[l1][i+1];
        
        for(int i = l1-1; i>=0; i--){
            for(int j = l2-1; j>=0; j--){
                if(s1[i] == s2[j]){ 
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(s1[i]+dp[i+1][j], s2[j]+dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
};