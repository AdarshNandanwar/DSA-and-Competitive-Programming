#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    ll n, val;
    cin>>n;
    set<ll> s;
    for(ll i=0; i<n; i++){
        cin>>val;
        s.insert(val);
    }
    if(s.count(1)){
        ll prev = -2;
        for(auto &i:s){
            if(i-prev == 1){
                cout<<"NO"<<endl;
                return;
            }
            prev = i;
        }
    }
    cout<<"YES"<<endl;
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