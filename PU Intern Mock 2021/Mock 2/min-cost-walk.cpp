// Method 1 (Dijkstra's 3 times):

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>> adj, ll st){
    ll n = adj.size();
    vector<ll> d(n, INT_MAX);

    // dijkstra
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    d[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll cost = cur.first, dest = cur.second;
        if(d[dest] < cost) continue;
        for(auto nbr:adj[dest]){
            if(cost+nbr.first < d[nbr.second]){
                d[nbr.second] = cost+nbr.first;
                pq.push({d[nbr.second], nbr.second});
            }
        }
    }
    return d;
}


void solve(){

    ll n, m, u, v, w;
    cin>>n>>m>>u>>v>>w;
    u--; v--; w--;

    // {wt, dest}
    vector<vector<pair<ll, ll>>> adj(n);

    for(ll i = 0; i<m; i++){
        ll x, y, c;
        cin>>x>>y>>c;
        x--; y--;
        adj[x].push_back({c, y});
        adj[y].push_back({c, x});
    }
    
    auto d1 = dijkstra(adj, u);
    auto d2 = dijkstra(adj, v);
    auto d3 = dijkstra(adj, w);
    
    ll minCost = LLONG_MAX;
    for(ll i = 0; i<n; i++) minCost = min(minCost, d1[i]+d2[i]+d3[i]);
    
    cout<<minCost<<endl;
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

// ATTEMPT 1 (FEW TEST CASES FAILED SINCE THIS LOGIC WORKS ONLY FOR TREE GRAPHS

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>> adj, ll u, ll v){
    ll n = adj.size();
    vector<ll> d(n, INT_MAX), parent(n, -1), path;

    // dijkstra
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

    d[u] = 0;
    pq.push({0, {u, u}});
    // cout<<"dij\n";
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll cost = cur.first, src = cur.second.first, dest = cur.second.second;
        // cout<<src<<" "<<dest<<" "<<cost<<endl;
        if(d[dest] < cost) continue;
        parent[dest] = src;
        if(dest == v) break;
        for(auto nbr:adj[dest]){
            if(cost+nbr.first < d[nbr.second]){
                d[nbr.second] = cost+nbr.first;
                pq.push({d[nbr.second], {dest, nbr.second}});
            }
        }
    }
    // cout<<"parent\n";
    // for(auto p:parent) cout<<p<<" "; cout<<endl;

    // remove weights form path
    for(ll i = v; i!=u; i = parent[i]){
        path.push_back(i);
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}


void solve(){

    ll n, m, u, v, w;
    cin>>n>>m>>u>>v>>w;
    u--; v--; w--;

    vector<vector<pair<ll, ll>>> adj(n);
    unordered_map<ll, unordered_map<ll, ll>> adjMat;

    for(ll i = 0; i<m; i++){
        ll x, y, c;
        cin>>x>>y>>c;
        x--; y--;
        adj[x].push_back({c, y});
        adj[y].push_back({c, x});
        adjMat[x][y] = adjMat[y][x] = c;
    }

    auto p1 = dijkstra(adj, w, u);
    auto p2 = dijkstra(adj, w, v);

    ll n1 =p1.size(), n2 = p2.size();
    ll cost = 0, i, j;
    for(i = 1; i<n1 and i<n2 and p1[i] == p2[i]; i++){
        cost += adjMat[p1[i]][p1[i-1]];
    }
    for(j = i; j<n1; j++){
        cost += adjMat[p1[j]][p1[j-1]];
    }
    for(j = i; j<n2; j++){
        cost += adjMat[p2[j]][p2[j-1]];
    }
    
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