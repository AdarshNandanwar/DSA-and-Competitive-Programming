#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){

    ll n;
    cin>>n;
    vector<ll> v(n);

    ll one_pos = -1, one_count = 0;
    for(auto &i:v){
        cin>>i;
        if(i == 1){
            one_pos = i;
            one_count++;
        }
    } 
    if(one_count != 1){
        cout<<"NO\n";
        return;
    }

    for(ll i=0; i<n; i++){
        if(v[(one_pos+i+1)%n]-v[(one_pos+i)%n] > 1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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