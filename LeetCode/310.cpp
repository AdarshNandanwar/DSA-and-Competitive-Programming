// https://leetcode.com/problems/minimum-height-trees/

// Method 1 (Modified topological sort for undirected acyclic graph, O(n)):

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int remaining = n, maxVal = 0;
        vector<int> deg(n, 0), maxHeight(n, 0), visited(n, 0);
        vector<vector<int>> nbrs(n, vector<int>(0));
        for(auto &e:edges){
            nbrs[e[0]].push_back(e[1]);
            nbrs[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(deg[i] == 1){
                q.push(i);
                deg[i]--;
                maxHeight[i] = 0;
                visited[i] = 1;
            }
        }
        while(1){
            int sz = q.size();
            if(sz == 0) break;
            while(sz--){
                auto cur = q.front();
                q.pop();
                visited[cur] = 1;
                for(auto &nbr:nbrs[cur]){
                    deg[nbr]--;
                    if(visited[nbr] == 0 and deg[nbr] > 0){
                        maxHeight[nbr] = max(maxHeight[nbr], 1+maxHeight[cur]);
                        maxVal = max(maxVal, maxHeight[nbr]);
                    }
                    if(deg[nbr] == 1){
                        q.push(nbr);
                    }
                }
            }
        }
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(maxHeight[i] == maxVal) res.push_back(i);
        }
        return res;
    }
};