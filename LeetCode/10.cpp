// https://leetcode.com/problems/regular-expression-matching/

// Method 1 (2D DP, Bottom Up, O(n*m)):

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        // for "a*" in pattern, choose which index will hold value.
        // here, it is 0 index. Other index's value is ignored
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        // base case
        dp[n][m] = true;
        for(int j = m-2; j>=0; j-=2){
            if(p[j+1] == '*') dp[n][j] = true;
            else break;
        }
        // iteration
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(p[j+1] == '*'){
                    dp[i][j] = dp[i][j] or dp[i][j+2];
                    if(s[i] == p[j] or p[j] == '.'){
                        dp[i][j] = dp[i][j] or dp[i+1][j];
                    }
                } else if(s[i] == p[j] or p[j] == '.'){
                    dp[i][j] = dp[i][j] or dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

// Method 2 (2D DP, Top Down, O(n*m)):

class Solution {
public:
    bool solve(string & s, string & p, int i, int j, vector<vector<int>> & dp){
        if(j == 0) return i == 0;
        if(i<0 or j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        bool res = 0;
        
        if(p[j-1] == '*'){
            // use "p[j]*" zero times
            res = res or solve(s, p, i, j-2, dp);
            if(i-1 >= 0 and s[i-1] == p[j-2] or p[j-2] == '.'){
                // use "p[j]*" one time
                res = res or solve(s, p, i-1, j, dp);
            }
        } else if(i-1 >= 0 and s[i-1] == p[j-1] or p[j-1] == '.'){
            // use p[j] one time
            res = solve(s, p, i-1, j-1, dp);
        }
        
        return dp[i][j] = res;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        // dp[i][j] = is matching s[0..i) and [0..j) ?
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, n, m, dp);
    }
};