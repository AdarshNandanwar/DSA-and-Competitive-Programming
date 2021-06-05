#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll a,b;
    cin>>a>>b;
    if(b == 1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"<<a*(b-1)<<" "<<a*(b+1)<<" "<<2*a*b<<endl;
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