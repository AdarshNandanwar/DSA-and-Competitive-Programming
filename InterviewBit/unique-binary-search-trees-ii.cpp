// https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int helper(int A, vector<int> & dp){
    if(A <= 1) return 1;
    if(dp[A] != -1) return dp[A];
    int res = 0;
    for(int i = 0; i<A; i++) res += (helper(i, dp)*helper(A-i-1, dp));
    return dp[A] = res;
}

int Solution::numTrees(int A) {
    vector<int> dp(A+1, -1);
    return helper(A, dp);
}
