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
    ll n, m;
    cin>>n>>m;

    vector<ll> * edges = new vector<ll>[n];
    for (ll i = 0; i < m; i++)
    {
        ll v1, v2;
        cin>>v1>>v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    

    ll * component_size = new ll[n]();
    ll count = find_connected_components(n, m, edges, component_size);
    
    if(count < 2){
        cout<<0<<endl;
    } else {
        ll pairs = 0;
        // for (ll i = 0; i < count; i++)
        // {
        //     for (ll j = i+1; j < count; j++)
        //     {
        //         pairs+=(component_size[i]*component_size[j]);
        //     }
        // }
        // to do the above in O(n)
        ll * cdf = new ll[n]();
        for (ll i = 0; i < count-1; i++)
        {
            cdf[i] = component_size[i+1];
        }
        cdf[count-1] = 0;
        for (ll i = count-2; i >= 0; i--)
        {
            cdf[i]+=cdf[i+1];
        }
        for (ll i = 0; i < count; i++)
        {
            pairs+=(component_size[i]*cdf[i]);
        }
        cout<<pairs<<endl;
    }
    return 0;
}
