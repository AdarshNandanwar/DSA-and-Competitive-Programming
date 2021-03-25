// https://www.interviewbit.com/problems/permutation-swaps/

// Method 1 (Union Find DS):

int root(int x, vector<int> & id){
    if(id[x] == x) return x;
    return id[x] = root(id[x], id);
}

void merge(int r1, int r2, vector<int> & id, vector<int> & sz){
    if(sz[r1] < sz[r2]) swap(r1, r2);
    id[r2] = r1;
    sz[r1] += sz[r2];
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    vector<int> id(n+1), sz(n+1, 1), indInB(n+1);
    for(int i = 0; i<=n; i++) id[i] = i;
    for(int i = 0; i<n; i++) indInB[B[i]] = i;
    
    for(auto e:C) merge(root(A[e[0]-1], id), root(A[e[1]-1], id), id, sz);
    
    for(int i = 0; i<n; i++){
        if(A[i] == B[i]) continue;
        while(A[i] != B[i]){
            if(root(A[i], id) != root(A[indInB[A[i]]], id)) return 0;
            swap(A[i], A[indInB[A[i]]]);
        }
    }
    return 1;
}
