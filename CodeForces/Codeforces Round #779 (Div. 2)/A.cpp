#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){

    ll n;
    ll m = 0, f = 0;
    cin>>n;
    string s;
    cin>>s;

    if(n == 1){
        cout<<0<<endl;
        return;
    }

    ll ans = 0, prevZero = INT_MIN;

    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            ans += max(0ll, 3-(i-prevZero));
            prevZero = i;
        }
    }
    cout<<ans<<endl;
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