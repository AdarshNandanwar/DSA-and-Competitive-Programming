// https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        vector<int> res(n, -1);
        unordered_map<string, int> visited; 
        queue<int> q;
        int color, dist;        
        string key;
        
        // 0: red, 1: blue
        
        vector<vector<vector<int>>> edge_list(2, vector<vector<int>>(n));
        for(auto e:red_edges){
            int i = e[0], j = e[1];
            edge_list[0][i].push_back(j);
        }
        for(auto e:blue_edges){
            int i = e[0], j = e[1];
            edge_list[1][i].push_back(j);
        }
        
        
        // red start
        
        q = {};
        visited.clear();

        q.push(0);
        color = 0;
        dist = 0;        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                
                int curr = q.front();
                q.pop();
                
                for(auto nbr:edge_list[color][curr]){
                    key = to_string(color)+","+to_string(curr)+","+to_string(nbr);
                    if(!visited[key])   q.push(nbr);
                    visited[key] = 1;
                }
                
                if(res[curr] == -1)
                    res[curr] = dist;
                else
                    res[curr] = min(res[curr], dist);
            }
            color ^= 1;
            dist++;
        }
        
                
        // blue start
        
        q = {};
        visited.clear();
        
        q.push(0);
        color = 1;
        dist = 0;        
        while(!q.empty()){
            int sz = q.size();            
            for(int i = 0; i<sz; i++){
                
                int curr = q.front();
                q.pop();
                
                for(auto nbr:edge_list[color][curr]){
                    key = to_string(color)+","+to_string(curr)+","+to_string(nbr);
                    if(!visited[key])   q.push(nbr);
                    visited[key] = 1;
                }
                
                if(res[curr] == -1)
                    res[curr] = dist;
                else
                    res[curr] = min(res[curr], dist);
            }
            color ^= 1;
            dist++;
        }
        
        return res;
    }
};