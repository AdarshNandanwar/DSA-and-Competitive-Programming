// https://leetcode.com/problems/critical-connections-in-a-network/

// Method 1 (DFS, Modified Tarjan's Algo, O(E+V)):

class Solution {
public:
    void dfs(vector<vector<int>> & adjList, int cur, int curLevel, vector<int> & level, vector<int> & low, int parent, vector<vector<int>> & ans){
        
        level[cur] = low[cur] = curLevel;     // visited is also set here
        for(auto nbr:adjList[cur]){
            if(parent == nbr) continue;
            if(level[nbr] == INT_MAX){       // not visited
                
                dfs(adjList, nbr, curLevel+1, level, low, cur, ans);
                
                if(level[cur] < low[nbr]){
                    // cut edge
                    ans.push_back({cur, nbr});
                }
            } 
            low[cur] = min(low[cur], low[nbr]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n), ans;
        for(auto c:connections){
            adjList[c[0]].push_back(c[1]);
            adjList[c[1]].push_back(c[0]);
        }
        vector<int> level(n, INT_MAX), low(n, INT_MAX);
        dfs(adjList, 0, 0, level, low, -1, ans);
        return ans;        
    }
};