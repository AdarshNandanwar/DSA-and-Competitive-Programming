#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll q;
    cin>>n>>q;
    ll * arr = new ll[n+1];
    for(ll i = 1; i<=n; i++){
        cin>> arr[i];
    }

    ll freq[n+1] = {0};
    for(ll i = 0; i<q; i++){
        ll l, r;
        cin>> l>> r;
        freq[l]++;
        freq[r+1]--;
    }
    for(ll i = 1; i<n+1; i++){
        freq[i] += freq[i-1];
    }
    sort(arr+1, arr+n+1);
    sort(freq+1, freq+n+1);
    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        ans += freq[i]*arr[i];
    }
    cout<< ans<<endl;
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