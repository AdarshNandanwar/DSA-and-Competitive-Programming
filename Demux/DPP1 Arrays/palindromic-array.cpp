#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n);
    for(auto & i:v) cin>>i;

    int p1 = 0, p2 = n-1, count = 0;

    while(p1<p2){
        if(v[p1] == v[p2]){
            p1++; p2--;
            continue;
        }
        if(v[p1]<v[p2]){
            v[p1+1]+=v[p1];
            p1++;
        } else {
            v[p2-1]+=v[p2];
            p2--;
        }
        count++;
    }
    cout<<count<<endl;
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