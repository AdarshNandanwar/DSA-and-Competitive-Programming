// https://leetcode.com/problems/is-graph-bipartite/

// Method 1 (BFS, O(E+V)):

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> visited(n, -1);
        for(int i=0; i<n; i++){
            if(visited[i] != -1){
                continue;
            }
            q.push(i);
            visited[i] = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                bool color = visited[cur];
                bool nbrColor = color^1;
                for(int &nbr:graph[cur]){
                    if(visited[nbr] == -1){
                        q.push(nbr);
                        visited[nbr] = nbrColor;
                    } else if(visited[nbr] != nbrColor){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// Alternate Code:

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] != -1){
                continue;
            }
            queue<int> q;
            int curColor = 0;
            q.push(i);
            color[i] = curColor;
            while(!q.empty()){
                int sz = q.size();
                for(int j = 0; j<sz; j++){
                    int cur = q.front();
                    q.pop();
                    for(auto &nbr:graph[cur]){
                        if(color[nbr] == -1){
                            color[nbr] = (curColor^1);
                            q.push(nbr);
                        }
                    }
                }
                curColor ^= 1;
            }
        }
        for(int i=0; i<n; i++){
            for(auto &nbr:graph[i]){
                if(color[i] == color[nbr]){
                    return false;
                }
            }
        }
        return true;
    }
};