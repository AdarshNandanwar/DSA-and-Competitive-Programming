// https://www.interviewbit.com/problems/0-1-knapsack/

int helper(vector<int> &A, vector<int> &B, int C, int index, vector<vector<int>> & dp){
    int n = A.size();
    if(n == index) return 0;
    if(C < 0) return 0;
    if(dp[index][C] != -1) return dp[index][C];
    int res = helper(A, B, C, index+1, dp);
    if(C-B[index] >= 0) res = max(res, A[index]+helper(A, B, C-B[index], index+1, dp));
    return dp[index][C] = res;
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<vector<int>> dp(A.size(), vector<int>(C+1, -1));
    return helper(A, B, C, 0, dp);
}
