// https://leetcode.com/problems/find-if-path-exists-in-graph/

// Method 1 (DFS):

class Solution {
    bool dfs(const vector<vector<int>> & adj, int cur, const int dest, vector<bool> & visited){
        if(cur == dest){
            return true;
        }
        if(visited[cur]){
            return false;
        }
        visited[cur] = true;
        for(int nbr:adj[cur]){
            if(dfs(adj, nbr, dest, visited)){
                return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto & edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, 0);
        return dfs(adj, source, destination, visited);
    }
};

// Method 2 (Union Find):

