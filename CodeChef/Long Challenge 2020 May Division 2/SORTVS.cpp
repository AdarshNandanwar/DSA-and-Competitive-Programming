#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){

    ll m, temp;
    cin>>n>>m;
    vector<ll> pos(n);
    for(int i =0; i<n; i++){
        cin>>temp;
        pos[temp-1] = i;
    }
    vector<ll> x(m), y(m);;
    for (ll i = 0; i < m; i++)
    {
        cin>>x[i]>>y[i];
    }
    
    
    vector<ll> comp_size;
    vector<bool> visited(n, false);
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        if(!visited[i]){
            count = 0;
            ll p = i;
            while(!visited[p]){
                visited[p] = true;
                count++;
                p = pos[p];
            }
            comp_size.push_back(count);
        }
    }
    ll ans = 0;
    for(auto i:comp_size){
        ans += (i-1);
    }cout<<endl;
    cout<<ans<<endl;
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