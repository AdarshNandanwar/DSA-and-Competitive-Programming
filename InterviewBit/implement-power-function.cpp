// https://www.interviewbit.com/problems/implement-power-function/

typedef long long int ll;

ll helper(ll x, ll n, ll d, unordered_map<ll, ll> & dp){
    if(x == 0) return 0ll;
    if(n == 0) return 1ll;
    if(n == 1) return x;
    if(dp.count(n)) return dp[n];
    return dp[n] = (helper(x, n/2, d, dp)*helper(x, n-n/2, d, dp))%d;
}

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<ll, ll> dp;
    ll res = helper(x, n, d, dp);
    return res<0 ? res+d : res;
}
