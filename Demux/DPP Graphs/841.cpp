// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), count = 1;
        // BFS
        queue<int> q;
        vector<bool> visited(n);
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto r:rooms[cur]){
                if(!visited[r]){
                    q.push(r);
                    visited[r] = true;
                    count++;
                }
            }
        }
        return count == n;
    }
};