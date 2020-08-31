// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

// Method 1 (Dijkstra's Algorithm, O(ElogV)):

vector<int> dir = {0, -1, 0, 1, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        d[0][0] = 0;
        while(!pq.empty()){
            int sz = pq.size();
            while(sz--){
                auto cur = pq.top();
                int curC = cur.first;
                pq.pop();
                if(cur.second.first == n-1 and cur.second.second == m-1) return curC;
                if(cur.second.first != 0 and cur.second.second != 0 and d[cur.second.first][cur.second.second] < cur.first) continue;
                for(int x = 0; x<4; x++){
                    int i = cur.second.first+dir[x], j = cur.second.second+dir[x+1];
                    if(i<0 or i>=n or j<0 or j>=m) continue;
                    int c = grid[cur.second.first][cur.second.second];
                    bool isSame = (x==0 and c==2) or (x==1 and c==4) or (x==2 and c==1) or (x==3 and c==3);
                    if(d[i][j] > (!isSame)+curC){
                        d[i][j] = (!isSame)+curC;
                        pq.push({(!isSame)+curC, {i, j}});
                    }
                }
            }
        }
        return n+m-2;
    }
};