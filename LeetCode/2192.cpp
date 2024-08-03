// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

// Method 1 (Topological Sort, O(V + E*V*log(V)) time, O(V2 + E) space):

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> parents(n), children(n);
        vector<int> inDegree(n);
        for(auto edge:edges){
            parents[edge[1]].push_back(edge[0]);
            children[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<set<int>> ancestors(n);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto child:children[cur]){
                inDegree[child]--;
                if(inDegree[child] == 0){
                    q.push(child);
                }
            }

            for(auto parent:parents[cur]){
                ancestors[cur].insert(parent);
                for(auto ancestor:ancestors[parent]){
                    ancestors[cur].insert(ancestor);
                }
            }
        }

        vector<vector<int>> res(n);
        for(int i=0; i<n; i++){
            res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return res;
    }
};
