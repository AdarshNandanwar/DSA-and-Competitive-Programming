#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    ll k, res = 0, i;
    cin>>n>>k;
    unordered_set<ll> s;
    while(n--){
        cin>>i;
        if(s.count(i-k) or s.count(i+k)) res = 1;
        s.insert(i);
    }
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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