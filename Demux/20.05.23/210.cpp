// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses, curCrs;
        vector<int> topoSort, inDeg(n, 0);
        vector<vector<int>> edge_list(n);
        
        // TOPOLOGICAL SORT

        for(auto p:prerequisites){
            edge_list[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            curCrs = q.front();
            q.pop();
            topoSort.push_back(curCrs);
            for(auto nbr:edge_list[curCrs]){
                inDeg[nbr]--;
                if(inDeg[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        return (topoSort.size() == n)?topoSort:vector<int>();
        
    }
};