// https://leetcode.com/problems/jump-game-iv/

// Method 1 (BFS, O(n)):

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), res = 0;
        unordered_map<int, vector<int>> ind;
        // VERY IMPORTANT!
        for(int i = n-1; i>=0; i--) ind[arr[i]].push_back(i);
        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                int cur = q.front();
                q.pop();
                if(cur == n-1) return res;
                if(cur-1>=0 and !visited[cur-1]){
                    q.push(cur-1);
                    visited[cur-1] = 1;
                }
                if(cur+1<n and !visited[cur+1]){
                    q.push(cur+1);
                    visited[cur+1] = 1;
                } 
                for(auto j:ind[arr[cur]]){
                    if(j == cur or visited[j]) continue;
                    q.push(j);
                    visited[j] = 1;
                }
                // VERY IMPORTANT!
                ind[arr[cur]].clear();  
            }
            res++;
        }
        return -1;
    }
};