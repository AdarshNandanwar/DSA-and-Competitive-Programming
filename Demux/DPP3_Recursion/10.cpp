// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    
    void solve(string & s, string & p, int i, int j, bool & res, vector<vector<bool>> & dp){
        if(j >= p.length()){
            if(i >= s.length()) res = true;
            return;
        }
        
        if(dp[i][j]) return;
        dp[i][j] = true;
        
        if(j+1 < p.length() and p[j+1] == '*') {
            solve(s, p, i, j+1, res, dp);
            return;
        }
        
        if(p[j] == '*'){
            solve(s, p, i, j+1, res, dp);
            if(res) return;
            if(i < s.length() and (p[j-1] == '.' or s[i] == p[j-1])){
                solve(s, p, i+1, j, res, dp);
                if(res) return;
                solve(s, p, i+1, j+1, res, dp);
            }
        } else if(i < s.length() and (p[j] == '.' or s[i] == p[j])) {
            solve(s, p, i+1, j+1, res, dp);
        }
    }
    
    bool isMatch(string s, string p) {
        bool res = false;
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));
        solve(s, p, 0, 0, res, dp);
        return res;
    }
};