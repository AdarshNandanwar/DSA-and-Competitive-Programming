#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll x, vector<ll> * edges, bool * visited, ll n, ll * component_size, ll count){
    if(visited[x]) return;
    visited[x] = true;
    component_size[count]++;
    vector<ll>::iterator itr;
    for(itr = edges[x].begin(); itr != edges[x].end(); itr++){
        dfs(*itr, edges, visited, n, component_size, count);
    }
}

ll find_connected_components(ll n, ll m, vector<ll> * edges, ll * component_size){
    ll count = 0;
    bool * visited = new bool[n];
    for (ll i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (ll i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        dfs(i, edges, visited, n, component_size, count);
        count++;
    }
    return count;
}

int main(){
    ll t;
    cin>>t;
    while (t--)
    {
        ll n, m, cl, cr;
        cin>>n>>m>>cl>>cr;

        vector<ll> * edges = new vector<ll>[n];
        for (ll i = 0; i < m; i++)
        {
            ll v1, v2;
            cin>>v1>>v2;
            v1--;
            v2--;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        

        ll * component_size = new ll[n]();
        ll count = find_connected_components(n, m, edges, component_size);
        if(cl<cr){
            cout<<n*cl<<endl;
        } else {
            ll cost = (count*cl);
            for (ll i = 0; i < count; i++)
            {
                cost+=((component_size[i]-1)*cr);
            }
            cout<<cost<<endl;
        }
        
    }
    return 0;
}
