// https://www.interviewbit.com/problems/max-edge-queries/

// Method 1 (binary lifting concept, O(q*n)):

typedef long long ll;

void buildTree(vector<vector<ll>> & adjList, ll root, ll par, ll ht, vector<ll> & parent, vector<ll> & height){
    parent[root] = par;
    height[root] = ht;
    for(auto nbr:adjList[root]){
        if(nbr == par) continue;
        buildTree(adjList, nbr, root, ht+1, parent, height);
    }
}

ll helper(vector<vector<ll>> & adjList, vector<unordered_map<ll, ll>> & w, ll u, ll v, vector<ll> & parent, vector<ll> & height){
    if(u == v) return 0;
    ll res;
    if(height[u] < height[v]){
        res = max(w[v][parent[v]], helper(adjList, w, u, parent[v], parent, height));
    } else {
        res = max(w[u][parent[u]], helper(adjList, w, parent[u], v, parent, height));
    }
    return res;
}

vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    ll n = A.size()+1;
    vector<vector<ll>> adjList(n);
    vector<unordered_map<ll, ll>> w(n);
    for(auto i:A){
        adjList[i[0]-1].push_back(i[1]-1);
        adjList[i[1]-1].push_back(i[0]-1);
        w[i[1]-1][i[0]-1] = w[i[0]-1][i[1]-1] = i[2];
    }
    vector<ll> parent(n), height(n);
    parent[0] = -1;
    buildTree(adjList, 0, -1, 0, parent, height);
    
    vector<int> res;
    for(auto i:B){
        res.push_back(helper(adjList, w, i[0]-1, i[1]-1, parent, height));
    }
    return res;
}

// Attempt 1 (DP, binary lifting concept, MLE):

typedef long long ll;

void buildTree(vector<vector<ll>> & adjList, ll root, ll par, ll ht, vector<ll> & parent, vector<ll> & height){
    parent[root] = par;
    height[root] = ht;
    for(auto nbr:adjList[root]){
        if(nbr == par) continue;
        buildTree(adjList, nbr, root, ht+1, parent, height);
    }
}

ll helper(vector<vector<ll>> & adjList, vector<unordered_map<ll, ll>> & w, ll u, ll v, vector<ll> & parent, vector<ll> & height, vector<unordered_map<ll, ll>> & dp){
    if(u == v) return 0;
    if(dp[u].count(v)) return dp[u][v];
    ll res;
    if(height[u] < height[v]){
        res = max(w[v][parent[v]], helper(adjList, w, u, parent[v], parent, height, dp));
    } else {
        res = max(w[u][parent[u]], helper(adjList, w, parent[u], v, parent, height, dp));
    }
    return dp[u][v] = dp[v][u] = res;
}

vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    ll n = A.size()+1;
    vector<vector<ll>> adjList(n);
    vector<unordered_map<ll, ll>> w(n);
    for(auto i:A){
        adjList[i[0]-1].push_back(i[1]-1);
        adjList[i[1]-1].push_back(i[0]-1);
        w[i[1]-1][i[0]-1] = w[i[0]-1][i[1]-1] = i[2];
    }
    vector<ll> parent(n), height(n);
    parent[0] = -1;
    buildTree(adjList, 0, -1, 0, parent, height);
    
    vector<unordered_map<ll, ll>> dp(n);
    vector<int> res;
    for(auto i:B){
        res.push_back(helper(adjList, w, i[0]-1, i[1]-1, parent, height, dp));
    }
    return res;
}
