// https://www.interviewbit.com/problems/tiling-with-dominoes/

// Method 1 (DP, O(n)):

int Solution::solve(int A) {
    if(A == 1) return 0;
    // using symmetry
    // dp[i][0] = ith col has one filled near edge
    // dp[i][1] = ith col has one empty near edge
    // dp[i][2] = ith col has all filled
    vector<vector<long>> dp(A, vector<long>(3, 0));
    dp[0][1] = dp[1][0] = 1;
    dp[1][2] = 3;
    for(int i = 2; i<A; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (dp[i-1][0]+dp[i-1][2])%1000000007;
        dp[i][2] = (2*dp[i-1][1]+dp[i-2][2])%1000000007;
    }
    return dp[A-1][2];
}
