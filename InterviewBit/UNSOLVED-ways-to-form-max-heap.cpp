// https://www.interviewbit.com/problems/ways-to-form-max-heap/

// Failing for larger test cases

// Attempt 2

#define MOD 1000000007
typedef long long int ll;

vector<vector<ll>> dpC(101, vector<ll>(101, -1));
vector<ll> dp(101, -1);

ll nCr(ll n, ll r){
    if(dpC[n][r] != -1) return dpC[n][r];
    if(n<r) return 0;
    if(n == r or r == 0) return dpC[n][r] = 1;
    return dpC[n][r] = (nCr(n-1, r)+nCr(n-1, r-1))%MOD;
}

int Solution::solve(int A) {
    if(A <= 2) return 1;
    if(dp[A] != -1) return dp[A];
    ll h = log(A);
    ll extra = A-((1<<(h+1))-1);
    ll leftExtra = min(extra, (1ll<<h));
    ll rightExtra = (extra-leftExtra);
    ll leftN = ((1<<h)-1+leftExtra);
    ll rightN = ((1<<h)-1+rightExtra);
    return dp[A] = (nCr(A-1, leftN)*((solve(rightN)*solve(leftN))%MOD))%MOD;
}

// Attempt 1

#define MOD 1000000007
typedef long long ll;

vector<vector<ll>> dpC(101, vector<ll>(101, -1));

ll nCr(ll n, ll r)
{
    if (dpC[n][r] != -1)
        return dpC[n][r];
    if (n == r or r == 0)
        return dpC[n][r] = 1;
    return dpC[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % MOD;
}

vector<ll> dp(101, -1);

int Solution::solve(int A)
{
    if (A <= 2)
        return 1;
    if (dp[A] != -1)
        return dp[A];
    ll h = 0;
    while ((1 << (h + 1)) - 1 <= A)
        h++;
    h--;
    ll extra = A - ((1 << (h + 1)) - 1);
    ll leftExtra = min(extra, (1ll << h)), rightExtra = extra - leftExtra;
    ll leftN = (1 << h) - 1 + leftExtra, rightN = (1 << h) - 1 + rightExtra;
    return dp[A] = (nCr(A - 1, leftN) * ((solve(rightN) * solve(leftN)) % MOD)) % MOD;
}