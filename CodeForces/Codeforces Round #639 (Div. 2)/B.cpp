#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

vector<ll> pyr;

void solve(){

    cin>>n;
    ll count = 0, i;
    for(i = 0; i<n;i++){
        if(pyr[i] > n){
            break;
        }
    }
    i--;
    while(n>0 && i>=0){
        ll q = n/pyr[i];
        count += q;
        n -= (q*pyr[i]);
        i--;
    }
    cout<<count<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1; i<26000; i++){
        pyr.push_back(((3*i*i)+i)/2);
    }

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}