#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m;

ll getWays(ll x){

    ll ans = 0;
    // for (ll i = 1; i <= x/8; i++)
    // {
    //     ans += max((ll)0, (ll)floor(cbrt(x/i))-1);
    // }
    for (ll r = 2; r*r*r <= x; r++)
    {
        ans += (x/(r*r*r));
    }
    
    return ans;
}

void solve(){

    cin>>m;
    ll high = 1e18, low = 0, mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(getWays(mid) < m){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    if(getWays(low) == m){
        cout<<low<<endl;
    } else {
        cout<<-1<<endl;
    }
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