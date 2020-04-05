#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    ll min_ele = INT_MAX, max_ele = -1;
    ll * arr = new ll[n];
    bool allNeg = true;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i] != -1){
            min_ele = min(arr[i], min_ele);    
            max_ele = max(arr[i], max_ele);    
            allNeg = false;
        }
    }
    if(allNeg){
        cout<<"0 0"<<endl;
        return;
    }
    ll k = (max_ele+min_ele)/2;
    ll ans = 0;
    if(arr[0] == -1){
        arr[0] = k;
    }
    for (ll i = 1; i < n; i++)
    {
        if(arr[i] == -1){
            arr[i] = k;
        }
        ans = max(ans,abs(arr[i]-arr[i-1]));
    }
    cout<<ans<<" "<<k<<endl;

    return;
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