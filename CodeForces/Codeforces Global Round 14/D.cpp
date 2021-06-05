#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll l, r, a, cost = 0;
    cin>>n>>l>>r;
    unordered_map<ll, ll> lf, rf;
    for(int i = 0; i<n; i++){
        cin>>a;
        if(i<l) lf[a]++;
        else rf[a]++;
    }

    ll shift_req = abs(l-r)/2;
    // cout<<"shift_req: "<<shift_req<<endl;



    // cout<<"left  "<<l<<": ";
    // for(ll i = 1; i<=n; i++) cout<<lf[i]<<" "; cout<<endl;
    // cout<<"right "<<r<<": ";
    // for(ll i = 1; i<=n; i++) cout<<rf[i]<<" "; cout<<endl;


    if(l > r){
        for(ll c = 1; c<=n and shift_req; c++){
            ll delta = min(shift_req, max(0ll, (lf[c]-rf[c])/2));
            lf[c] -= delta;
            rf[c] += delta;
            l -= delta;
            r += delta;
            cost += delta;
            shift_req -= delta;
        }
    } else if(l < r){
        for(ll c = 1; c<=n and shift_req; c++){
            ll delta = min(shift_req, max(0ll, (rf[c]-lf[c])/2));
            lf[c] += delta;
            rf[c] -= delta;
            l += delta;
            r -= delta;
            cost += delta;
            shift_req -= delta;
        }
    }

    // cout<<"left  "<<l<<": ";
    // for(ll i = 1; i<=n; i++) cout<<lf[i]<<" "; cout<<endl;
    // cout<<"right "<<r<<": ";
    // for(ll i = 1; i<=n; i++) cout<<rf[i]<<" "; cout<<endl;

    if(l > r){
        for(ll c = 1; c<=n and shift_req; c++){
            ll delta = min(shift_req, max(0ll, lf[c]-rf[c]));
            lf[c] -= delta;
            rf[c] += delta;
            l -= delta;
            r += delta;
            cost += delta;
            shift_req -= delta;
        }
    } else if(l < r){
        for(ll c = 1; c<=n and shift_req; c++){
            ll delta = min(shift_req, max(0ll, rf[c]-lf[c]));
            lf[c] += delta;
            rf[c] -= delta;
            l += delta;
            r -= delta;
            cost += delta;
            shift_req -= delta;
        }
    }

    // cout<<"left  "<<l<<": ";
    // for(ll i = 1; i<=n; i++) cout<<lf[i]<<" "; cout<<endl;
    // cout<<"right "<<r<<": ";
    // for(ll i = 1; i<=n; i++) cout<<rf[i]<<" "; cout<<endl;

    ll sum = 0;
    for(ll c = 1; c<=n; c++){
        sum += abs(rf[c]-lf[c]);
    }

    // cout<<"cost: "<<cost<<endl;
    // cout<<"sum: "<<sum<<endl;
    cost += (sum/2);

    cout<<cost<<endl;


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