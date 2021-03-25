// https://leetcode.com/problems/possible-bipartition/

// Method 1 (BFS):

class Solution {
public:
    
    int bfs(int & N, unordered_map<int, vector<int>>& adjList, int i, bool c, unordered_map<int, bool> & color){
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
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList(N);
        unordered_map<int, bool> color;
        for(auto d:dislikes){
            adjList[d[0]-1].push_back(d[1]-1);
            adjList[d[1]-1].push_back(d[0]-1);
        }
        for(auto [i, j]:adjList) if(!color.count(i) and !bfs(N, adjList, i, 0, color)) return false;
        return true;
    }
};

// Method 2 (DFS):

class Solution {
public:
    
    int dfs(int & N, unordered_map<int, vector<int>>& adjList, int i, bool c, unordered_map<int, int> & color){
        if(color.count(i)) return color[i] == c;
        color[i] = c;
        for(auto nbr:adjList[i]) if(!dfs(N, adjList, nbr, !c, color)) return false;
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList(N);
        unordered_map<int, int> color;
        for(auto d:dislikes){
            adjList[d[0]-1].push_back(d[1]-1);
            adjList[d[1]-1].push_back(d[0]-1);
        }
        for(auto [i, j]:adjList) if(!color.count(i) and !dfs(N, adjList, i, 0, color)) return false;
        return true;
    }
};