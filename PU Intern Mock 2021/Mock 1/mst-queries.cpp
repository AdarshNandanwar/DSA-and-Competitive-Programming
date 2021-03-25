// https://www.hackerrank.com/contests/intern-2020-bpgc/challenges/mst-queries

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll root(ll x, vector<ll> & id){
    if(id[x] == x) return x;
    return id[x] = root(id[x], id);
}

void merge(ll r1, ll r2, vector<ll> & id, vector<ll> & sz){
    if(sz[r1] < sz[r2]) swap(r1, r2);
    id[r2] = r1;
    sz[r1] += sz[r2];
}

vector<ll> kruskal(vector<vector<ll>> & edges, ll n, unordered_map<ll, ll> & ind){
    vector<ll> mst, id(n), sz(n, 1);
    for(ll i = 0; i<n; i++) id[i] = i;
    
    for(auto e:edges){
        if(mst.size() == n-1) return mst;
        ll r1 = root(e[1], id), r2 = root(e[2], id);
        if(r1 == r2) continue;
        mst.push_back(ind[e[0]]);
        merge(r1, r2, id, sz);
    }
    return mst;
}

void solve(){
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> edges(m, vector<ll>(3));
    unordered_map<ll, ll> ind;
    for(ll i = 0; i<m; i++){
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
        if(edges[i][1] == edges[i][2]) continue;
        edges[i][1]--;
        edges[i][2]--;
        ind[edges[i][0]] = i+1;
    }
    sort(edges.begin(), edges.end());
    vector<ll> mst = kruskal(edges, n, ind);
    for(ll i = 0; i<q; i++){
        ll t;
        cin>>t;
        cout<<mst[t-1]<<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
