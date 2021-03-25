// Kruskal's Algorithm with Union Find by Rank and Path Compression

#include<bits/stdc++.h>
using namespace std;

int root(int x, vector<int> & id){
    int r = x, p;
    while(r != id[r]){
        r = id[r];
    }
    while(x != r){
        p = id[x];
        id[x] = r;
        x = p;
    }
    return r;
}

void merge(int r0, int r1, vector<int> & id, vector<int> & sz){
    if(sz[r0] < sz[r1]){
        id[r0] = r1;
        sz[r1] += sz[r0];
    } else {
        id[r1] = r0;
        sz[r0] += sz[r1];
    }
}

bool cmp(vector<int> & a, vector<int> & b){ return a[2]<b[2]; }

vector<vector<int>> kruskalMST(int n, vector<vector<int>>& edges) {
    
    // Kruskal's Algorithm with Union Find Data Structure with Rank and Path Compression
    
    int r0, r1;
    vector<int> id(n, 0), sz(n, 1);
    vector<vector<int>> mst;

    for(int i = 0; i<n; i++) id[i] = i;
    sort(edges.begin(), edges.end(), cmp);
    
    for(auto edge:edges){
        if(mst.size() == n-1){
            break;
        }
        r0 = root(edge[0], id);
        r1 = root(edge[1], id);
        if(r0 == r1){
            continue;
        }
        merge(r0, r1, id, sz);
        mst.push_back(edge);
    }

    return mst;
}