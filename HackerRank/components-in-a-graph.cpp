#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dfs(vector<ll> * edges, ll n, bool * visited, ll sv){
    visited[sv] = true;
    ll size = 1;
    vector<ll>::iterator itr;
    for (itr = edges[sv].begin(); itr!= edges[sv].end(); itr++ )
    {
        if(!visited[*itr]){
            size += dfs(edges, n, visited, *itr);
        }
    }
    return size;
}

vector<ll> get_component_sizes(vector<ll> * edges, ll n){
    vector<ll> sizes;
    bool * visited = new bool[2*n]();

    for (ll i = 0; i < 2*n; i++)
    {
        if(!visited[i]){
            sizes.push_back(dfs(edges, n, visited, i));
        }
    }
    return sizes;
}

ll find_smallest_component(vector<ll> sizes){
    ll ans = 15001;
    vector<ll>::iterator itr;
    for (itr = sizes.begin(); itr != sizes.end(); itr++)
    {
        if(*itr == 1){
            continue;
        } else {
            ans = min(ans, *itr);
        }
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> * edges = new vector<ll>[2*n];
    for (ll i = 0; i < n; i++)
    {
        ll sv, ev;
        cin>>sv>>ev;
        sv--;
        ev--;
        edges[sv].push_back(ev);
        edges[ev].push_back(sv);
    }

    vector<ll> component_sizes = get_component_sizes(edges, n);
    cout<<find_smallest_component(component_sizes)<<" "<<*max_element(component_sizes.begin(), component_sizes.end())<<endl;
    
    delete [] edges;
    return 0;
}