// https://www.interviewbit.com/problems/stairs/

int Solution::climbStairs(int A) {
    if(A <= 1) return 1;
    // dp[i] = num of ways to climb i stairs
    vector<int> dp(A+1, 1);
    for(int i = 2; i<=A; i++) dp[i] = dp[i-1]+dp[i-2];
    return dp[A];
}
