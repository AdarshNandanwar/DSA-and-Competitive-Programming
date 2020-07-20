#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<pair<ll, ll>> v(n);
    for(auto & [i,j]:v) cin>>i>>j;
    sort(v.begin(), v.end());
    ll maxDay = 0;
    for(auto [i,j]:v) maxDay = j<maxDay ? max(maxDay, i) : j;
    cout<<maxDay<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}