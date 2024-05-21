// https://leetcode.com/problems/longest-ideal-subsequence/

// Method 1 (2D DP, O(n) time, O(1) space):

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(2, vector<int>(26));
        // dp[j][j] = longest ideal subsequence in [i,n) that starts with letter 'a'+j
        for(int i=n-1; i>=0; i--){

            // Case 1: Choose s[i];
            for(int j=max(s[i]-'a'-k, 0); j<=min(25, s[i]-'a'+k); j++){
                dp[i%2][s[i]-'a'] = max(dp[i%2][s[i]-'a'], 1 + dp[(i+1)%2][j]);
            }

            // Case 2: Skip s[i];
            for(int j=0; j<26; j++){
                if(j == (s[i]-'a')){
                    continue;
                }
                dp[i%2][j] = dp[(i+1)%2][j];
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};

// Method 2 (2D DP, O(n) time, O(n) space):

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(26));
        // dp[j][j] = longest ideal subsequence in [i,n) that starts with letter 'a'+j
        for(int i=n-1; i>=0; i--){

            // Case 1: Choose s[i];
            for(int j=max(s[i]-'a'-k, 0); j<=min(25, s[i]-'a'+k); j++){
                dp[i][s[i]-'a'] = max(dp[i][s[i]-'a'], 1 + dp[i+1][j]);
            }

            // Case 2: Skip s[i];
            for(int j=0; j<26; j++){
                if(j == (s[i]-'a')){
                    continue;
                }
                dp[i][j] = dp[i+1][j];
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};
