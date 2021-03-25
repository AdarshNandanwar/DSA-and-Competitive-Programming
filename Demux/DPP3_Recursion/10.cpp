// https://leetcode.com/problems/regular-expression-matching/

// Method 1 (DP Bottom Up):

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

// Method 2 (DP Top Down):

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
                res = res or solve(s, p, i-1, j-2, dp);
                // use "p[j]*" more than one time
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