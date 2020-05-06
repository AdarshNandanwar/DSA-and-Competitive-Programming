#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    cin>>n;
    vector<ll> v;
    for(int i =0; i<n; i++){
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    unordered_map<int, int> mp;
    vector<ll> nv(n);
    for(int i = 0; i<n; i++){
        ll k = v[i];
        ll mod = (k%n);
        cout<<mod<<" ";
        // if(mod<0) mod+=n;
        nv[i] = k+(v[mod]);
        // if(mp[nv[i]]){
        //     cout<<"NO\n";
        //     return;
        // }
        // mp[nv[i]]++;
        // cout<<nv[i]<<" ";
    }cout<<endl;
    // cout<<"YES\n";
    
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