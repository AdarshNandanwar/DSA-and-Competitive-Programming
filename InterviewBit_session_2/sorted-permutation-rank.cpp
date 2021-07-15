// https://www.interviewbit.com/problems/sorted-permutation-rank/

#define MOD 1000003

long fact(long x){
    if(x == 0) return 1;
    return (x*fact(x-1))%MOD;
}

int Solution::findRank(string A) {
    unordered_set<char> s(A.begin(), A.end());
    long res = 0, n = A.length();
    for(long i = 0; i<n; i++){
        s.erase(A[i]);
        long lesser = 0;
        for(auto &c:s) if(c<A[i]) lesser++;
        res = (res + (lesser*fact(n-i-1))%MOD)%MOD;
    }
    return (res+1)%MOD;
}
