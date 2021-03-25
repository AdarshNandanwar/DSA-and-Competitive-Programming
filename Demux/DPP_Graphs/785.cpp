// https://leetcode.com/problems/is-graph-bipartite/

// Method 1 (BFS):

class Solution {
public:
    
    int bfs(int & N, vector<vector<int>>& adjList, int i, bool c, unordered_map<int, bool> & color){
        queue<int> q;
        color[i] = c;
        q.push(i);
        int cur, sz;
        while(!q.empty()){
            c = !c;
            sz = q.size();
            while(sz--){
                cur = q.front();
                q.pop();
                for(auto nbr:adjList[cur]){
                    if(!color.count(nbr)){
                        color[nbr] = c;
                        q.push(nbr);                        
                    } else {
                        if(color[nbr] != c) return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        unordered_map<int, bool> color;
        for(int i=0; i<N; i++) if(!color.count(i) and !bfs(N, graph, i, 0, color)) return false;
        return true;
    }
};