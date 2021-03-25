// https://www.interviewbit.com/problems/distinct-initial-matrices/?test_id=11890

#define MOD 1000000007

long getFact(long n, vector<long> & dp){
    if(n<=1) return dp[n] = 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (n*getFact(n-1, dp))%MOD;
}

long getPow(long n, long p){
    if(p == 0) return 1;
    else return (n*getPow(n, p-1))%MOD;
}

int Solution::cntMatrix(vector<int> &A) {
    long n = A.size(), res = 0;
    vector<long> dpFact(n+1, -1);
    for(long rows = 1; rows<=n; rows++){
        if(n%rows) continue;
        // check if groupwise sorted
        bool isGroupwiseSorted = 1;
        for(long i = 0; i<n; i++){
            if(i%rows and A[i]<A[i-1]) {
                // not first element
                isGroupwiseSorted = 0;
                break;
            } 
        }
        if(isGroupwiseSorted) {
            res = (res + getPow(getFact(rows, dpFact), n/rows))%MOD;
        }
    }
    return res;
}
