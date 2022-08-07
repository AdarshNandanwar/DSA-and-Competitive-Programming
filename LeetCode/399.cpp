// https://leetcode.com/problems/evaluate-division/

// Method 1 (DFS, O((#vars)+equations.size())):

class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>> &graph, const string & cur, const string & dest, unordered_set<string> & visited){
        if(!graph.count(cur)) return -1.0;
        if(cur == dest) return 1.0;
        
        double ans = -1;
        visited.insert(cur);
        for(auto &node:graph[cur]){
            string nbr = node.first;
            double weight = node.second;
            if(!visited.count(nbr)){
                double res = dfs(graph, nbr, dest, visited);
                if(res != -1.0){
                    ans = weight*res;
                    break;
                }
            }
        }
        visited.erase(cur);
        return ans;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = equations.size();
        for(auto i=0; i<n; i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], ((double)1)/values[i]});
        }
        vector<double> ans;
        for(auto &q:queries){
            unordered_set<string> visited;
            double res = dfs(graph, q[0], q[1], visited);
            ans.push_back(res);
        }
        return ans;
    }
};