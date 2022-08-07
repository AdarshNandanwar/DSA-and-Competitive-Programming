#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<vector<ll>> freq((1<<17)+1, vector<ll>(64, 0));

void solve(){

    ll l, r, a;
    cin>>l>>r;

    vector<ll> v(64, 0);
    for(ll i=0; i<r-l+1; i++){
        cin>>a;
        for(ll j=0; j<64; j++){
            v[j] += ((a>>j)&1);
        }
    }

    vector<ll> target(freq[r]);
    if(l>0){
        for(ll i=0; i<64; i++){
            target[i] -= freq[l-1][i];
        }
    }

    ll ans = 0;
    for(ll i=0; i<64; i++){
        if(v[i] != target[i]){
            ans += (1<<i);
        }
    }
    cout<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(ll i=1; i<=1<<17; i++){
        for(ll j=0; j<64; j++){
            freq[i][j] = ((i>>j)&1)+freq[i-1][j];
        }
    }

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}