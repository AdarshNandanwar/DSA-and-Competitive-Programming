#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;

    // dp[i] = number of ways of pairing i friends
    vector<ll> dp(n+1, 1);
    for(ll i = 2; i<=n; i++) dp[i] = dp[i-1]+(i-1)*dp[i-2]
    cout<<dp[n]<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}