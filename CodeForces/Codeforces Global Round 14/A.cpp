#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll w;
    ll flag = -1;
    cin>>n>>w;
    vector<ll> v(n);
    vector<ll> c(n);
    for(auto & i:v) cin>>i;

    ll sum = 0;
    for(auto & i:v) sum += i;
    if(sum == w){
        cout<<"NO\n";
        return;
    }

    sort(v.begin(), v.end(), greater<ll>());

    c[0] = v[0];
    if(v[0] == w) flag = 0;
    for(ll i = 1; i<n; i++){
        c[i] = c[i-1]+v[i];
        if(c[i] == w) flag = i;
    } 
    cout<<"YES\n";
    
    for(ll i = 0; i<n; i++){
        if(flag == i){
            cout<<v[i+1]<<" "<<v[i]<<" ";
            i++;
            continue;
        }
        cout<<v[i]<<" ";
    } 
    cout<<"\n";
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