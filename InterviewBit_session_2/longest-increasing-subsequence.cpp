// https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &A) {
    int n = A.size(), res = 0;
    vector<int> dp(n, 1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(A[i] > A[j]) dp[i] = max(dp[i], 1+dp[j]);
        }
        res = max(res, dp[i]);
    }
    return res;
}
