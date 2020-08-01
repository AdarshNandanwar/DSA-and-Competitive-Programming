// https://leetcode.com/problems/regular-expression-matching/

// Method 1 (DP Bottom Up):

class Solution {
public:
    bool isMatch(string A, string B) {
        int na = A.length(), nb = B.length();

        // dp[i][j] = is [i..na-1] and [j..nb-1] matching
        vector<vector<bool>> dp(na+1, vector<bool>(nb+1, 0));

        // base case
        dp[na][nb] = 1;

        for(int i = na; i>=0; i--){
            for(int j = nb; j>=0; j--){
                if(A[i] == B[j] or B[j] == '.'){
                    if(i+1 <= na and j+1 <= nb) dp[i][j] = dp[i+1][j+1];
                    if(j+1<nb and B[j+1] == '*'){
                        // take B[j] zero times
                        dp[i][j] = dp[i][j] or dp[i][j+2];
                        // take B[j] one time
                        if(i+1 <= na) dp[i][j] = dp[i][j] or dp[i+1][j+2];
                        // take B[j] more than one time. i.e. use B[j] again for [i+1..na-1]
                        if(i+1 <= na) dp[i][j] = dp[i][j] or dp[i+1][j];
                    }
                } else {
                    if(j+1<nb and B[j+1] == '*'){
                        // take B[j] zero times
                        dp[i][j] = dp[i][j+2];
                    }
                }
            }
        }

        return dp[0][0];
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