#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<vector<ll>> freq(1<<17+1, vector<ll>(32, 0));

void solve(){

    ll l, r;
    cin>>l>>r;
    ll n = r+1, a;
    vector<int> v(32, 0);
    ll ans = 0;
    for(ll i=0; i<n; i++){
        cin>>a;
        for(ll j=0; j<32; j++){
            v[j] += ((a>>j)&1);
        }
    }
    for(ll i=0; i<32; i++){
        if(v[i] != freq[n-1][i]){
            ans += (1<<i);
        }
    }
    cout<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(ll i=1; i<1+1<<17; i++){
        for(ll j=0; j<32; j++){
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