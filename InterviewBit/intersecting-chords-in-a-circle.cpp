// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

// Method 1 (DP, O(n2)):

#define MOD 1000000007

long helper(long n, vector<long> & dp){
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
    long res = 0;
    for(long i = 0; i<n; i++){
        res = (res + (helper(i, dp)*helper(n-i-1, dp))%MOD)%MOD;
    }
    return dp[n] = res%MOD;
}

int Solution::chordCnt(int A) {
    vector<long> dp(A+1, -1);
    return helper(A, dp);
}
