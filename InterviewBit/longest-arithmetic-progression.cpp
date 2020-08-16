// https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A) {
    int n = A.size(), res = -1;
    if(n <= 1) return n;
    vector<unordered_map<int, int>> dp(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(dp[j].count(A[i]-A[j])) dp[i][A[i]-A[j]] = max(dp[i][A[i]-A[j]], 1+dp[j][A[i]-A[j]]);
            else dp[i][A[i]-A[j]] = 1;
            res = max(res, dp[i][A[i]-A[j]]);
        }
    }
    return res+1;
}
