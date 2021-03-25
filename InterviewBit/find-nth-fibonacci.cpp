// https://www.interviewbit.com/problems/find-nth-fibonacci/

// Method 1 (Matrix Exponentiation, O(logn)):

#define MOD 1000000007

vector<vector<long>> pow(vector<vector<long>> v, long n, unordered_map<long, vector<vector<long>>> & dp){
    if(n == 0) return {{1, 0}, {0, 1}};
    if(n == 1) return v;
    if(dp.count(n)) return dp[n];
    auto v1 = pow(v, n/2, dp);
    auto v2 = pow(v, n-n/2, dp);
    vector<vector<long>> res(2, vector<long>(2));
    res[0][0] = (v1[0][0]*v2[0][0] + v1[0][1]*v2[1][0])%MOD;
    res[0][1] = (v1[0][0]*v2[0][1] + v1[0][1]*v2[1][1])%MOD;
    res[1][0] = (v1[1][0]*v2[0][0] + v1[1][1]*v2[1][0])%MOD;
    res[1][1] = (v1[1][0]*v2[0][1] + v1[1][1]*v2[1][1])%MOD;
    return dp[n] = res;
}

int Solution::solve(int A) {
    if(A <= 2) return 1;
    vector<vector<long>> v = {{1, 1},{1, 0}};
    // nth fib is pow(v, n-1)
    unordered_map<long, vector<vector<long>>> dp;
    return pow(v, A-1, dp)[0][0];
}

// Attempt 1 (Partially Accepted, O(n)):

#define MOD 1000000007

int Solution::solve(int A) {
    if(A <= 2) return 1;
    A-=2;
    int a = 1, b = 1;
    unordered_map<int, unordered_map> m;
    while(A--){
        swap(a, b);
        b = (a+b)%MOD;
    }
    return b;
}
