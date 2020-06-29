// https://leetcode.com/problems/course-schedule/

// Method 1 (Queue):

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i, curCrs, curInDeg, cnt = 0, n = numCourses;
        
        // TOPOLOGICAL SORT
        
        vector<vector<int>> edge_list(n);
        vector<int> inDeg(n, 0);
        
        for(auto p:prerequisites){
            edge_list[p[1]].push_back(p[0]);
            inDeg[p[0]]++;    
        }
        
        queue<int> Q;  // nodes with inDeg == 0
        
        for(i = 0; i<n; i++){
            if(inDeg[i] == 0)
                Q.push(i);
        }
        
        while(!Q.empty()){
            curCrs = Q.front();
            Q.pop();
            cnt++;
            for(auto nbr:edge_list[curCrs]){
                inDeg[nbr]--;
                if(inDeg[nbr] == 0)
                    Q.push(nbr);
            }
        }
        
        return cnt == n;
    }
};

// Method 2 (Priority Queue) (Lots of redundancy here):

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i,curCrs, curInDeg, cnt = 0, n = numCourses;
        
        vector<vector<int>> edge_list(n);
        vector<int> inDeg(n, 0);
        vector<bool> visited(n, false);
        
        for(auto p:prerequisites){
            edge_list[p[1]].push_back(p[0]);
            inDeg[p[0]]++;    
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;  // {inDeg, node}
        
        for(i = 0; i<n; i++){
            Q.push({inDeg[i], i});
        }
        
        while(!Q.empty()){
            
            if(cnt == n) break;
            
            curCrs = Q.top().second;
            curInDeg = Q.top().first;
            Q.pop();
            
            if(curInDeg) return false;
            
            if(visited[curCrs]) continue;
            
            cnt++;
            
            for(auto nbr:edge_list[curCrs]){
                inDeg[nbr]--;
                Q.push({inDeg[nbr], nbr});
            }
            
        }
        
        return true;
        
    }
};