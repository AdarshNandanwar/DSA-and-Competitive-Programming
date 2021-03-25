#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    cin>>n;
    vector<ll> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    set<ll> s;
    for(int i = 0; i<n; i++){
        ll temp = (i+v[i])%n;
        if(temp<0) temp+=n;
        if(s.find(temp) != s.end()){
            cout<<"NO\n";
            return;
        }
        s.insert(temp);
    }
    cout<<"YES\n";
    return;
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