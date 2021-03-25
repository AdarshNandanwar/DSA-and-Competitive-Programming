// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    
    void helper(vector<vector<int>>& graph, int pos, int & n, vector<int> & cur, vector<bool> & visited, vector<vector<int>> & ans){
        if(pos == n-1){
            ans.push_back(cur);
            return;
        }
        for(auto i:graph[pos]){
            if(!visited[i]){
                visited[i] = true;
                cur.push_back(i);
                helper(graph, i, n, cur, visited, ans);
                cur.pop_back();
                visited[i] = false;
            } 
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cur;
        vector<bool> visited(n);
        vector<vector<int>> ans;
        visited[0] = true;
        cur.push_back(0);
        helper(graph, 0, n, cur, visited, ans);
        return ans;
    }
};