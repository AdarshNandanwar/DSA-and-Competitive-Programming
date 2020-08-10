// https://leetcode.com/problems/flower-planting-with-no-adjacent/

// Method 1 (BFS):

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int n = N, c;
        vector<vector<int>> adjList(n);
        for(auto i:paths){
            adjList[i[0]-1].push_back(i[1]-1);
            adjList[i[1]-1].push_back(i[0]-1);
        }
        
        vector<int> color(n, 0);
        vector<bool> visited(n, 0);
        queue<int> q;
        for(int st = 0; st<n; st++){
            q.push(st);
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                // find color
                for(c = 1; c<=4; c++){
                    bool found = 0;
                    for(auto nbr:adjList[cur]){
                        if(color[nbr] == c){
                            found = 1;
                            break;
                        }
                    }
                    if(!found) break;
                }

                color[cur] = c;

                for(auto nbr:adjList[cur]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = 1;
                    }
                }
            }
        }
        return color;
    }
};