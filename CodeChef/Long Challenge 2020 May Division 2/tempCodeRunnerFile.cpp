#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    ll X, Y, L, R;
    cin>>X>>Y>>L>>R;
    ll max_z = R, max_F = (X&R)*(Y*R);

    for(ll i = log2(R); i >=1; i--){
        if(R & ((ll)1<<i)){
            ll curr_z = (R & (~((ll)1<<i))) | (((ll)1<<i)-1);
            curr_z &= (X|Y);
            ll curr_F = (X&curr_z)*(Y*curr_z);
            if(curr_F >= max_F){
                curr_F = max_F;
                max_z = curr_z;
            }
        }
    }
    cout<<max_z<<endl;
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