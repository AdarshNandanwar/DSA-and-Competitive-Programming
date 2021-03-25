// https://www.interviewbit.com/problems/increasing-subarrays/?test_id=11890

// Method 1 (DP, NOT TESTED AS CONTEST OVER, O(n)):

#define MOD 1000000007
int Solution::cntInc(vector<int> &A) {
    int n = A.size(), res = 0;
    if(n == 0) return 0;
    vector<int> dp(n, 1);
    for(int i  =1; i<n; i++){
        if(dp[i] > dp[i-1]) dp[i] = (1+dp[i-1])%MOD;
        res = (res + dp[i])%MOD;
    } 
    return res;
}