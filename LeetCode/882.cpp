// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/

// Method 1 (Modified Dijkstra's Algorithm, O(Elog(V)) = O(n2log(n))):

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // w = weight = subnodes+1; w[i][j] == 0 means no edge
        // uv = unvisited subnodes in edge
        vector<vector<int>> w(n, vector<int>(n, 0)), uv(n, vector<int>(n, 0)), adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            w[e[0]][e[1]] = w[e[1]][e[0]] = e[2]+1;
            uv[e[0]][e[1]] = uv[e[1]][e[0]] = e[2];
        }
        int ans = 0;
        vector<int> d(n, INT_MAX);
        // {cumulative sum, cur, remaining moves}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        d[0] = 0;
        pq.push({d[0], 0, maxMoves});
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int cur = v[1];
            int cost = v[0];
            int rm = v[2];
            if(cost > d[cur]) continue;
            // cout<<"NewNode: "<<cur<<", Cost: "<<cost<<", Moves: "<<rm<<endl;
            ans++;
            for(auto nbr:adj[cur]){
                int new_subnodes_visited = min(rm, uv[cur][nbr]);
                // cout<<"Nbr: "<<nbr<<", w: "<<w[cur][nbr]<<", uv: "<<uv[cur][nbr]<<", new visited: "<<new_subnodes_visited<<" "<<endl;
                ans += new_subnodes_visited;
                uv[cur][nbr] = uv[nbr][cur] = uv[cur][nbr]-new_subnodes_visited;
                int next_cost = cost+w[cur][nbr];
                if(next_cost < d[nbr] and rm >= w[cur][nbr]){
                    d[nbr] = next_cost;
                    pq.push({d[nbr], nbr, rm-w[cur][nbr]});
                }
            }
        }
        return ans;
    }
};