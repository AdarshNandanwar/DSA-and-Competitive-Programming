// https://www.interviewbit.com/problems/tushars-birthday-party/

int helper(const vector<int> &B, const vector<int> &C, int target, unordered_map<int, int> &dp){
    if(target == 0) return 0;
    if(dp.count(target)) return dp[target];
    int res = 10e7, n = B.size();
    for(int i = 0; i<n; i++){
        if(target-B[i] >= 0) res = min(res, C[i]+helper(B, C, target-B[i], dp));
    }
    return dp[target] = res;
}


int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    unordered_map<int, int> dp;
    int n = A.size(), res = 0;
    for(int i = 0; i<n; i++) res += helper(B, C, A[i], dp);
    return res;
}