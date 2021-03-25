// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

#define MOD 1000000007

int helper(const int & A, int B, int index, vector<vector<int>> & dp){
    if(index == A) return B == 0;
    if(B<0) return 0;
    if(dp[B][index] != -1) return dp[B][index];
    int res = 0;
    if(index != 0) res = (res + helper(A, B, index+1, dp))%MOD;
    for(int i = 1; i<=9; i++){
        res = (res + helper(A, B-i, index+1, dp))%MOD;
    }
    return dp[B][index] = res;
}

int Solution::solve(int A, int B) {
    if(A == 0) return 0;
    vector<vector<int>> dp(B+1, vector<int>(A, -1));
    return helper(A, B, 0, dp);
}
