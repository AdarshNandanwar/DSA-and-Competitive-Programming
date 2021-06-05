#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;



void solve(){

    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &i:v) cin>>i;

    auto m = min_element(v.begin(), v.end());
    ll i = m-v.begin();

    cout<<n-1<<endl;
    for(int j = i+1; j<n; j++){
        cout<<i+1<<" "<<j+1<<" "<<v[i]<<" "<<v[i]+j-i<<endl;
    }
    for(int j = i-1; j>=0; j--){
        cout<<i+1<<" "<<j+1<<" "<<v[i]<<" "<<v[i]+i-j<<endl;
    }
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