// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    if(n == 0) return 0;
    if(n == 1) return max(A[0][0], A[1][0]);
    
    // dp[i] = max(max(A[i][0], A[i][1])+d[i-2], dp[i-1]);
    vector<int> dp(n, 0);
    // base case
    dp[0] = max(A[0][0], A[1][0]);
    dp[1] = max(max(A[0][1], A[1][1]), dp[0]);
    for(int i = 2; i<n; i++) dp[i] = max(max(A[0][i], A[1][i])+dp[i-2], dp[i-1]);
    return dp[n-1];
}
