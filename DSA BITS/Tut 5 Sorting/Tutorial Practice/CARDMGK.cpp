#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll inc_count = 0;
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] < arr[i-1]){
            inc_count++;
        }
    }
    if(inc_count == 0){
        cout<<"YES\n";
        return;
    } else if(inc_count == 1){
        if(arr[n-1] <= arr[0]){
            cout<<"YES\n";  
        } else {
            cout<<"NO\n";
        }
        return;
    } else {
        cout<<"NO\n";
        return;
    }
    
    delete [] arr;
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