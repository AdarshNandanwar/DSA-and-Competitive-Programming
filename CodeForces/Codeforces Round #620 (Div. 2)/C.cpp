#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

void solve(){

    cin>>n>>m;
    ll low = m, high = m, initial = 0;
    bool ans = true;
    ll * t = new ll[n];
    ll * l = new ll[n];
    ll * h = new ll[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>t[i]>>l[i]>>h[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll diff = t[i]-initial;
        initial = t[i];
        low -= diff;
        high += diff;
        low = max(low, l[i]);
        high = min(high, h[i]);
        // cout<<low<<" "<<high<<endl;
        if(low>high){
            ans = false;
            break;
        }
    }
    
    if(ans){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}