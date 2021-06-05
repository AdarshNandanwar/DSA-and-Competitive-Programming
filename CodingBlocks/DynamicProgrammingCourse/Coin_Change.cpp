// Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, In how many ways can we make the change? The order of coins doesn’t matter.

// Input Format
// First line of input contain two space separated integers N and M. Second line of input contains M space separated integers - value of coins.

// Constraints
// 1<=N<=250 1<=m<=50 1 <= Si <= 50

// Output Format
// Output a single integer denoting the number of ways to make the given change using given coin denominations.

// Sample Input
// 10 4
// 2 5 3 6
// Sample Output
// 5

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

ll helper(ll sum, ll start, ll & n, vector<ll> & change, vector<vector<ll>> & dp){
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(dp[sum][start] != -1) return dp[sum][start];

    ll res = 0;
    for(ll i = start; i<change.size(); i++){
        res += helper(sum-change[i], i, n, change, dp);
    }
    return dp[sum][start] = res;
}

void solve(){

    cin>>n;
    ll m;
    cin>>m;
    vector<ll> v(m);
    for(auto &i:v) cin>>i;
    vector<vector<ll>> dp(n+1, vector<ll>(m, -1));
    cout<<helper(n, 0, n, v, dp)<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}