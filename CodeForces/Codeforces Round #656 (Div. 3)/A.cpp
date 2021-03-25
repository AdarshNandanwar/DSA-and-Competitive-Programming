#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    vector<int> v(3);
    for(auto & i:v) cin>>i;

    sort(v.begin(), v.end(), greater<int>());
    if(v[0] == v[1]){
        cout<<"YES\n";
        cout<<v[0]<<" "<<v[2]<<" "<<1<<endl;
    } else {
        cout<<"NO\n";
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