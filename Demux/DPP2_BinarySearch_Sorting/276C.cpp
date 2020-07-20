// http://codeforces.com/problemset/problem/276/C

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll q, l, r, res = 0;
    cin>>n>>q;
    vector<ll> v(n), freq(n+1, 0);
    for(auto & i:v) cin>>i;

    sort(v.begin(), v.end());

    for(ll i = 0; i<q; i++){
        cin>>l>>r;
        freq[l-1]++;
        freq[r]--;
    }
    for(ll i = 1; i<n; i++) freq[i] += freq[i-1];
    sort(freq.begin(), freq.end()-1);
    for(ll i = 0; i<n; i++) res += (v[i]*freq[i]);
    cout<<res<<endl;
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