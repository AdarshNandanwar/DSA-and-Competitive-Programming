// https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    
    int helper(vector<string>& strs, int index, int m, int n, vector<vector<vector<int>>> & dp){
        if(index == strs.size()) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];
        int res = 0, ones = 0, zeros = 0;
        for(auto c:strs[index]){
            if(c == '0') zeros++;
            else ones++;
        }
        if(zeros<=m and ones<=n) res = max(res, 1+helper(strs, index+1, m-zeros, n-ones, dp));
        res = max(res, helper(strs, index+1, m, n, dp));
        return dp[index][m][n] = res;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // dp[i][j][k] = number of strings in [i..n) that can be formed using j 0s and k 1s
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(strs, 0, m, n, dp);
    }
};