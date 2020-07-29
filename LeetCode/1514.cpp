// https://leetcode.com/problems/path-with-maximum-probability/

double dfs(vector<vector<pair<int, double>>> & adjList, int cur, int & end, vector<bool> & visited){
    if(cur == end) return 1;
    double res = 0;
    for(auto nbr:adjList[cur]){
        if(visited[nbr.first]) continue;
        visited[nbr.first] = 1;
        res = max(res, (double)(nbr.second*dfs(adjList, nbr.first, end, visited)));
        visited[nbr.first] = 0;
    }
    return res;
}


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adjList(n);
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<bool> visited(n, 0);
        
        return dfs(adjList, start, end, visited);
    }
};