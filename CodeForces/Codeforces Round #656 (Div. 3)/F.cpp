#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

ll helper(vector<vector<ll>> & adjList, ll v, ll & k, vector<ll> & dp, vector<bool> & visited){
    if(dp[v] != -1) return dp[v];
    if(visited[v]) return 0;
    visited[v] = true;
    
    ll res = adjList[v].size()/k + (adjList[v].size()%k == 0 ? 0 : 1);
    for(auto nbr:adjList[v]){
        res += helper(adjList, nbr, k, dp, visited);
    }
    return dp[v] = res;
}

void solve(){

    ll k;
    cin>>n>>k;
    vector<vector<ll>> adjList(n);

    for(ll i = 0; i<n-1; i++){
        ll a, b;
        cin>>a>>b;
        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }

    ll moves = INT_MAX;

    vector<bool> visited(n);
    vector<ll> dp(n+1, -1);
    for(ll i = 0; i<n; i++){
        moves = min(moves, helper(adjList, i, k, dp, visited));
    }
    cout<<moves<<endl;
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