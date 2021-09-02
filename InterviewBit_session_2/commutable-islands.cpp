// https://www.interviewbit.com/problems/commutable-islands/

int root(int x, vector<int> &id){
    if(x == id[x]) return x;
    return id[x] = root(id[x], id);
}

void merge(int r1, int r2, vector<int> &id, vector<int> &sz){
    if(sz[r1] > sz[r2]) swap(r1, r2);
    id[r1] = r2;
    sz[r2] += sz[r1];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), [](const vector<int> & a, const vector<int> & b){
        return a[2] < b[2];
    });
    vector<int> id(A+1), sz(A+1, 1);
    for(int i = 1; i<A+1; i++) id[i] = i;
    int cost = 0, count = 0;
    for(auto &e:B){
        int r1 = root(e[0], id);
        int r2 = root(e[1], id);
        if(r1 == r2) continue;
        merge(r1, r2, id, sz);
        count++;
        cost += e[2];
        if(count == A-1) return cost;
    }
    return -1;
}
