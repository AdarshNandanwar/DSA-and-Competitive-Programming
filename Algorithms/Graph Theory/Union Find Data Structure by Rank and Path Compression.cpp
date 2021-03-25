// Union Find Data Structure with Rank and Path Compression

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

void unionFind(vector<vector<int>>& edges) {
    
    // Union Find Data Structure with Rank and Path Compression
    
    int n = edges.size(), r0, r1;
    vector<int> id(n+1, 0), sz(n+1, 1);
    
    for(int i = 1; i<=n; i++) id[i] = i;
    
    for(auto edge:edges){
        r0 = root(edge[0], id);
        r1 = root(edge[1], id);
        if(r0 == r1){
            cout<<"This edge forms cycle"<<endl;
        }
        merge(r0, r1, id, sz);
    }
}