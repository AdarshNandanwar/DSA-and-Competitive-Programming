#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    cin>>n;
    vector<ll> v(n), ans;
    for(auto & i:v){
        cin>>i;
    }
    int zero = 0;

    for(int i = 0; i<n; i++){
        if(v[i] == 0){
            zero++;
            continue;
        }
        if(i+1<n and v[i] == v[i+1]){
            ans.push_back(v[i]*2);
            i++;
            zero++;
            continue;
        }
        ans.push_back(v[i]);
    }

    while(zero--) ans.push_back(0);

    for(auto i:ans) cout<<i<<" ";
    cout<<endl;

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