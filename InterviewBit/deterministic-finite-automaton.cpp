// https://www.interviewbit.com/problems/deterministic-finite-automaton

// Method 1 (DP, O(n*k)):

#define MOD 1000000007

int helper(vector<int> &A, vector<int> &B, unordered_set<int> &acceptStates, int cur, int len, vector<vector<int>> &dp){
    if(len == 0) return acceptStates.count(cur);
    if(dp[cur][len] != -1) return dp[cur][len];
    return dp[cur][len] = (helper(A, B, acceptStates, A[cur], len-1, dp) + helper(A, B, acceptStates, B[cur], len-1, dp))%MOD;
}

int Solution::automata(vector<int> &A, vector<int> &B, vector<int> &C, int D, int E) {
    int n = A.size();
    unordered_set<int> acceptStates(C.begin(), C.end());
    vector<vector<int>> dp(n, vector<int>(E+1, -1));
    return helper(A, B, acceptStates, D, E, dp);
}
