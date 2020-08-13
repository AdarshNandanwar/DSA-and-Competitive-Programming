// https://www.interviewbit.com/problems/commutable-islands/

bool cmp(const vector<int> & a, const vector<int> & b){
    return a[2] < b[2];
}

int root(int x, vector<int> & id){
    if(id[x] == x) return x;
    return id[x] = root(id[x], id);
}

void merge(int r1, int r2, vector<int> & id, vector<int> & sz){
    if(sz[r1] < sz[r2]) swap(r1, r2);
    id[r2] = id[r1];
    sz[r1] += sz[r2];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Kruskal's Algorithm using union find with rank and path compression
    vector<int> id(A+1), sz(A+1, 1);
    for(int i=1; i<=A; i++) id[i] = i;
    sort(B.begin(), B.end(), cmp);
    int bridgeCount = 0, totalCost = 0;
    for(int i = 0; i<B.size(); i++){
        int src = B[i][0], dest = B[i][1], cost = B[i][2];
        int r1 = root(src, id), r2 = root(dest, id);
        if(r1 != r2){
            merge(r1, r2, id, sz);
            totalCost += cost;
            bridgeCount++;
        }
        if(bridgeCount == A-1) return totalCost;
    }
    return totalCost;
}
