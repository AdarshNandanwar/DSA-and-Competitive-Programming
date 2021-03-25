// https://www.interviewbit.com/problems/longest-palindromic-subsequence/

int helper(string & s, int st, int end, vector<vector<int>> & dp){
    if(st == end) return 1;
    if(st>end) return 0;
    if(dp[st][end] != -1) return dp[st][end];
    if(s[st] == s[end]) return dp[st][end] = 2+helper(s, st+1, end-1, dp);
    else return dp[st][end] = max(helper(s, st+1, end, dp), helper(s, st, end-1, dp));
}

int Solution::solve(string A) {
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(A, 0, n-1, dp);
}
