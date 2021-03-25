#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;

void solve(){
    ll n;
    cin>>n;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    ll * left_odd = new ll[n];
    ll * right_odd = new ll[n];
    left_odd[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i-1]%2 != 0){
            left_odd[i] = left_odd[i-1]+1;
        } else {
            left_odd[i] = 0;
        }
    }
    right_odd[n-1] = 0;
    for (ll i = n-2; i >= 0; i--)
    {
        if(arr[i+1]%2 != 0){
            right_odd[i] = right_odd[i+1]+1;
        } else {
            right_odd[i] = 0;
        }
    }
    
    ll ans = (n*(n+1))/2;
    for (ll i = 0; i < n; i++)
        if(arr[i]%4 == 2)
            ans -= (left_odd[i]+1)*(right_odd[i]+1);

    cout<<ans<<"\n";

    delete [] arr;
    delete [] left_odd;
    delete [] right_odd;
}
 
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}