// https://www.interviewbit.com/problems/tiling-with-dominoes/

// Method 1 (DP, O(n)):

#define MOD 1000000007

int Solution::solve(int A) {
    if(A <= 1) return 0;
    // https://ccodingclub.blogspot.com/2020/08/tiling-with-dominoes-dynamic.html
    vector<vector<long>> dp(A+1, vector<long>(2, 0));
    // dp[i][0] = num of ways to make A*i in which 1*1 missing on top
    // dp[i][1] = num of ways to make A*i in which last col is completely filled
    
    // NOTE-Even though top empty and bottom empty are 2 different states, 
    //      their value will be the same. Thus we store them together in dp[i][0]
    
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 0;
    for(int i = 2; i<=A; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-2][0])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][0] + dp[i-2][1])%MOD;
    }
    return dp[A][1];
}
