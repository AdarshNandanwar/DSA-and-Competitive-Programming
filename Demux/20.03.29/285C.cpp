#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll * arr = new ll[n];
    for(ll i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    ll ans =0;
    for(ll i = 1; i<=n; i++){
        ans += abs(i-arr[i-1]);
    }
    cout<<ans<<endl;
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