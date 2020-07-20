#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    ll l, r, m, i;
    cin>>l>>r>>m;

    ll lb = m-(r-l), ub = m+(r-l);
    
    for(i = l; i<=r; i++){
        if(ub/i == (ll)floor(((double)lb)/i)){
            if(lb%i == 0) {
                n = (ub/i)*i;
                break;
            }
            else continue;
        } else {
            n = (ub/i)*i;
            break;
        }
    }
    
    ll diff = n-m, b, c;
    if(diff < 0){
        c = l;
        b = l+abs(diff);
    } else {
        c = l+abs(diff);
        b = l;
    }

    cout<<i<<" "<<b<<" "<<c<<endl;
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