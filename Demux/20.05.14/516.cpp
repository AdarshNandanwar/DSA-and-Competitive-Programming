// https://leetcode.com/problems/longest-palindromic-subsequence/

// Method 1 (DP, easy to understand, O(n2)):

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // dp[i][j] = LPS in [i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base Case
        for(int i = 0; i<n; i++) dp[i][i] = 1;
        
        for(int i = n-2; i>=0; i--){
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};

// Method 1 (DP, unclean code, O(n2)):

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // DP on length
        vector<vector<int>> dp(n+1,vector<int>(n+1, 0));
        // dp[i][j] = len of longest palindromic subsequence in [i..j] inclusive
        
        
        // base case
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
            
        for(int i = 2; i<=n; i++){              // length
            for(int j = 0; j+i-1<n; j++){       // start index
                if(s[j] == s[j+i-1]){
                    dp[j][j+i-1] = 2+dp[j+1][j+i-2];
                } else {
                    dp[j][j+i-1] = max(dp[j+1][j+i-1], dp[j][j+i-2]);
                }
            }
        }
        
        return dp[0][n-1];           
    }
};