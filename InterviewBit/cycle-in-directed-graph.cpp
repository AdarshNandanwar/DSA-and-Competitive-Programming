// https://www.interviewbit.com/problems/cycle-in-directed-graph/

// Method 1 (Topological Sort, O(E+V)):

vector<int> topoSort(vector<vector<int>> & adj){
    int n = adj.size();
    vector<int> tp;
    vector<int> inDeg(n, 0);
    for(auto i:adj) for(auto nbr:i) inDeg[nbr]++;
    queue<int> q;
    for(int i = 0; i<n; i++) if(inDeg[i] == 0) q.push(i);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        tp.push_back(cur);
        for(auto nbr:adj[cur]){
            inDeg[nbr]--;
            if(inDeg[nbr] == 0) q.push(nbr);
        }
    }
    return tp;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A);
    for(int i = 0; i<B.size(); i++) adj[B[i][0]-1].push_back(B[i][1]-1);
    // topological sort
    return topoSort(adj).size() < A;
}

// Method 2 (DFS, O(E+V)):

bool dfs(vector<vector<int>> & adj, int cur, vector<bool> & track, vector<bool> & visited){
    if(track[cur]) return 1;
    if(visited[cur]) return 0;
    visited[cur] = track[cur] = 1;
    bool res = 0;
    for(auto nbr:adj[cur]){
        res = res or dfs(adj, nbr, track, visited);
    }
    track[cur] = 0;
    return res;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A);
    for(int i = 0; i<B.size(); i++) adj[B[i][0]-1].push_back(B[i][1]-1);
    
    // dfs
    vector<bool> visited(A, 0), track(A, 0);
    stack<int> s;
    for(int st = 0; st<A; st++){
        if(!visited[st] and dfs(adj, st, track, visited)) return 1;
    }
    return 0;
}

// Method 3 (Multiple DFS, O(V*(E+V))):

bool dfs(vector<vector<int>> & adj, int cur, vector<bool> & visited){
    if(visited[cur]) return 1;
    visited[cur] = 1;
    bool res = 0;
    for(auto nbr:adj[cur]){
        res = res or dfs(adj, nbr, visited);
    }
    visited[cur] = 0;
    return res;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A);
    for(int i = 0; i<B.size(); i++) adj[B[i][0]-1].push_back(B[i][1]-1);
    
    // dfs
    vector<bool> visited(A, 0);
    stack<int> s;
    for(int st = 0; st<A; st++){
        if(dfs(adj, st, visited)) return 1;
    }
    return 0;
}
