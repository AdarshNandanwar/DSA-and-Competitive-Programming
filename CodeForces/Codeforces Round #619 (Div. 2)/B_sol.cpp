#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){
    ll max_ele = 0, min_ele = 1e9;
    cin>>n;
    ll * arr = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if(arr[i] == -1){
            continue;
        }
        if(i == 0 && arr[i+1] != -1){
            continue;
        }
        if(i == n-1 && arr[i-1] != -1){
            continue;
        }
        if(arr[i-1] == -1 || arr[i+1] == -1){
            max_ele = max(max_ele, arr[i]);
            min_ele = min(min_ele, arr[i]);
        }
    }
    ll k = (max_ele+min_ele)/2;
    for (ll i = 0; i < n; i++)
    {
        if(arr[i] == -1){
            arr[i] = k;
        }
    }
    ll max_diff = 0;
    for (ll i = 1; i < n; i++)
    {
        max_diff = max(max_diff, abs(arr[i]-arr[i-1]));
    }
    
    cout<<max_diff<<" "<<k<<endl;

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