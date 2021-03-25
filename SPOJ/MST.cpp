#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

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

vector<vector<int>> primMST(int n, vector<vector<int>> & edges){
    int curS, curD, curW, nbrN, nbrW;

    // {weight, v}
    vector<vector<pair<int, int>>> adjList(n);

    for(auto e:edges){
        adjList[e[0]].push_back({e[2], e[1]});
        adjList[e[1]].push_back({e[2], e[0]});
    }

    // {{src, des, w}}
    vector<vector<int>> mst;    
    vector<bool> visited(n, false);
    // {weight, {src, des}}
    priority_queue<pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  
    int src = 0;
    pq.push({0, {src, src}});
    
    while (!pq.empty()) 
    {
        if(mst.size() == n-1) break;
        curS = pq.top().second.first; 
        curD = pq.top().second.second; 
        curW = pq.top().first; 
        pq.pop();
        if(visited[curD]) continue;
        visited[curD] = true;
        if(curD != src) mst.push_back({curS, curD, curW});
        for(auto nbr:adjList[curD]){
            nbrN = nbr.second;
            nbrW = nbr.first;
            pq.push({nbrW, {curD, nbrN}});
        }
    }

    return mst;
}

void solve(){

    vector<vector<int>> edges;
    ll n, m;
    cin>>n>>m;

    while(m--){
        int src, des, w;
        cin>>src>>des>>w;
        edges.push_back({src-1, des-1, w});
    }

    vector<vector<int>> mst = kruskalMST(n, edges);

    ll sum = 0;
    for(auto i:mst){
        sum += i[2];
    }

    cout<<sum<<endl;
}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}