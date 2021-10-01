// https://leetcode.com/problems/longest-common-subsequence/

// Method 1 (2D DP, O(n2)):

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i = l1-1; i>=0; i--){
            for(int j = l2-1; j>=0; j--){
                if(text1[i] == text2[j]) dp[i][j] = 1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};