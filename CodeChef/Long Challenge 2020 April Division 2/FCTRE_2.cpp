#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

unordered_map<ll,ll> path_cost_map;

void mapDivisors(ll n)  
{  
    while (n % 2 == 0)  
    {  
        path_cost_map[2]++;
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            path_cost_map[i]++;
            n = n/i;  
        }  
    }  
    if (n > 2)  
        path_cost_map[n]++;
}  

ll n;

ll dfs(ll a, ll b, vector<ll> edges[], ll n, bool * visited, ll * cost){
    visited[a] = true;
    if(a == b){
        mapDivisors(cost[a]);
        return 10;
    }
    ll ans = 1;
    for (ll i = 0; i < edges[a].size(); i++)
    {
        if(!visited[edges[a][i]]){
            ll recurse = dfs(edges[a][i], b, edges, n, visited, cost);
            if(recurse != 1){
                ans = recurse;
                mapDivisors(cost[a]);
                break;
            }
        }
    }
    return ans;
}

ll dfs_call(ll a, ll b, vector<ll> edges[], ll n, ll * cost){
    bool * visited = new bool[n+1]();
    return dfs(a,b,edges,n,visited,cost);
}

void solve(){


    scanf("%lld", &n);
    vector<ll> edges[n+1];
    ll * cost = new ll[n+1];
    ll a, b;
    for (ll i = 1; i <= n-1; i++)
    { 
        scanf("%lld %lld", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &cost[i]);
    ll q;
    scanf("%lld", &q);
    for (ll i = 1; i <= q; i++)
    {
        scanf("%lld %lld", &a, &b);
        path_cost_map.clear();
        ll temp = dfs_call(a, b, edges, n, cost);
        ll ans = 1;
        for(auto itr:path_cost_map){
            ans = ((ans%MOD)*(((itr.second%MOD)+1)%MOD))%MOD;
        }
        printf("%lld\n", ans%MOD);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}