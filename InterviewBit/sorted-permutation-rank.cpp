// https://www.interviewbit.com/problems/sorted-permutation-rank/

#define MOD 1000003

vector<int> dp;

int fact(int a){
    if(a <= 0) return 1;
    if(dp[a] != -1) return dp[a];
    return dp[a] = (a*fact(a-1))%MOD;
}

int Solution::findRank(string A) {
    set<char> s;
    for(auto i:A) s.insert(i);
    int res = 1, n = A.length();
    dp = vector<int>(n, -1);
    for(int i = 0; i<n; i++){
        int index = distance(s.begin(), s.lower_bound(A[i]));
        s.erase(A[i]);
        res = (res + (index*fact(n-1-i))%MOD)%MOD;
    }
    return res;
}
