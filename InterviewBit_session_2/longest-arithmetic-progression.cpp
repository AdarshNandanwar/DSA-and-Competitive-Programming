// https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A) {
    int n = A.size(), res = 0;
    vector<unordered_map<int, int>> dp(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            dp[i][A[i]-A[j]] = 1+dp[j][A[i]-A[j]];
            res = max(res, dp[i][A[i]-A[j]]);
        }
    }
    return 1+res;
}
