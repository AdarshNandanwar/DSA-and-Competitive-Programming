#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void dfs(vector<vector<ll>> & v, ll i, ll j, ll val, ll & assigned){
    int n = v.size();
    if(assigned == val) return;
    if(i<0 or j<0 or i>=n or j>=n or i<j) return;
    if(i!=j and v[i][j] != 0) return;
    v[i][j] = val;
    assigned++;
    dfs(v, i, j-1, val, assigned);
    dfs(v, i+1, j, val, assigned);
}

void solve(){

    cin>>n;
    vector<vector<ll>> v(n, vector<ll>(n, 0));
    for(ll i = 0; i<n; i++) cin>>v[i][i];

    for(ll i = 0; i<n; i++){
        ll assigned = 0;
        dfs(v, i, i, v[i][i], assigned);
        if(assigned < v[i][i]){
            cout<<-1<<endl;
            return;
        }
    }

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<=i; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}