// https://leetcode.com/problems/min-cost-to-connect-all-points/

// Method 1 (Union Find with rank and path compression, O(ElogV) or O(n2logn)):

class Solution {
    int root(int x, vector<int> & id){
        if(x == id[x]){
            return x;
        }
        return id[x] = root(id[x], id);
    }
    void merge(int r1, int r2, vector<int> & id, vector<int> & sz){
        if(sz[r1] < sz[r2]){
            swap(r1, r2);
        }
        id[r2] = r1;
        sz[r1] += sz[r2];
    }
public:    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int weight = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back(make_pair(weight, make_pair(i, j)));
            }
        }
        // Union Find with rank and path compression
        sort(edges.begin(), edges.end());
        vector<int> id(n), sz(n, 1);
        for(int i=0; i<n; i++){
            id[i] = i;
        }
        int components = n;
        int cost=0;
        for(auto & edge:edges){
            int weight = edge.first;
            int r1 = root(edge.second.first, id);
            int r2 = root(edge.second.second, id);
            if(r1 == r2){
                continue;
            }
            merge(r1, r2, id, sz);
            components--;
            cost += weight;
            if(components == 1){
                break;
            }
        }
        return cost;
    }
};

// Method 2 (Prim's Algorithm with "unvisited" optimization, O(n2logn)):

class Solution {
public:    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // {weight, dest}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        // Prim's Algorithm
        unordered_set<int> unvisited;
        for(int i=0; i<n; i++){
            unvisited.insert(i);
        }
        int cost = 0;
        while(unvisited.size()){
            auto cur = pq.top();
            pq.pop();
            int dest = cur.second;
            if(!unvisited.count(dest)){
                continue;
            }
            cost += cur.first;
            unvisited.erase(dest);
            for(int nbr:unvisited){
                if(!unvisited.count(nbr)){
                    continue;
                }
                int weight = abs(points[nbr][0]-points[dest][0]) + abs(points[nbr][1]-points[dest][1]);
                pq.push(make_pair(weight, nbr));
            }
        }
        return cost;
    }
};

// Method 2 (Prim's Algorithm, O(n2logn)):

class Solution {
public:    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // {weight, dest}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        // Prim's Algorithm
        unordered_set<int> visited;
        int cost = 0;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int dest = cur.second;
            if(visited.count(dest)){
                continue;
            }
            cost += cur.first;
            visited.insert(dest);
            for(int nbr=0; nbr<n; nbr++){
                if(visited.count(nbr)){
                    continue;
                }
                int weight = abs(points[nbr][0]-points[dest][0]) + abs(points[nbr][1]-points[dest][1]);
                pq.push(make_pair(weight, nbr));
            }
            if(visited.size() == n){
                break;
            }
        }
        return cost;
    }
};