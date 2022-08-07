#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

vector<ll> fact(1001, 1);

void solve(){

    ll n;
    cin>>n;
    if(n%2){
        cout<<0<<endl;
    } else {
        cout<<fact[n/2]<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(ll i = 1; i<1001; i++){
        fact[i] = (((i*i)%MOD)*fact[i-1])%MOD;
    }

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}