// https://leetcode.com/problems/find-eventual-safe-states/

// Method 1 (Topological Sort, O(VlogV + E)):

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n);
        for(int i=0; i<n; i++){
            outDegree[i] = graph[i].size();
            for(int dest:graph[i]){
                reverseGraph[dest].push_back(i);
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(outDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safe;
        while(!q.empty()){
            int cur = q.front();
            safe.push_back(cur);
            q.pop();
            for(int nbr:reverseGraph[cur]){
                outDegree[nbr]--;
                if(outDegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};
