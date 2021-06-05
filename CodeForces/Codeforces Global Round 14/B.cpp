#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    if(n%2) {
        cout<<"NO\n";
        return;
    }
    while(n%2 == 0) n/=2;
    ll rt = sqrt(n);
    if(rt*rt == n){
        cout<<"YES\n";
        return;
    } else {
        cout<<"NO\n";
        return;
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