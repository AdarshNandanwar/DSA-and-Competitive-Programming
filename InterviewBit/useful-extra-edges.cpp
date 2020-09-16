// https://www.interviewbit.com/problems/useful-extra-edges/

// Method 1 (Bidirectional Dijkstra's Algo, O(edges*log(V)+E)):

vector<int> dijkstra(int & A, vector<vector<pair<int, int>>> & adjList, int C, int D){
    vector<int> d(A, 1e8);
    // {cumCost, dest}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    d[C-1] = 0;
    pq.push({0, C-1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curCost = cur.first, src = cur.second;
        if(d[src] < curCost) continue;
        
        for(auto nbr:adjList[src]){
            int cost = nbr.first, dest = nbr.second;
            if(d[dest] > curCost+cost){
                d[dest] = curCost+cost;
                pq.push({d[dest], dest});
            }
        }
    }
    return d;
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    // {cost, dest}
    vector<vector<pair<int, int>>> adjList(A), extra(A);
    for(auto e:B){
        adjList[e[0]-1].push_back({e[2], e[1]-1});
        adjList[e[1]-1].push_back({e[2], e[0]-1});
    } 
    
    vector<int> d_fwd, d_rev;
    d_fwd = dijkstra(A, adjList, C, D);
    d_rev = dijkstra(A, adjList, D, C);
    
    int res = d_fwd[D-1];
    for(auto e:E){
        int es = e[0]-1, ed = e[1]-1, ew = e[2];
        res = min(res, min(d_fwd[es]+ew+d_rev[ed], d_fwd[ed]+ew+d_rev[es]));
    }
    return res == 1e8 ? -1 : res;
}

// Method 2 (Dijkstra's Algo E times, O(E*edges*log(V))):

int dijkstra(int & A, vector<vector<pair<int, int>>> & adjList, int C, int D, vector<int> & extra){
    vector<int> d(A, INT_MAX);
    // {cumCost, dest}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    d[C-1] = 0;
    pq.push({0, C-1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curCost = cur.first, src = cur.second;
        if(d[src] < curCost) continue;
        
        for(auto nbr:adjList[src]){
            int cost = nbr.first, dest = nbr.second;
            if(d[dest] > curCost+cost){
                d[dest] = curCost+cost;
                pq.push({d[dest], dest});
            }
        }
        if(extra[0]-1 == src or extra[1]-1 == src){
            int cost = extra[2], dest = (extra[0]-1 == src ? extra[1]-1 : extra[0]-1);
            if(d[dest] > curCost+cost){
                d[dest] = curCost+cost;
                pq.push({d[dest], dest});
            }
        }
    }
    return d[D-1];
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    // {cost, dest}
    vector<vector<pair<int, int>>> adjList(A), extra(A);
    for(auto e:B){
        adjList[e[0]-1].push_back({e[2], e[1]-1});
        adjList[e[1]-1].push_back({e[2], e[0]-1});
    } 
    
    int res = INT_MAX;
    for(auto e:E){
        res = min(res, dijkstra(A, adjList, C, D, e));
    }
    return res == INT_MAX ? -1 : res;
}
